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
    moveResult = new MoveResult();
    setNumSpriteArray(numSpriteArray);
    resetMoveResult();
}

void NumSpriteMoveHelper::resetMoveResult()
{
    moveResult->score = 0;
    moveResult->isMerged = false;
}

MoveResult* NumSpriteMoveHelper::moveLeft()
{
    resetMoveResult();
    int score = 0;
    for (int j = 0; j < Config::LINE_COUNT; j++) {
        for (int i = 0; i < Config::LINE_COUNT; i++) {
            for (int ii = i + 1; ii < Config::LINE_COUNT; ii++) {
                if (getNumSpriteArray()->numSprites[ii][j]->getNumber() > 0) {
                    if (getNumSpriteArray()->numSprites[i][j]->getNumber() <= 0) {
                        getNumSpriteArray()->numSprites[i][j]->setNumber(getNumSpriteArray()->numSprites[ii][j]->getNumber());
                        getNumSpriteArray()->numSprites[ii][j]->setNumber(0);
                        score = score + getNumSpriteArray()->numSprites[i][j]->getNumber();
                        i--;
                    } else if (getNumSpriteArray()->numSprites[ii][j]->getNumber() == getNumSpriteArray()->numSprites[i][j]->getNumber()) {
                        moveResult->isMerged = true;
                        getNumSpriteArray()->numSprites[i][j]->setNumber(getNumSpriteArray()->numSprites[i][j]->getNumber() * 2);
                        getNumSpriteArray()->numSprites[ii][j]->setNumber(0);
                        score = score + getNumSpriteArray()->numSprites[i][j]->getNumber();
                    }
                    break;
                }
            }
        }
    }
    moveResult->score = score;
    return moveResult;
}

MoveResult* NumSpriteMoveHelper::moveRight()
{
    resetMoveResult();
    int score = 0;
    for (int j = 0; j < Config::LINE_COUNT; j++) {
        for (int i = Config::LINE_COUNT - 1; i >= 0; i--) {
            for (int ii = i - 1; ii >= 0; ii--) {
                if (getNumSpriteArray()->numSprites[ii][j]->getNumber() > 0) {
                    if (getNumSpriteArray()->numSprites[i][j]->getNumber() <= 0) {
                        getNumSpriteArray()->numSprites[i][j]->setNumber(getNumSpriteArray()->numSprites[ii][j]->getNumber());
                        getNumSpriteArray()->numSprites[ii][j]->setNumber(0);
                        score = score + getNumSpriteArray()->numSprites[i][j]->getNumber();
                        i++;
                    } else if (getNumSpriteArray()->numSprites[ii][j]->getNumber() == getNumSpriteArray()->numSprites[i][j]->getNumber()) {
                        moveResult->isMerged = true;
                        getNumSpriteArray()->numSprites[i][j]->setNumber(getNumSpriteArray()->numSprites[i][j]->getNumber() * 2);
                        getNumSpriteArray()->numSprites[ii][j]->setNumber(0);
                        score = score + getNumSpriteArray()->numSprites[i][j]->getNumber();
                    }
                    break;
                }
            }
        }
    }
    moveResult->score = score;
    return moveResult;
}

MoveResult* NumSpriteMoveHelper::moveDown()
{
    resetMoveResult();
    int score = 0;
    for (int i = 0; i < Config::LINE_COUNT; i++) {
        for (int j = 0; j < Config::LINE_COUNT; j++) {
            for (int jj = j + 1; jj < Config::LINE_COUNT; jj++) {
                if (getNumSpriteArray()->numSprites[i][jj]->getNumber() > 0) {
                    if (getNumSpriteArray()->numSprites[i][j]->getNumber() <= 0) {
                        getNumSpriteArray()->numSprites[i][j]->setNumber(getNumSpriteArray()->numSprites[i][jj]->getNumber());
                        getNumSpriteArray()->numSprites[i][jj]->setNumber(0);
                        score = score + getNumSpriteArray()->numSprites[i][j]->getNumber();
                        j--;
                    } else if (getNumSpriteArray()->numSprites[i][jj]->getNumber() == getNumSpriteArray()->numSprites[i][j]->getNumber()) {
                        moveResult->isMerged = true;
                        getNumSpriteArray()->numSprites[i][j]->setNumber(getNumSpriteArray()->numSprites[i][j]->getNumber() * 2);
                        getNumSpriteArray()->numSprites[i][jj]->setNumber(0);
                        score = score + getNumSpriteArray()->numSprites[i][j]->getNumber();
                    }
                    break;
                }
            }
        }
    }
    moveResult->score = score;
    return moveResult;
}

MoveResult* NumSpriteMoveHelper::moveUp()
{
    resetMoveResult();
    int score = 0;
    for (int i = 0; i < Config::LINE_COUNT; i++) {
        for (int j = Config::LINE_COUNT - 1; j >= 0; j--) {
            for (int jj = j - 1; jj >= 0; jj--) {
                if (getNumSpriteArray()->numSprites[i][jj]->getNumber() > 0) {
                    if (getNumSpriteArray()->numSprites[i][j]->getNumber() <= 0) {
                        getNumSpriteArray()->numSprites[i][j]->setNumber(getNumSpriteArray()->numSprites[i][jj]->getNumber());
                        getNumSpriteArray()->numSprites[i][jj]->setNumber(0);
                        score = score + getNumSpriteArray()->numSprites[i][j]->getNumber();
                        j++;
                    } else if (getNumSpriteArray()->numSprites[i][jj]->getNumber() == getNumSpriteArray()->numSprites[i][j]->getNumber()) {
                        moveResult->isMerged = true;
                        getNumSpriteArray()->numSprites[i][j]->setNumber(getNumSpriteArray()->numSprites[i][j]->getNumber() * 2);
                        getNumSpriteArray()->numSprites[i][jj]->setNumber(0);
                        score = score + getNumSpriteArray()->numSprites[i][j]->getNumber();
                    }
                    break;
                }
            }
        }
    }
    moveResult->score = score;
    return moveResult;
}