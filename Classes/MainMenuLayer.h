//
//  MainMenuLayer.h
//  MyGame
//
//  Created by zzl09 on 14-5-9.
//  Copyright 2014年 zzl09. All rights reserved.
//

#import "cocos2d.h"
#include "cocos-ext.h"

class MainMenuLayer : public cocos2d::Layer {
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(MainMenuLayer);

private:
    cocos2d::extension::ControlButton* buildTestButton();
};
