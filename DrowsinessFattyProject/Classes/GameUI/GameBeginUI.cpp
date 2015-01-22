#include "GameBeginUI.h"

USING_NS_CC;
USING_NS_CC_EXT;

using namespace cocostudio;
using namespace ui;
using namespace cocostudio;

GameBeginUI::GameBeginUI()
{
}

GameBeginUI::~GameBeginUI()
{
    
}

bool GameBeginUI::init()
{
	bool bResult = false;
	if (!Layer::init())
	{
		return bResult;
	}

	ui::Widget* pWidgetNode = cocostudio::GUIReader::getInstance()->widgetFromJsonFile(GAMEBEGIN_UI_JSON_FILE);
	this->addChild(pWidgetNode);

	ui::Button* pButton = (ui::Button*)ui::Helper::seekWidgetByName(pWidgetNode,"GameBeginBtn");
	pButton->addTouchEventListener(this, toucheventselector(GameBeginUI::TouchEventCallBack));

	bResult = true;
	return bResult;
}

void GameBeginUI::TouchEventCallBack(cocos2d::Ref* pSend, cocos2d::ui::TouchEventType Type)
{
	switch (Type)
	{
	case ui::TouchEventType::TOUCH_EVENT_BEGAN:
		{
			log("touch begin");
			break;
		}
	case ui::TouchEventType::TOUCH_EVENT_MOVED:
		{
			log("touch move");
			break;
		}
	case ui::TouchEventType::TOUCH_EVENT_ENDED:
		{
			log("touch end");
			break;
		}
	case ui::TouchEventType::TOUCH_EVENT_CANCELED:
		{
			log("touch cancel");
			break;
		}
	default:
		break;
	}
}