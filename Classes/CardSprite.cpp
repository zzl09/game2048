//
//  CardSprite.cpp
//  MyGame
//
//  Created by zzl09 on 14-5-14.
//  Copyright (c) 2014年 zzl09. All rights reserved.
//

#include "CardSprite.h"
USING_NS_CC;

CardSprite* CardSprite::createCardSprite(int number, int wight, int height, float positionX, float positionY)
{
    CardSprite* result = new CardSprite();
    if (result && result->init()) {
        result->autorelease();
        result->enemyInit(number, wight, height, positionX, positionY);
        return result;
    }
    //    CC_SAFE_DELETE(result);
    //    return NULL;
}
bool CardSprite::init()
{
    if (!Sprite::init()) {
        return false;
    }
    return true;
}

void CardSprite::setNumber(int number)
{
    this->number = number;
    //update ui
    if (number > 0) {
        this->labelTTFCardNumber->setString(__String::createWithFormat("%i", number)->getCString());
    } else {
        this->labelTTFCardNumber->setString("");
    }
}

int CardSprite::getNumber()
{
    return this->number;
}

void CardSprite::enemyInit(int number, int wight, int height, float positionX, float positionY)
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

    labelTTFCardNumber = cocos2d::LabelTTF::create(showString, "黑体", 80);
    labelTTFCardNumber->setPosition(Point(labelColorBG->getContentSize().width / 2, labelColorBG->getContentSize().height / 2));
    labelColorBG->addChild(labelTTFCardNumber);
    this->addChild(labelColorBG);
}
