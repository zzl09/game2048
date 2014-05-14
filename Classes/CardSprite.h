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

class CardSprite : public cocos2d::Sprite {
public:
    static CardSprite* createCardSprite(int number, int wight, int height, float positionX, float positionY);
    virtual bool init();
    CREATE_FUNC(CardSprite);

    void setNumber(int number);
    int getNumber();

private:
    int number;
    void enemyInit(int number, int wight, int height, float positionX, float positionY);

    //show
    cocos2d::LabelTTF* labelTTFCardNumber;
    cocos2d::LayerColor* labelColorBG;
};
#endif /* defined(__MyGame__CardSprite__) */
