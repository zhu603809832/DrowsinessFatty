#pragma once

#include "cocos2d.h"

class GameBeginScene : public cocos2d::Layer
{
public:
	GameBeginScene();
	~GameBeginScene();
	static cocos2d::Scene * createScene();

	virtual bool init();
	//implement the "static create()" method
	CREATE_FUNC(GameBeginScene);
};

