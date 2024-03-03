#pragma once
#include <stdio.h>
#define BIT(x) 1<<x
class FileHandler {
public:
	enum FileMode {
		FM_APPEND = BIT(0),
		FM_READ = BIT(1),
		FM_WRITE = BIT(2),
	};
	FileHandler(const char* fileName);
	void Open();
	static void OpenNewFile(const char* fileName);
	void Close();
	void Flush();
	void FetchToBuffer(const char* buf);
	void SetNewWriteMethod(const char* buffer);
	/*
	* Should Open in Write mode to clear then close then open in append.
	*/
	void ClearFile();

protected:
	FILE** GetFile();
	void SetNewFile(FILE* _f_);
	const char* extractFileExtention(const char* fileName);
private:
	const char* fileWriter;
	FILE* m_MemFile;
};