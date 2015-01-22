#include "AppDelegate.h"
#include "CommonDefine.h"
#include "GameScene\GameLogoScene.h"
#include "Core.h"
#include "CoreLogic\ConstStringManager.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
	bool nInitRetCode = false;

	int nInitCoreEnv = g_InitCoreEnv();
	PROCESS_ERROR(nInitCoreEnv);

	int nInitCore = g_InitCore();
	PROCESS_ERROR(nInitCore);

    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLView::create(g_ConstStringManager["szGameTitleName"]);
        director->setOpenGLView(glview);
    }

    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
    //auto scene = HelloWorld::createScene();
	auto sceneGameLogo = GameLogoScene::createScene();
	director->runWithScene(sceneGameLogo);

    // run
    //director->runWithScene(scene);
	CCLog("AppDelegate Init Successfully!!");
	nInitRetCode = true;
Exit0:
    return nInitRetCode;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
