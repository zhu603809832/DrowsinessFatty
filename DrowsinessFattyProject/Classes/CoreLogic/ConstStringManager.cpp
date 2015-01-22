#include "ConstStringManager.h"
#include "cocos\platform\CCFileUtils.h"
#include "GlobalDefine.h"
#include "CommonDefine.h"

USING_NS_CC;

ConstStringManager g_ConstStringManager;

int ConstStringManager::Initialize()
{
	int nRetCode = false;
	ValueMap constStringMap;
	constStringMap = FileUtils::getInstance()->getValueMapFromFile(FILE_PATH_CONST_STRING);
	PROCESS_ERROR(constStringMap.size() != 0);
	m_RegistryStringMap.clear();
	for (auto iter = constStringMap.begin(); iter !=  constStringMap.end(); ++iter)
	{
		std::string strKey = iter->first;
		auto strValue = iter->second.asString();
		m_RegistryStringMap[strKey] = strValue;
	}

	nRetCode = true;
Exit0:
	return nRetCode;
}

int ConstStringManager::UnInitialize()
{
	int nRetCode = true;
	m_RegistryStringMap.clear();
	return nRetCode;
}

const string& ConstStringManager::operator[](const string& strKey)
{
	return m_RegistryStringMap[strKey];
}

int ConstStringManager::GetRegistryStringSize()
{
	int nSize = m_RegistryStringMap.size();
	return nSize;
}