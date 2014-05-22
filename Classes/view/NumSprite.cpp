//
//  CardSprite.cpp
//  MyGame
//
//  Created by zzl09 on 14-5-14.
//  Copyright (c) 2014年 zzl09. All rights reserved.
//

#include "NumSprite.h"
#include "DataUtil.h"
USING_NS_CC;

NumSprite* NumSprite::create(int number, int wight, int height, cocos2d::Point position)
{
    NumSprite* result = new NumSprite();
    if (result && result->init()) {
        result->autorelease();
        result->init(number, wight, height, position);
        return result;
    }
    CC_SAFE_DELETE(result);
    return NULL;
}

bool NumSprite::init()
{
    if (!Sprite::init()) {
        return false;
    }
    return true;
}

void NumSprite::init(int number, int wight, int height, cocos2d::Point position)
{
    int bgSizeOffset = 15;
    labelColorBG = cocos2d::LayerColor::create(cocos2d::Color4B(200, 190, 180, 255), wight - bgSizeOffset, height - bgSizeOffset);
    labelTTFCardNumber = cocos2d::LabelTTF::create("", "HiraKakuProN-W6", 100);
    labelColorBG->setPosition(position);
    labelTTFCardNumber->setPosition(Point(labelColorBG->getContentSize().width / 2, labelColorBG->getContentSize().height / 2));
    labelColorBG->addChild(labelTTFCardNumber);
    this->addChild(labelColorBG);
    setNumber(number);
}

cocos2d::LabelTTF* NumSprite::getLabelTTFCardNumber()
{
    return labelTTFCardNumber;
}

void NumSprite::updateUI()
{
    if (number > 0) {
        int fontSize = 100 - ((DataUtil::getNumberLength(number) - 1) * 20);
        this->labelTTFCardNumber->setFontSize(fontSize);
        this->labelTTFCardNumber->setString(__String::createWithFormat("%i", number)->getCString());

        this->labelColorBG->setColor(getNumberBgColor(number));
        this->labelTTFCardNumber->setColor(getNumberColor(number));
    } else {
        this->labelTTFCardNumber->setString("");
        this->labelColorBG->setColor(cocos2d::Color3B(200, 190, 180));
    }
}

void NumSprite::setNumber(int number)
{
    this->number = number;
    updateUI();
}

int NumSprite::getNumber()
{
    return this->number;
}

cocos2d::Color3B NumSprite::getNumberBgColor(int number)
{
    cocos2d::Color3B colorBG;
    if (number == 2) {
        colorBG = cocos2d::Color3B(238, 228, 218);
    } else if (number == 4) {
        colorBG = cocos2d::Color3B(236, 224, 200);
    } else if (number == 8) {
        colorBG = cocos2d::Color3B(242, 177, 121);
    } else if (number == 16) {
        colorBG = cocos2d::Color3B(223, 141, 83);
    } else if (number == 32) {
        colorBG = cocos2d::Color3B(245, 124, 95);
    } else if (number == 64) {
        colorBG = cocos2d::Color3B(233, 89, 55);
    } else if (number == 128) {
        colorBG = cocos2d::Color3B(241, 219, 108);
    } else if (number == 256) {
        colorBG = cocos2d::Color3B(240, 207, 74);
    } else if (number == 512) {
        colorBG = cocos2d::Color3B(228, 193, 41);
    } else if (number == 1024) {
        colorBG = cocos2d::Color3B(227, 186, 20);
    } else if (number == 2048) {
        colorBG = cocos2d::Color3B(238, 194, 46);
    } else if (number == 4096) {
        colorBG = cocos2d::Color3B(94, 218, 146);
    } else {
        colorBG = cocos2d::Color3B(118, 109, 103);
    }
    return colorBG;
}

cocos2d::Color3B NumSprite::getNumberColor(int number)
{
    cocos2d::Color3B colorFont;
    if (number == 2) {
        colorFont = cocos2d::Color3B(118, 109, 103);
    } else {
        colorFont = cocos2d::Color3B(254, 254, 254);
    }
    return colorFont;
}