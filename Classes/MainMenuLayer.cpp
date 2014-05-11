//
//  MainMenuLayer.m
//  MyGame
//
//  Created by zzl09 on 14-5-9.
//  Copyright 2014年 zzl09. All rights reserved.
//

#import "MainMenuLayer.h"
USING_NS_CC;
USING_NS_CC_EXT;

// on "init" you need to initialize your instance
bool MainMenuLayer::init()
{
    if (!Layer::init()) {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    CCLog("width:%f,height:%f", visibleSize.width, visibleSize.height);
    CCLog("pointX:%f,pointY:%f", origin.x, origin.y);
    this->addChild(buildTestButton());
    return true;
}

ControlButton* MainMenuLayer::buildTestButton()
{
    /* 正常状态下的按钮图片 */
    Scale9Sprite* btnNormal = Scale9Sprite::create("CloseNormal.png");

    /* 点击状态下的按钮图片 */
    Scale9Sprite* btnDown = Scale9Sprite::create("CloseSelected.png");

    /* 按钮标题 */
    CCLabelTTF* title = CCLabelTTF::create("Touch4234", "Marker Felt", 30);

    /* 按钮的大小会根据标题自动调整 */
    ControlButton* controlBtn = ControlButton::create(title, btnNormal);
    controlBtn->setPreferredSize(CCSize(300, 50));
    /* 设置按钮按下时的图片 */
    controlBtn->setBackgroundSpriteForState(btnDown, Control::State::HIGH_LIGHTED);
    controlBtn->setPosition(ccp(200, 200));
    return controlBtn;
}

void MainMenuLayer::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
