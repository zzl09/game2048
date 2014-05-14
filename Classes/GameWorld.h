#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "NumSprite.h"
class GameWorld : public cocos2d::Layer {
    const static int LINE_CARD_NUM = 4;
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(GameWorld);
    virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
private:
    int firstX, firstY, endX, endY;
    NumSprite* numSprites[LINE_CARD_NUM][LINE_CARD_NUM];
    bool isGameOver();
    void createNumSprite(cocos2d::Size size);
    void randomFill();
    bool moveLeft();
    bool moveRight();
    bool moveDown();
    bool moveUp();
};

#endif
