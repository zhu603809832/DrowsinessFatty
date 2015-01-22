#pragma once

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "cocos-ext.h"
#include "ui/CocosGUI.h"

#define GAMEBEGIN_UI_JSON_FILE "GameBegin.json"

class GameBeginUI: public cocos2d::Layer
{
public:
    GameBeginUI();
    ~GameBeginUI();
    
	virtual bool init();

	void TouchEventCallBack(cocos2d::Ref* pSender, cocos2d::ui::TouchEventType Type);

	CREATE_FUNC(GameBeginUI);
};
