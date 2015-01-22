#pragma once

#include <string>
#include <map>

using namespace std;

class  ConstStringManager
{
public:
	int Initialize();
	int UnInitialize();
	const string& operator[](const string& strKey);
	int	GetRegistryStringSize();

private:
	typedef std::map<string, string> StringRegistryMap;
	StringRegistryMap m_RegistryStringMap;
};

extern ConstStringManager g_ConstStringManager;
