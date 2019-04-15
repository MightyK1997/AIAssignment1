#pragma once
#include <string>
#include <map>
#include <vector>

class Example
{
public:
	std::string GetAttribute() { return m_Attribute; }
	std::string GetAction() { return m_Action; }
private:
	std::string m_Action;
	std::string m_Attribute;
};
