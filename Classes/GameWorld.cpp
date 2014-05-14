#include "GameWorld.h"
#include "CardSprite.h"
USING_NS_CC;
Scene* GameWorld::createScene()
{
    Scene* scene = Scene::create();
    Layer* layer = GameWorld::create();
    scene->addChild(layer);
    return scene;
}

bool GameWorld::init()
{
    if (!Layer::init()) {
        return false;
    }

    Size visiableSize = Director::getInstance()->getVisibleSize();

    EventListenerTouchOneByOne* touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = CC_CALLBACK_2(GameWorld::onTouchBegan, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(GameWorld::onTouchEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
    createCardSprite(visiableSize);
    return true;
}

bool GameWorld::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
    Point touchPoint = touch->getLocation();
    firstX = touchPoint.x;
    firstY = touchPoint.y;
    return true;
}
void GameWorld::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{
    int offest = 5;
    Point touchPoint = touch->getLocation();
    endX = firstX - touchPoint.x;
    endY = firstY - touchPoint.y;
    if (abs(endX) > abs(endY)) {
        if (endX + 5 > 0) {
            doLeft();
        } else {
            doRight();
        }
    } else {
        if (endY + 5 > 0) {
            doDown();
        } else {
            doUp();
        }
    }
}

void GameWorld::createCardSprite(cocos2d::Size size)
{
    int margin = 28;
    int singleMargin = 20;
    int singleLon = (size.width - 28) / 4;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            CardSprite* cardSprite = CardSprite::createCardSprite(i+j+1, singleLon, singleLon, singleLon * i + 20, singleLon * j + 20 + size.height / 6);
            addChild(cardSprite);
        }
    }
}
bool GameWorld::doLeft()
{
    log("doLeft");
}
bool GameWorld::doRight()
{
    log("doRight");
}
bool GameWorld::doDown()
{
    log("doDown");
}
bool GameWorld::doUp()
{
    log("doUp");
}