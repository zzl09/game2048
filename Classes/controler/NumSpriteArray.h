//
//  NumSpriteArray.c
//  MyGame
//
//  Created by zzl09 on 14-5-15.
//  Copyright (c) 2014年 zzl09. All rights reserved.
//
#ifndef MyGame_NumSpriteArray_h
#define MyGame_NumSpriteArray_h

#include "NumSprite.h"
struct NumSpriteArray{
public:
    NumSprite* numSprites[Config::LINE_COUNT][Config::LINE_COUNT];
};

#endif