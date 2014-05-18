//
//  NumSpriteMoveHelper.cpp
//  MyGame
//
//  Created by zzl09 on 14-5-15.
//  Copyright (c) 2014年 zzl09. All rights reserved.
//

#include "NumSpriteMoveHelper.h"
NumSpriteMoveHelper* NumSpriteMoveHelper::create(NumSpriteArray* numSpriteArray)
{
    NumSpriteMoveHelper* result = new NumSpriteMoveHelper();
    if (result && result->init()) {
        result->autorelease();
        result->init(numSpriteArray);
        return result;
    }
    CC_SAFE_DELETE(result);
    return NULL;
}

bool NumSpriteMoveHelper::init()
{
    return true;
}


void NumSpriteMoveHelper::init(NumSpriteArray* numSpriteArray)
{
//    this->numSpriteArray=numSpriteArray;
    setNumSpriteArray(numSpriteArray);
}

int NumSpriteMoveHelper::moveLeft()
{
    int result = 0;
    for (int j = 0; j < Config::LINE_COUNT; j++) {
        for (int i = 0; i < Config::LINE_COUNT; i++) {
            for (int ii = i + 1; ii < Config::LINE_COUNT; ii++) {
                if (getNumSpriteArray()->numSprites[ii][j]->getNumber() > 0) {
                    if (getNumSpriteArray()->numSprites[i][j]->getNumber() <= 0) {
                        getNumSpriteArray()->numSprites[i][j]->setNumber(getNumSpriteArray()->numSprites[ii][j]->getNumber());
                        getNumSpriteArray()->numSprites[ii][j]->setNumber(0);
                        result = result + getNumSpriteArray()->numSprites[i][j]->getNumber();
                        i--;
                    } else if (getNumSpriteArray()->numSprites[ii][j]->getNumber() == getNumSpriteArray()->numSprites[i][j]->getNumber()) {
                        getNumSpriteArray()->numSprites[i][j]->setNumber(getNumSpriteArray()->numSprites[i][j]->getNumber() * 2);
                        getNumSpriteArray()->numSprites[ii][j]->setNumber(0);
                        result = result + getNumSpriteArray()->numSprites[i][j]->getNumber();
                    }
                    break;
                }
            }
        }
    }
    return result;
}

int NumSpriteMoveHelper::moveRight()
{
    int result = 0;
    for (int j = 0; j < Config::LINE_COUNT; j++) {
        for (int i = Config::LINE_COUNT - 1; i >= 0; i--) {
            for (int ii = i - 1; ii >= 0; ii--) {
                if (getNumSpriteArray()->numSprites[ii][j]->getNumber() > 0) {
                    if (getNumSpriteArray()->numSprites[i][j]->getNumber() <= 0) {
                        getNumSpriteArray()->numSprites[i][j]->setNumber(getNumSpriteArray()->numSprites[ii][j]->getNumber());
                        getNumSpriteArray()->numSprites[ii][j]->setNumber(0);
                        result = result + getNumSpriteArray()->numSprites[i][j]->getNumber();
                        i++;
                    } else if (getNumSpriteArray()->numSprites[ii][j]->getNumber() == getNumSpriteArray()->numSprites[i][j]->getNumber()) {
                        getNumSpriteArray()->numSprites[i][j]->setNumber(getNumSpriteArray()->numSprites[i][j]->getNumber() * 2);
                        getNumSpriteArray()->numSprites[ii][j]->setNumber(0);
                        result = result + getNumSpriteArray()->numSprites[i][j]->getNumber();
                    }
                    break;
                }
            }
        }
    }
    return result;
}

int NumSpriteMoveHelper::moveDown()
{
    int result = 0;
    for (int i = 0; i < Config::LINE_COUNT; i++) {
        for (int j = 0; j < Config::LINE_COUNT; j++) {
            for (int jj = j + 1; jj < Config::LINE_COUNT; jj++) {
                if (getNumSpriteArray()->numSprites[i][jj]->getNumber() > 0) {
                    if (getNumSpriteArray()->numSprites[i][j]->getNumber() <= 0) {
                        getNumSpriteArray()->numSprites[i][j]->setNumber(getNumSpriteArray()->numSprites[i][jj]->getNumber());
                        getNumSpriteArray()->numSprites[i][jj]->setNumber(0);
                        result = result + getNumSpriteArray()->numSprites[i][j]->getNumber();
                        j--;
                    } else if (getNumSpriteArray()->numSprites[i][jj]->getNumber() == getNumSpriteArray()->numSprites[i][j]->getNumber()) {
                        getNumSpriteArray()->numSprites[i][j]->setNumber(getNumSpriteArray()->numSprites[i][j]->getNumber() * 2);
                        getNumSpriteArray()->numSprites[i][jj]->setNumber(0);
                        result = result + getNumSpriteArray()->numSprites[i][j]->getNumber();
                    }
                    break;
                }
            }
        }
    }
    return result;
}

int NumSpriteMoveHelper::moveUp()
{
    int result = 0;
    for (int i = 0; i < Config::LINE_COUNT; i++) {
        for (int j = Config::LINE_COUNT - 1; j >= 0; j--) {
            for (int jj = j - 1; jj >= 0; jj--) {
                if (getNumSpriteArray()->numSprites[i][jj]->getNumber() > 0) {
                    if (getNumSpriteArray()->numSprites[i][j]->getNumber() <= 0) {
                        getNumSpriteArray()->numSprites[i][j]->setNumber(getNumSpriteArray()->numSprites[i][jj]->getNumber());
                        getNumSpriteArray()->numSprites[i][jj]->setNumber(0);
                        result = result + getNumSpriteArray()->numSprites[i][j]->getNumber();
                        j++;
                    } else if (getNumSpriteArray()->numSprites[i][jj]->getNumber() == getNumSpriteArray()->numSprites[i][j]->getNumber()) {
                        getNumSpriteArray()->numSprites[i][j]->setNumber(getNumSpriteArray()->numSprites[i][j]->getNumber() * 2);
                        getNumSpriteArray()->numSprites[i][jj]->setNumber(0);
                        result = result + getNumSpriteArray()->numSprites[i][j]->getNumber();
                    }
                    break;
                }
            }
        }
    }
    return result;
}