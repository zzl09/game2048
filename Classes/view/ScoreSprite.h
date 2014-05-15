//
//  ScoreSprite.h
//  MyGame
//
//  Created by zzl09 on 14-5-15.
//  Copyright (c) 2014年 zzl09. All rights reserved.
//

#ifndef __MyGame__ScoreSprite__
#define __MyGame__ScoreSprite__

#include "cocos2d.h"
class ScoreSprite : public cocos2d::Sprite {
public:
    CREATE_FUNC(ScoreSprite);
    static ScoreSprite* create(int score, cocos2d::Point point);
    void init(int score,cocos2d::Point point);
    virtual bool init();
    long getScore();
    void setScore(long score);
private:
    void updateUI();
    long score;
    cocos2d::LabelTTF *scoreLabel;
    cocos2d::LabelTTF *scoreNoteLabel;
};

#endif
