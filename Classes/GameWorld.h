#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class GameWorld : public cocos2d::Layer {
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(GameWorld);

    //手势事件
    virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);

    bool doLeft();
    bool doRight();
    bool doDown();
    bool doUp();

private:
    //点击的元素
    int firstX, firstY, endX, endY;
    void createCardSprite(cocos2d::Size size);
};

#endif
