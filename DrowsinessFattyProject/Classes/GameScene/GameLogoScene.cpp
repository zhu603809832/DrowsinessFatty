#include "GameLogoScene.h"
#include "CoreLogic/ConstStringManager.h"
#include "GameBeginScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace CocosDenshion;

GameLogoScene::GameLogoScene()
{
	m_fChangeSceneLast = 0.0f;
	m_fChangeSceneDelay = 0.0f;
}

GameLogoScene::~GameLogoScene()
{

}

Scene* GameLogoScene::createScene()
{
	auto scene = Scene::create();
	auto layer = GameLogoScene::create();
	scene->addChild(layer);
	return scene;
}

bool GameLogoScene::init()
{
	bool bResult = false;
	if (!Layer::init())
	{
		return bResult;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto sprite = Sprite::create(g_ConstStringManager["szGameLogoScene"]);
	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(sprite);
	
	m_fChangeSceneDelay = 9.0f;
	m_fChangeSceneLast = 2.0f;
	scheduleOnce(schedule_selector(GameLogoScene::ChangeScene), m_fChangeSceneDelay);

	PreLoadBackgroundSound();

	PlayBackgroundSound();

	bResult = true;
	return bResult;
}

void GameLogoScene::ChangeScene(float fParam)
{
	CCTransitionScene * pTransitionScene = NULL;
	Scene* pTargetScene = GameBeginScene::createScene();
	pTransitionScene = CCTransitionCrossFade::create(m_fChangeSceneLast, pTargetScene);
	CCDirector::sharedDirector()->replaceScene(pTransitionScene);

	StopPlayBackgroundSound();
}

void GameLogoScene::PreLoadBackgroundSound()
{
	SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic(g_ConstStringManager["szGameLogoSound"].c_str());
}

void GameLogoScene::PlayBackgroundSound()
{
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic(g_ConstStringManager["szGameLogoSound"].c_str(), false);
}

void GameLogoScene::StopPlayBackgroundSound()
{
	SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
}
