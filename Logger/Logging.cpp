#include "Logging.h"
#include "../ScriptHookV/natives.h"
#include "../UI.h"
#include <string>
#define CHECK_NULL(fName) do{WAIT(0); } while(fName==nullptr); 
Logger* Logger::sm_Instance = new Logger(); 
Logger& Logger::GetInstance()
{
	return *sm_Instance;
}
Logger::Logger()
{
	Init();
}
Logger::~Logger()
{
}

void Logger::Init()
{
	m_LogFile = fopen(__logName__, "w");
	m_LogFile = freopen(__logName__, "a",m_LogFile);
}
void Logger::InfoLog(std::string loggerInfo)
{
	UI_DrawNotificationF(1.f);
	Log(LG_INFO, loggerInfo);
	return;
}

void Logger::Log(LogSeverity importance, std::string loggedInfo)
{	
	if (m_LogFile == nullptr) {
		Init();
		Log(importance, loggedInfo);
		return;
	}
	fprintf(m_LogFile, (GetEnumString(importance) + loggedInfo).c_str());
	fprintf(m_LogFile, "\n");
	fflush(m_LogFile);
	return;
	
}

//void Logger::FileClose() {
//	if (m_LogFile == nullptr) {
//		return;
//	}
//	fclose(m_LogFile);
//	return;
//}
//
//void Logger::FileOpen() {
//	if (m_LogFile == nullptr) {
//		m_LogFile = fopen(__logName__, "w");
//	} else {
//		m_LogFile = freopen(__logName__ , "a", m_LogFile);
//	}
//}

std::string Logger::GetEnumString(LogSeverity s)
{
	switch (s) {
	case LogSeverity::LG_CRASH:
		return std::string("[CRASH]: ");
	case LogSeverity::LG_ERROR:
		return std::string("[ERROR]: ");
	case LogSeverity::LG_FATAL:
		return std::string("[FATAL]: ");
	case LogSeverity::LG_INFO:
		return std::string("[INFO]: ");
	}
	return std::string("[YOU REALLY FUCKED IT NOW]: ");
}
