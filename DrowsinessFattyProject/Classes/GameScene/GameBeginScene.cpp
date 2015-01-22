#include "GameBeginScene.h"
#include "CoreLogic/ConstStringManager.h"
#include "GameUI/GameBeginUI.h"

USING_NS_CC;

GameBeginScene::GameBeginScene()
{
}


GameBeginScene::~GameBeginScene()
{
}

Scene * GameBeginScene::createScene()
{
	auto scene = Scene::create();

	auto layer = GameBeginScene::create();
	scene->addChild(layer);

	auto layerUI = GameBeginUI::create();
	scene->addChild(layerUI);

	return scene;
}

bool GameBeginScene::init()
{
	bool nRetCode = false;
	if (!Layer::init())
		return nRetCode;

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 originVec = Director::getInstance()->getVisibleOrigin();

	auto sprite = Sprite::create(g_ConstStringManager["szGameBeginScene"]);
	sprite->setPosition(Vec2(visibleSize.width / 2 + originVec.x, visibleSize.height / 2 + originVec.y));
	this->addChild(sprite);

	nRetCode = true;
	return nRetCode;
}
