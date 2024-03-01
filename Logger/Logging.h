#pragma once
#include <iostream>
#include <fstream>

//#define __logName__ "E:\\SteamLibrary\\steamapps\\common\\Grand Theft Auto V\\APIMarkers.log"
#define __logName__ "APIMarkers.log"
/*Borke the mod crashes immediately because log file can't open idk ill try some more later or on monday.*/
class Logger {
public:
	enum LogSeverity {
		LG_CRASH,
		LG_FATAL,
		LG_ERROR,
		LG_INFO,
	};
	static Logger& GetInstance();
	Logger();
	~Logger();
	void Init();
	void InfoLog(std::string loggerInfo);
	void Log(LogSeverity importance, std::string loggedInfo);

private:
	std::string GetEnumString(LogSeverity s);
	static Logger* sm_Instance;
	FILE* m_LogFile;
};
#define LOGGER_INSTANCE Logger::GetInstance()