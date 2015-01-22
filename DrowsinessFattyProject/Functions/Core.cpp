#include "Core.h"
#include "../Classes/CoreLogic/ConstStringManager.h"
#include "../Base/CommonDefine.h"

int g_InitCoreEnv()
{
	int nRetCode = false;
	FileUtils::getInstance()->addSearchResolutionsOrder("SettingFiles",true);
	FileUtils::getInstance()->addSearchResolutionsOrder("GameUI",true);
	nRetCode = true;
	return nRetCode;
}
	
int g_InitCore()
{
	int nRetCode = false;
	PROCESS_ERROR(g_ConstStringManager.Initialize());
	nRetCode = true;
Exit0:
	return nRetCode;
}

int g_UnInitCore()
{
	int nRetCode = false;
	PROCESS_ERROR(g_ConstStringManager.UnInitialize());
Exit0:
	return nRetCode;
}