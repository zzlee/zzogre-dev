/*
 * ZzLab.cpp
 *
 *  Created on: 2012/11/29
 *      Author: SUCHEN
 */

#include "ZzLab.h"

#include <limits>
#include <stdexcept>
using namespace std;

#include <boost/python.hpp>
using namespace boost;

namespace zzlab {

static RegisterInitializer::Initializer _Initializers[256];
static RegisterInitializer::Deinitializer _Deinitializers[256];
static size_t _InitializerCount = 0;

void WIN_(DWORD err, const char* file, int line) {
	if (err == ERROR_SUCCESS)
		return;

	stringstream ss;
	ss << file << '(' << line << "): Win32 error, err=" << err;
	throw runtime_error(ss.str());
}

void HR_(HRESULT err, const char* file, int line) {
	if (SUCCEEDED(err))
		return;

	stringstream ss;
	ss << file << '(' << line << "): COM error, err=0x" << hex << err;
	throw runtime_error(ss.str());
}

std::string handlePythonError() {
	string ret;

	if (PyErr_Occurred()) {
		PyObject *exc, *val, *tb;
		PyErr_Fetch(&exc, &val, &tb);

		python::object formatted_list, formatted;
		python::handle<> hexc(exc), hval(python::allow_null(val)), htb(
				python::allow_null(tb));
		python::object traceback(python::import("traceback"));
		if (!tb) {
			python::object format_exception_only(
					traceback.attr("format_exception_only"));
			formatted_list = format_exception_only(hexc, hval);
		} else {
			python::object format_exception(traceback.attr("format_exception"));
			formatted_list = format_exception(hexc, hval, htb);
		}
		formatted = python::str("\n").join(formatted_list);

		ret = python::extract<std::string>(formatted);
	}

	python::handle_exception();
	PyErr_Clear();

	return ret;
}

void initialize() {
	for(size_t i = 0;i < _InitializerCount;++i)
		_Initializers[i]();
}

void uninitialize() {
	for(size_t i = 0;i < _InitializerCount;++i)
		_Deinitializers[i]();
}

RegisterInitializer::RegisterInitializer(Initializer init, Deinitializer deinit) {
	_Initializers[_InitializerCount] = init;
	_Deinitializers[_InitializerCount] = deinit;

	++_InitializerCount;
}

} /* namespace zzlab */
