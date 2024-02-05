#include "Logging.h"
#include "../UI.h"
#include <string>
Logger Logger::sm_Instance = Logger(); 
Logger& Logger::GetInstance()
{
	UI_DrawNotificationSTR("GetInst Called");
	UI_DrawNotificationI(reinterpret_cast<int>( & sm_Instance));
	return sm_Instance;
}
Logger::Logger() :
	m_LogFile(std::ofstream(__logName__, std::ios::in | std::ios::out | std::ios::app))
{
	UI_DrawNotificationSTR("Constructor Called");
	
	Init();
}

Logger::~Logger()
{
}

void Logger::Init()
{

	//try {
	//	m_LogFile.open(__logName__);
	//	if (!m_LogFile.is_open()) {
	//		throw std::exception();
	//	}
	//	m_LogFile.clear();
	//}
	//catch (std::exception()) {
	//	std::string s = "~r~" + std::string(__logName__) + ": Failed To Load!";
	//	UI_DrawNotificationSTR(const_cast<char*>(s.c_str()));
	//}

}

void Logger::InfoLog(std::string loggerInfo)
{
	
	UI_DrawNotificationSTR("Log Attempted Open");
	m_LogFile.open(__logName__ ,std::ios::out | std::ios::in | std::ios::app); //crashes here

	if (m_LogFile.is_open()) {
		m_LogFile << GetEnumString(LogSeverity::LG_INFO) << loggerInfo;
		m_LogFile.close();
	}
	else {
		
		return;
	}
	
}

void Logger::Log(LogSeverity importance, std::string loggedInfo)
{	
	m_LogFile.open(__logName__);
	if (!m_LogFile.is_open()) {
		return;
	}
	m_LogFile << GetEnumString(importance) << loggedInfo;
	
	m_LogFile.close();
}

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
