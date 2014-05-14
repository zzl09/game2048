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
    /*产生一个从start到end间的随机数*/
    static int getRand(int start, int end);

    /*获得一个数字的长度*/
    static int getNumberLength(int number);
};

#endif /* defined(__MyGame__DataUtil__) */
