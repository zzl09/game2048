//
//  MainMenuLayer.m
//  MyGame
//
//  Created by zzl09 on 14-5-9.
//  Copyright 2014年 zzl09. All rights reserved.
//

#import "MainMenuLayer.h"

USING_NS_CC;
using namespace ui;

// on "init" you need to initialize your instance
bool MainMenuLayer::init()
{
    if (!Layer::init()) {
        return false;
    }
    //
    Size visibleSize = Director::getInstance()->getVisibleSize();
    //    Point origin = Director::getInstance()->getVisibleOrigin();
    //    CCLog("width:%f,height:%f", visibleSize.width, visibleSize.height);
    //    CCLog("pointX:%f,pointY:%f", origin.x, origin.y);
    //    Layout* layout = Layout::create();
    //    layout->setSize(Size(500, 500));
    //    layout->setPosition(Point(0, 0));
    //    layout->setAnchorPoint(ccp(0,-0.5));
    //    layout->setBackGroundColor(Color3B(123, 123, 123));
    //    layout->setBackGroundColorType(LAYOUT_COLOR_SOLID);
    //    layout->addChild(buildTestUIButton());
    //    layout->addChild(buildTestUIButton());
    //    layout->addChild(buildTestUIButton());
    //    layout->setLayoutType(LayoutType::LAYOUT_LINEAR_VERTICAL);
    //    this->addChild(layout);

    Sprite* BtnNormal = Sprite::create("CloseNormal.png");
    Sprite* BtnPressed = Sprite::create("CloseSelected.png");
    MenuItemSprite* startBt = MenuItemSprite::create(BtnNormal, BtnPressed);

    Sprite* BtnNormal2 = Sprite::create("CloseNormal.png");
    Sprite* BtnPressed2 = Sprite::create("CloseSelected.png");
    MenuItemSprite* startBt2 = MenuItemSprite::create(BtnNormal2, BtnPressed2);

    Menu* menu = Menu::create(startBt, startBt2, NULL);
    menu->setPosition(Point(visibleSize.width * 0.5, visibleSize.height * 0.3 - 15));
    menu->alignItemsVerticallyWithPadding(30);
    this->addChild(menu);

    Sprite* start = Sprite::create("Account.9.png");
    Sprite* scene = Sprite::create("Account.9.png");
    start->setPosition(Point(visibleSize.width * 0.5, visibleSize.height * 0.3 + 25));
    scene->setPosition(Point(visibleSize.width * 0.5, visibleSize.height * 0.2 - 35));
    this->addChild(start);
    this->addChild(scene);
    return true;
}

void MainMenuLayer::start_callback(CCObject* pSender)
{
    CCLOG("start game");
}

void MainMenuLayer::scene_callback(CCObject* pSender)
{
    CCLOG("select scene");
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

Button* MainMenuLayer::buildTestUIButton()
{
    Button* button_scale9 = cocos2d::ui::Button::create();
    button_scale9->setTouchEnabled(true);
    button_scale9->loadTextures("CloseNormal.png", "CloseSelected.png", "");
    button_scale9->setScale9Enabled(true);
    button_scale9->setSize(Size(100, 100));
    return button_scale9;
}

void MainMenuLayer::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
