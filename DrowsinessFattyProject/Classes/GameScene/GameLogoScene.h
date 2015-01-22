#pragma once

#include "cocos2d.h"

class GameLogoScene : public cocos2d::Layer
{
public:
	GameLogoScene();
	~GameLogoScene();
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // implement the "static create()" method manually
	CREATE_FUNC(GameLogoScene);
	
	//Delay Exe Func
	void ChangeScene(float fParam);

	void PreLoadBackgroundSound();
	void PlayBackgroundSound();
	void StopPlayBackgroundSound();

private:
	float	m_fChangeSceneDelay;
	float	m_fChangeSceneLast;
};

