#pragma once
#include "./FileHandling.h"
#include <vector>
class XMLProperty{
public:
	XMLProperty(const char* lineToParse);
	
private:

};
class _XML_Tag_ {
public:
	_XML_Tag_(const char* lineToParse);
	void Parse(const char* line);

private:
	std::vector<XMLProperty>* m_Property;
};
class XMLFile : public FileHandler{
public:
	XMLFile(FILE* f);
	static FILE* f_Create(const char* bufferName);
	
private:

};