//============================================================================
// Name        : Player.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

#include <Objbase.h>

#include <OgreException.h>
#include <OgreResourceBackgroundQueue.h>
#include <OgreSceneNode.h>
using namespace Ogre;

#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/filesystem.hpp>
#include <boost/python.hpp>
#include <boost/format.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/locale.hpp>
#include <boost/program_options.hpp>
using namespace boost;
using namespace boost::python;
using namespace boost::filesystem;
using namespace boost::posix_time;
namespace po = boost::program_options;

#include <zzlab/ZzLab.h>
#include <zzlab/ZzCOM.h>
using namespace zzlab;

#include <zzogre/ZzOGRE.h>
#include <zzogre/Logger.h>
#include <zzogre/FrameEventManager.h>
#include <zzogre/OISRenderWindow.h>
#include <zzogre/SceneNodes.h>
#include <zzogre/RegularClockUpdater.h>
#include <zzogre/Component.h>
using namespace zzogre;

#include <rapidxml/rapidxml.hpp>
#include <rapidxml/rapidxml_utils.hpp>
using namespace rapidxml;

#include <gui3d/Gui3DDebugPanelColors.h>

void Main(int argc, char* argv[]) {
	HRESULT hr = S_OK;

	po::options_description desc("Allowed options");
	desc.add_options()("help", "produce help message")("root-config",
			po::value<string>(), "root configuration");

	po::variables_map vm;
	po::store(po::parse_command_line(argc, argv, desc), vm);
	po::notify(vm);

	if (vm.count("help")) {
		cout << desc << "\n";
		return;
	}

	path config;
	if (vm.count("root-config")) {
		config = vm["root-config"].as<string>();
	} else {
		config = "Root.xml";
	}

	path rootPath = path("Data") / config;
	LOGI(format("Parsing \"%s\"...") % rootPath.string());
	file<char> rootFile(rootPath.string().c_str());
	xml_document<char> doc;
	doc.parse<parse_default>(rootFile.data());
	XmlNode* rootNode = doc.first_node("root");
	if (!rootNode)
		HR(E_POINTER);

	// Load OGRE3D plug-ins
	for (XmlNode* plugin = rootNode->first_node("plugin"); plugin; plugin =
			plugin->next_sibling("plugin")) {
		_Root->loadPlugin(plugin->value());
	}

	// Select rendering subsystem
	XmlNode* renderSystem = rootNode->first_node("render-system");
	if (renderSystem) {
		_RenderSystem = _Root->getRenderSystemByName(renderSystem->value());
	} else {
		_RenderSystem = _Root->getRenderSystemByName(
				"Direct3D9 Rendering Subsystem");
	}
	_Root->setRenderSystem(_RenderSystem);

	// Initialize OGRE3D root
	_Root->initialise(false);

	// Cache singletons
	cacheSingletons();

	// Setup resource groups
	path assets = current_path() / path("Assets");
	path resources = assets / path("Resources");
	addResourceGroups(resources);

	// Create render window(s)
	for (XmlNode* renderWindow = rootNode->first_node("render-window");
			renderWindow;
			renderWindow = renderWindow->next_sibling("render-window")) {
		OISRenderWindowPtr window(new OISRenderWindow());

#define _PARSE0(NAME, ATTR) \
		if(strcmp(attr->name(), NAME) == 0) \
			window->ATTR = attr->value()

#define _PARSE(NAME, TYPE, ATTR) \
		if(strcmp(attr->name(), NAME) == 0) \
			window->ATTR = StringConverter::parse ## TYPE (attr->value())

		for (XmlAttribute* attr = renderWindow->first_attribute(); attr; attr =
				attr->next_attribute()) {
			_PARSE0("name", name);
			_PARSE("left", Int, left);
			_PARSE("top", Int, top);
			_PARSE("width", Int, width);
			_PARSE("height", Int, height);
			_PARSE0("title", title);
			_PARSE("use-full-screen", Bool, useFullScreen);
			_PARSE("colour-depth", Int, colourDepth);
			_PARSE("depth-buffer", Bool, depthBuffer);
			_PARSE("FSAA", Int, FSAA);
			_PARSE0("FSAAHint", FSAAHint);
			_PARSE("display-frequency", Int, displayFrequency);
			_PARSE("vsync", Bool, vsync);
			_PARSE("vsync-interval", Int, vsyncInterval);
			_PARSE0("border", border);
			_PARSE("outer-dimensions", Bool, outerDimensions);
			_PARSE("gamma", Bool, gamma);
			_PARSE("enable-double-click", Bool, enableDoubleClick);
			_PARSE("deactivate-on-focus-change", Bool, deactivateOnFocusChange);
			_PARSE("mouse-foreground", Bool, mouseForeground);
			_PARSE("mouse-exclusive", Bool, mouseExclusive);
			_PARSE("keyboard-foreground", Bool, keyboardForeground);
			_PARSE("keyboard-exclusive", Bool, keyboardExclusive);
			_PARSE("auto-capture", Bool, autoCapture);
			_PARSE("quit-on-destroy", Bool, quitOnDestroy);
		}

#undef _PARSE
#undef _PARSE0

		window->initialise();

		_Windows.push_back(window);
	}

	if (_Windows.empty())
		OGRE_EXCEPT(Ogre::Exception::ERR_RT_ASSERTION_FAILED,
				"at least one render window", __FUNCTION__);
	_Window = _Windows[0];

	// Create texture(s)
	for (XmlNode* node0 = rootNode->first_node("texture"); node0;
			node0 = node0->next_sibling("texture")) {
		XmlAttribute* name = node0->first_attribute("name");
		if (!name)
			OGRE_EXCEPT(Exception::ERR_RT_ASSERTION_FAILED,
					"texture name is missing", __FUNCTION__);

		XmlAttribute* group = node0->first_attribute("group");
		if (!group)
			OGRE_EXCEPT(Exception::ERR_RT_ASSERTION_FAILED,
					"texture group is missing", __FUNCTION__);

		TextureType texType;
		XmlAttribute* type = node0->first_attribute("type");
		if (type) {
			if (strcmp(type->value(), "1d") == 0)
				texType = TEX_TYPE_1D;
			else if (strcmp(type->value(), "2d") == 0)
				texType = TEX_TYPE_2D;
			else if (strcmp(type->value(), "3d") == 0)
				texType = TEX_TYPE_3D;
			else if (strcmp(type->value(), "cube-map") == 0)
				texType = TEX_TYPE_CUBE_MAP;
			else if (strcmp(type->value(), "2d-array") == 0)
				texType = TEX_TYPE_2D_ARRAY;
			else
				OGRE_EXCEPT(Exception::ERR_RT_ASSERTION_FAILED,
						"unknown texture type: " + string(type->value()),
						__FUNCTION__);
		} else
			texType = TEX_TYPE_2D;

		XmlAttribute* width = node0->first_attribute("width");
		if (!width)
			OGRE_EXCEPT(Exception::ERR_RT_ASSERTION_FAILED,
					"texture width is missing", __FUNCTION__);

		XmlAttribute* height = node0->first_attribute("height");
		if (!height)
			OGRE_EXCEPT(Exception::ERR_RT_ASSERTION_FAILED,
					"texture height is missing", __FUNCTION__);

		uint depth;
		XmlAttribute* attr = node0->first_attribute("depth");
		if (attr)
			depth = StringConverter::parseUnsignedInt(attr->value());
		else
			depth = 1;

		uint num_mips;
		attr = node0->first_attribute("num-mipmaps");
		if (attr)
			num_mips = StringConverter::parseInt(attr->value());
		else
			num_mips = 0;

		PixelFormat format;
		attr = node0->first_attribute("pixel-format");
		if (attr)
			format = zzogre::parsePixelFormat(attr->value());
		else
			format = PF_R8G8B8;

		int usage;
		attr = node0->first_attribute("usage");
		if (attr)
			usage = zzogre::parseFlags(attr->value());
		else
			usage = TU_DEFAULT;

		bool hwGammaCorrection;
		attr = node0->first_attribute("hw-gamma-correction");
		if (attr)
			hwGammaCorrection = StringConverter::parseBool(attr->value());
		else
			hwGammaCorrection = false;

		uint FSAA;
		attr = node0->first_attribute("FSAA");
		if (attr)
			FSAA = StringConverter::parseUnsignedInt(attr->value());
		else
			FSAA = 0;

		string FSAAHint;
		attr = node0->first_attribute("FSAAHint");
		if (attr)
			FSAAHint = attr->value();

		RenderWindowResourcesClosurePtr closure;
		attr = node0->first_attribute("zzogre-device-resource");
		if (attr)
			closure.reset(new RenderWindowResourcesClosure(attr->value()));

		_TextureManager->createManual(name->value(), group->value(), texType,
				StringConverter::parseUnsignedInt(width->value()),
				StringConverter::parseUnsignedInt(height->value()), depth,
				num_mips, format, usage, NULL, hwGammaCorrection, FSAA,
				FSAAHint);
	}

	// Initialize resource groups
	_ResourceGroupManager->initialiseAllResourceGroups();

	// Initialize gui3d
	XmlNode* gui3d = rootNode->first_node("gui3d");
	if (gui3d) {
		XmlAttribute* debug = gui3d->first_attribute("debug");
		if (debug && StringConverter::parseBool(debug->value()))
			_Gui3D = new Gui3D::Gui3D(new Gui3D::DebugPanelColors());
		else {
			Gui3D::PanelColors* colors = new Gui3D::PanelColors();
			XmlNode* panelColors = gui3d->first_node("panel-colors");
			if (panelColors) {
				XmlAttribute* name = gui3d->first_attribute("name");
				ZzOgreAssert(name, "panel colors configuration is missing");

				XmlAttribute* group = gui3d->first_attribute("group");
				zzogre::loadPanelColors(colors, name->value(),
						group ? group->value() : ResourceGroupManager::AUTODETECT_RESOURCE_GROUP_NAME);
			} else {
				zzogre::loadDefaultPanelColors(colors);
			}
			_Gui3D = new Gui3D::Gui3D(colors);
		}
	}

	// clock updater(s)
	RegularClockUpdaterPtr _regularClock;

	// Initialize clock
	XmlNode* clockNode = rootNode->first_node("clock");
	if (clockNode) {
		XmlAttribute* attr = clockNode->first_attribute("type");
		if (attr) {
			if (strcmp(attr->value(), "regular") == 0) {
				LONG numeratorValue;
				LONG denominatorValue;

				XmlAttribute* numerator = clockNode->first_attribute(
						"numerator");
				if (numerator)
					numeratorValue = StringConverter::parseInt(
							numerator->value());
				else
					numeratorValue = 1;

				XmlAttribute* denominator = clockNode->first_attribute(
						"denominator");
				if (denominator)
					denominatorValue = StringConverter::parseInt(
							denominator->value());
				else
					denominatorValue = 60;

				LOGI(
						format("Use regular clock: %d/%d") % numeratorValue
								% denominatorValue);
				_regularClock.reset(
						new RegularClockUpdater(numeratorValue,
								denominatorValue));
			} else if (strcmp(attr->value(), "network") == 0) {
				std::string hostValue;
				int portValue;
				std::string sourceTypeValue;

				XmlAttribute* host = clockNode->first_attribute("host");
				if (host)
					hostValue = host->value();
				else
					hostValue = "127.0.0.1";

				XmlAttribute* port = clockNode->first_attribute("port");
				if (port)
					portValue = StringConverter::parseInt(port->value());
				else
					portValue = 9001;

				IClockPtr sourceClock;
				XmlAttribute* sourceType = clockNode->first_attribute(
						"source-type");
				if (sourceType)
					if (strcmp(sourceType->value(), "native") == 0) {
						hr = _ZzCOM->CreateNativeClock((IClock**) &sourceClock), HR(hr);
					} else if(strcmp(sourceType->value(), "media") == 0) {
						hr = _ZzCOM->CreateMediaClock((IClock**)&sourceClock), HR(hr);
					} else if(strcmp(sourceType->value(), "hires") == 0) {
						hr = _ZzCOM->CreateHiResClock((IClock**)&sourceClock), HR(hr);
					} else {
						hr = _ZzCOM->CreateNativeClock((IClock**)&sourceClock), HR(hr);
						sourceTypeValue = "native";
					}
					else {
						hr = _ZzCOM->CreateNativeClock((IClock**)&sourceClock), HR(hr);
						sourceTypeValue = "native";
					}

				LOGI(
						format("Use network clock: %s @ %d from %s clock")
								% hostValue % portValue % sourceTypeValue);

				IClockPtr _clock;
				BSTR bstrHost =
						SysAllocString(
								locale::conv::utf_to_utf<wchar_t>(
										hostValue.c_str()).c_str());
				hr = _ZzCOM->CreateSyncClock(bstrHost, portValue,
						sourceClock.get(), (IClock **) &_clock), HR(hr);
				SysFreeString(bstrHost);
				_Clock = _clock;
			}
		}
	}

	// Register frame event manager
	_Root->addFrameListener(&_FrameEventManager);

	// Load all behaviors in Assets/
	loadAllBehaviors(assets);

	// Create scene
	XmlNode* mainScene = rootNode->first_node("main-scene");
	if (!mainScene)
		HR(E_POINTER);

	{
		XmlAttribute* name = mainScene->first_attribute("name");
		if (!name)
			HR(E_POINTER);

		XmlAttribute* group = mainScene->first_attribute("group");

		loadScene(name->value(),
				group ? group->value() : ResourceGroupManager::AUTODETECT_RESOURCE_GROUP_NAME,
				_SceneManager);
	}

	// Start rendering loop
	_Root->startRendering();

	// Disable all components
	SceneNodes::activeAllInHierarchy(_SceneManager->getRootSceneNode(), false);

	_Window.reset();
	_Windows.clear();
	_regularClock.reset();
	if (_Gui3D) {
		delete _Gui3D->getPanelColors();
		delete _Gui3D;
		_Gui3D = NULL;
	}
}

int main(int argc, char* argv[]) {
	try {
		// Create Ogre3D root
		ptime now = second_clock::local_time();
		gregorian::date nowDate = now.date();
		time_duration nowTime = now.time_of_day();
		path logsPath = path("Data") / path("logs")
				/ path(
						(format("%04d-%02d-%02d") % nowDate.year()
								% nowDate.month() % nowDate.day()).str());
		create_directories(logsPath);
		path logFile = logsPath
				/ (format("%02d-%02d-%02d.log") % nowTime.hours()
						% nowTime.minutes() % nowTime.seconds()).str();
		_Root = new Ogre::Root("", "", logFile.string());

		// Initialization
		CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
		Py_Initialize();
		zzlab::initialize();

		Main(argc, argv);

		// Uninitialize
		zzlab::uninitialize();
		Py_Finalize();
		CoUninitialize();

		delete _Root;
	} catch (const Ogre::Exception& e) {
		LOGD(
				format("An Ogre exception has occured: %s")
						% e.getFullDescription());
	} catch (const std::exception& ex) {
		LOGD(format("An std exception has occured: %s") % ex.what());
	} catch (const python::error_already_set&) {
		LOGD(handlePythonError());
	}

	return 0;
}
