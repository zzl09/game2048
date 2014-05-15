//
//  DataUtil.h
//  MyGame
//
//  Created by zzl09 on 14-5-14.
//  Copyright (c) 2014年 zzl09. All rights reserved.
//

#ifndef __MyGame__DataUtil__
#define __MyGame__DataUtil__

#include "cocos2d.h"

class DataUtil {
public:
    /*create a random number from start to end*/
    static int getRand(int start, int end);

    /*get a number length*/
    static int getNumberLength(int number);
};

#endif
