/*
 * Logger.cpp
 *
 *  Created on: 2013/4/1
 *      Author: SUCHEN
 */

#include "Logger.h"

#include <sstream>
using namespace std;

#include "ZzOGRE.h"

namespace zzogre {

Logger _Logger;

Logger::Logger() {
}

Logger::~Logger() {
}

void Logger::logi(const char* file, int line, const std::string& str) {
	stringstream ss;
	ss << file << '(' << line << "): " << str;

	Ogre::LogManager::getSingletonPtr()->logMessage(ss.str(), Ogre::LML_NORMAL);
}

void Logger::logi(const char* file, int line, boost::format& fmt) {
	stringstream ss;
	ss << file << '(' << line << "): " << fmt.str();

	Ogre::LogManager::getSingletonPtr()->logMessage(ss.str(), Ogre::LML_NORMAL);
}

void Logger::logd(const char* file, int line, const std::string& str) {
	stringstream ss;
	ss << file << '(' << line << "): " << str;

	Ogre::LogManager::getSingletonPtr()->logMessage(ss.str(), Ogre::LML_CRITICAL);
}

void Logger::logd(const char* file, int line, boost::format& fmt) {
	stringstream ss;
	ss << file << '(' << line << "): " << fmt.str();

	Ogre::LogManager::getSingletonPtr()->logMessage(ss.str(), Ogre::LML_CRITICAL);
}
} /* namespace zzogre */
