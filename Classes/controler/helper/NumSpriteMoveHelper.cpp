//
//  NumSpriteMoveHelper.cpp
//  MyGame
//
//  Created by zzl09 on 14-5-15.
//  Copyright (c) 2014年 zzl09. All rights reserved.
//

#include "NumSpriteMoveHelper.h"
NumSpriteMoveHelper* NumSpriteMoveHelper::create(NumSpriteArray* numSpritearray)
{
    NumSpriteMoveHelper* result = new NumSpriteMoveHelper();
    if (result && result->init()) {
        result->autorelease();
        result->init(numSpritearray);
        return result;
    }
    CC_SAFE_DELETE(result);
    return NULL;
}

bool NumSpriteMoveHelper::init()
{
    return true;
}


void NumSpriteMoveHelper::init(NumSpriteArray* numSpritearray)
{
    this->numSpritearray=numSpritearray;
}

int NumSpriteMoveHelper::moveLeft()
{
    int result = 0;
    for (int j = 0; j < Config::LINE_COUNT; j++) {
        for (int i = 0; i < Config::LINE_COUNT; i++) {
            for (int ii = i + 1; ii < Config::LINE_COUNT; ii++) {
                if (numSpritearray->numSprites[ii][j]->getNumber() > 0) {
                    if (numSpritearray->numSprites[i][j]->getNumber() <= 0) {
                        numSpritearray->numSprites[i][j]->setNumber(numSpritearray->numSprites[ii][j]->getNumber());
                        numSpritearray->numSprites[ii][j]->setNumber(0);
                        result = result + numSpritearray->numSprites[i][j]->getNumber();
                        i--;
                    } else if (numSpritearray->numSprites[ii][j]->getNumber() == numSpritearray->numSprites[i][j]->getNumber()) {
                        numSpritearray->numSprites[i][j]->setNumber(numSpritearray->numSprites[i][j]->getNumber() * 2);
                        numSpritearray->numSprites[ii][j]->setNumber(0);
                        result = result + numSpritearray->numSprites[i][j]->getNumber();
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
                if (numSpritearray->numSprites[ii][j]->getNumber() > 0) {
                    if (numSpritearray->numSprites[i][j]->getNumber() <= 0) {
                        numSpritearray->numSprites[i][j]->setNumber(numSpritearray->numSprites[ii][j]->getNumber());
                        numSpritearray->numSprites[ii][j]->setNumber(0);
                        result = result + numSpritearray->numSprites[i][j]->getNumber();
                        i++;
                    } else if (numSpritearray->numSprites[ii][j]->getNumber() == numSpritearray->numSprites[i][j]->getNumber()) {
                        numSpritearray->numSprites[i][j]->setNumber(numSpritearray->numSprites[i][j]->getNumber() * 2);
                        numSpritearray->numSprites[ii][j]->setNumber(0);
                        result = result + numSpritearray->numSprites[i][j]->getNumber();
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
                if (numSpritearray->numSprites[i][jj]->getNumber() > 0) {
                    if (numSpritearray->numSprites[i][j]->getNumber() <= 0) {
                        numSpritearray->numSprites[i][j]->setNumber(numSpritearray->numSprites[i][jj]->getNumber());
                        numSpritearray->numSprites[i][jj]->setNumber(0);
                        result = result + numSpritearray->numSprites[i][j]->getNumber();
                        j--;
                        result = true;
                    } else if (numSpritearray->numSprites[i][jj]->getNumber() == numSpritearray->numSprites[i][j]->getNumber()) {
                        numSpritearray->numSprites[i][j]->setNumber(numSpritearray->numSprites[i][j]->getNumber() * 2);
                        numSpritearray->numSprites[i][jj]->setNumber(0);
                        result = result + numSpritearray->numSprites[i][j]->getNumber();
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
                if (numSpritearray->numSprites[i][jj]->getNumber() > 0) {
                    if (numSpritearray->numSprites[i][j]->getNumber() <= 0) {
                        numSpritearray->numSprites[i][j]->setNumber(numSpritearray->numSprites[i][jj]->getNumber());
                        numSpritearray->numSprites[i][jj]->setNumber(0);
                        result = result + numSpritearray->numSprites[i][j]->getNumber();
                        j++;
                    } else if (numSpritearray->numSprites[i][jj]->getNumber() == numSpritearray->numSprites[i][j]->getNumber()) {
                        numSpritearray->numSprites[i][j]->setNumber(numSpritearray->numSprites[i][j]->getNumber() * 2);
                        numSpritearray->numSprites[i][jj]->setNumber(0);
                        result = result + numSpritearray->numSprites[i][j]->getNumber();
                    }
                    break;
                }
            }
        }
    }
    return result;
}