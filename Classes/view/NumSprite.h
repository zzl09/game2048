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
    CREATE_FUNC(NumSprite);
    static NumSprite* create(int number, int wight, int height, cocos2d::Point position);
    virtual bool init();
    void init(int number, int wight, int height, cocos2d::Point position);
    void setNumber(int number);
    int getNumber();

private:
    void updateUI();
    int number;
    cocos2d::LabelTTF* labelTTFCardNumber;
    cocos2d::LayerColor* labelColorBG;
};
#endif
