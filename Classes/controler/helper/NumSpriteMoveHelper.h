//
//  NumSpriteMoveHelper.h
//  MyGame
//
//  Created by zzl09 on 14-5-15.
//  Copyright (c) 2014年 zzl09. All rights reserved.
//

#ifndef __MyGame__NumSpriteMoveHelper__
#define __MyGame__NumSpriteMoveHelper__

#include "cocos2d.h"
#include "NumSprite.h"
#include "Config.h"
#include "NumSpriteArray.h"
#include "MoveResult.h"

class NumSpriteMoveHelper : public cocos2d::Ref {
public:
    CREATE_FUNC(NumSpriteMoveHelper);
    virtual bool init();

    /**
     *  create a NumSpriteMoveHelper
     *
     *  @param numSpritearray numSpritearray description
     *
     *  @return what create
     */
    static NumSpriteMoveHelper* create(NumSpriteArray* numSpritearray);

    /**
     *  init NumSpriteMoveHelper data
     *
     *  @param numSpritearray numSpritearray description
     */
    void init(NumSpriteArray* numSpritearray);

    /**
     *  move to up
     *
     *  @return MoveResult
     */
    MoveResult* moveUp();

    /**
     *  move to down
     *
     *  @return MoveResult
     */
    MoveResult* moveDown();

    /**
     *  move to left
     *
     *  @return MoveResult
     */
    MoveResult* moveLeft();

    /**
     *  move to right
     *
     *  @return MoveResult
     */
    MoveResult* moveRight();

    NumSpriteMoveHelper()
    {
        numSpriteArray = NULL;
        moveResult = NULL;
    }
    ~NumSpriteMoveHelper()
    {
        CC_SAFE_RELEASE(numSpriteArray);
        CC_SAFE_FREE(moveResult);
    }

private:
    MoveResult *moveResult;
    CC_SYNTHESIZE_RETAIN(NumSpriteArray*, numSpriteArray, NumSpriteArray);
    void resetMoveResult();
};

#endif
