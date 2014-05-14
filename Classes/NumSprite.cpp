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

NumSprite* NumSprite::createNumSprite(int number, int wight, int height, float positionX, float positionY)
{
    NumSprite* result = new NumSprite();
    if (result && result->init()) {
        result->autorelease();
        result->init(number, wight, height, positionX, positionY);
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

void NumSprite::setNumber(int number)
{
    this->number = number;
    if (number > 0) {
        int fontSize = 100 - ((DataUtil::getNumberLength(number) - 1) * 20);
        this->labelTTFCardNumber->setFontSize(fontSize);
        this->labelTTFCardNumber->setString(__String::createWithFormat("%i", number)->getCString());
    } else {
        this->labelTTFCardNumber->setString("");
    }
}

int NumSprite::getNumber()
{
    return this->number;
}

void NumSprite::init(int number, int wight, int height, float positionX, float positionY)
{
    int bgSizeOffset = 15;
    this->number = number;
    labelColorBG = cocos2d::LayerColor::create(cocos2d::Color4B(200, 190, 180, 255), wight - bgSizeOffset, height - bgSizeOffset);
    labelColorBG->setPosition(positionX, positionY);

    std::string showString;
    if (number > 0) {
        showString = __String::createWithFormat("%i", number)->getCString();
    } else {
        showString = "";
    }

    labelTTFCardNumber = cocos2d::LabelTTF::create(showString, "HiraKakuProN-W6", 100);
    labelTTFCardNumber->setPosition(Point(labelColorBG->getContentSize().width / 2, labelColorBG->getContentSize().height / 2));
    labelColorBG->addChild(labelTTFCardNumber);
    this->addChild(labelColorBG);
}
