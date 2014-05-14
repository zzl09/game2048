//
//  CardSprite.h
//  MyGame
//
//  Created by zzl09 on 14-5-14.
//  Copyright (c) 2014年 zzl09. All rights reserved.
//

#ifndef __MyGame__CardSprite__
#define __MyGame__CardSprite__

#include "cocos2d.h"

class NumSprite : public cocos2d::Sprite {
public:
    static NumSprite* createNumSprite(int number, int wight, int height, float positionX, float positionY);
    virtual bool init();
    CREATE_FUNC(NumSprite);
    void setNumber(int number);
    int getNumber();
private:
    int number;
    cocos2d::LabelTTF* labelTTFCardNumber;
    cocos2d::LayerColor* labelColorBG;
    void init(int number, int wight, int height, float positionX, float positionY);
};
#endif /* defined(__MyGame__CardSprite__) */
