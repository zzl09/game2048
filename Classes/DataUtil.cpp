//
//  DataUtil.cpp
//  MyGame
//
//  Created by zzl09 on 14-5-14.
//  Copyright (c) 2014年 zzl09. All rights reserved.
//

#include "DataUtil.h"

int DataUtil::getRand(int start, int end)
{

    float i = CCRANDOM_0_1() * (end - start + 1) + start;
    return (int)i;
}

int DataUtil::getNumberLength(int number)
{
    int a = number;
    int count = 0;
    do {
        count += 1;
        a = (int)(a / 10);
    } while (a != 0);

    return count;
}