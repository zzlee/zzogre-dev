/*
 * Logger.h
 *
 *  Created on: 2013/4/1
 *      Author: SUCHEN
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#include <string>
#include <boost/format.hpp>

#include <OgreLogManager.h>

namespace zzogre {

#ifndef LOGI
#define LOGI(x) _Logger.logi(__FILE__, __LINE__, x)
#endif

#ifndef LOGD
#define LOGD(x) _Logger.logd(__FILE__, __LINE__, x)
#endif

class Logger {
public:
	Logger();
	virtual ~Logger();

	void logi(const char* file, int line, const std::string& str);
	void logi(const char* file, int line, boost::format& fmt);

	void logd(const char* file, int line, const std::string& str);
	void logd(const char* file, int line, boost::format& fmt);
};
extern Logger _Logger;

} /* namespace zzogre */
#endif /* LOGGER_H_ */
