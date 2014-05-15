//
//  ScoreSprite.cpp
//  MyGame
//
//  Created by zzl09 on 14-5-15.
//  Copyright (c) 2014年 zzl09. All rights reserved.
//

#include "ScoreSprite.h"
USING_NS_CC;

bool ScoreSprite::init()
{
    if (!Sprite::init()) {
        return false;
    }
    return true;
}

ScoreSprite* ScoreSprite::create(int score, cocos2d::Point point)
{
    ScoreSprite* result = new ScoreSprite;
    if (result && result->init()) {
        result->autorelease();
        result->init(score, point);
        return result;
    }
    CC_SAFE_DELETE(result);
    return NULL;
}

void ScoreSprite::init(int score, cocos2d::Point point)
{
    this->scoreLabel = cocos2d::LabelTTF::create("", "HiraKakuProN-W6", 50);
    scoreLabel->setPosition(point);
    this->addChild(scoreLabel);
    setScore(score);
}

void ScoreSprite::updateUI()
{
    scoreLabel->setString(__String::createWithFormat("%ld", score)->getCString());
}

long ScoreSprite::getScore()
{
    return score;
}

void ScoreSprite::setScore(long score)
{
    this->score = score;
    updateUI();
}
