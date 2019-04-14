#pragma once
#include <string>
#include <map>

class Example
{
public:
	std::string GetValue(std::string i_Attribute) { return m_Attributes[i_Attribute]; }
	std::string GetAction() { return m_Action; }
private:
	std::string m_Action;
	std::map<std::string, std::string> m_Attributes;
};