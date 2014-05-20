#include "GameWorld.h"
#include "NumSprite.h"
#include "DataUtil.h"
#import "SimpleAudioEngine.h"

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

    //init isMoveLocked
    isMoveLocked = false;

    //init inner data
    setNumSpriteArray(NumSpriteArray::create());

    //fetch evi param
    Size visiableSize = Director::getInstance()->getVisibleSize();

    //init bg
    LayerColor* layerColorBg = LayerColor::create(Color4B(180, 170, 160, 255));
    this->addChild(layerColorBg);

    //init scoreSprite
    scoreSprite = ScoreSprite::create(0, Point(visiableSize.width / 2 + 120, visiableSize.height - 150));
    this->addChild(scoreSprite);

    //init event listener
    EventListenerTouchOneByOne* touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = CC_CALLBACK_2(GameWorld::onTouchBegan, this);
    touchListener->onTouchMoved = CC_CALLBACK_2(GameWorld::onTouchMoved, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

    //init numSpriteArray
    createNumSprite(visiableSize);

    //init spriteMoveHelper
    setNumSpriteMoveHelper(NumSpriteMoveHelper::create(numSpriteArray));
    return true;
}

bool GameWorld::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
    Point touchPoint = touch->getLocation();
    touchX = touchPoint.x;
    touchY = touchPoint.y;
    isMoveLocked = false;
    return true;
}

void GameWorld::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event)
{
    MoveResult* moveResult;
    Point touchPoint = touch->getLocation();
    int endX = touchX - touchPoint.x;
    int endY = touchY - touchPoint.y;
    if (!isMoveLocked && abs(endX - endY) > 50) {
        if (abs(endX) > abs(endY)) {
            if (endX > 0) {
                moveResult = numSpriteMoveHelper->moveLeft();
            } else {
                moveResult = numSpriteMoveHelper->moveRight();
            }
        } else {
            if (endY > 0) {
                moveResult = numSpriteMoveHelper->moveDown();
            } else {
                moveResult = numSpriteMoveHelper->moveUp();
            }
        }
        if (moveResult->score > 0) {
            randomFill();
            char* playSound;
            if (moveResult->isMerged) {
                playSound="merge.wav";
            }else{
                playSound="move.wav";
            }
            CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic(playSound, false);
            scoreSprite->setScore(moveResult->score + scoreSprite->getScore());
            if (isGameOver()) {
                Director::getInstance()->replaceScene(TransitionFade::create(1, GameWorld::createScene()));
            }
        }
        isMoveLocked = true;
    }
    
}

void GameWorld::createNumSprite(cocos2d::Size size)
{
    int margin = 28;
    int singleMargin = 20;
    int singleLon = (size.width - margin) / Config::LINE_COUNT;
    for (int i = 0; i < Config::LINE_COUNT; i++) {
        for (int j = 0; j < Config::LINE_COUNT; j++) {
            Point position = Point(singleLon * i + singleMargin, singleLon * j + singleMargin + size.height / 6);
            NumSprite* cardSprite = NumSprite::create(0, singleLon, singleLon, position);
            numSpriteArray->numSprites[i][j] = cardSprite;
            addChild(cardSprite);
        }
    }
    randomFill();
}

void GameWorld::randomFill()
{
    int emptyCount = 0;
    for (int i = 0; i < Config::LINE_COUNT; i++) {
        for (int j = 0; j < Config::LINE_COUNT; j++) {
            if (numSpriteArray->numSprites[i][j]->getNumber() <= 0) {
                emptyCount++;
            }
        }
    }
    if (emptyCount == 0) {
        return;
    }
    int randomIndex = DataUtil::getRand(0, emptyCount - 1);
    emptyCount = 0;
    for (int i = 0; i < Config::LINE_COUNT; i++) {
        for (int j = 0; j < Config::LINE_COUNT; j++) {
            if (numSpriteArray->numSprites[i][j]->getNumber() <= 0) {
                if (emptyCount == randomIndex) {
                    numSpriteArray->numSprites[i][j]->setNumber(DataUtil::getRand(1, 2) * 2);
                    return;
                }
                emptyCount++;
            }
        }
    }
}

bool GameWorld::isGameOver()
{
    for (int i = 0; i < Config::LINE_COUNT; i++) {
        for (int j = 0; j < Config::LINE_COUNT; j++) {
            NumSprite* numSprite = numSpriteArray->numSprites[i][j];
            if (numSprite->getNumber() <= 0) {
                return false;
            } else if (i > 0 && numSprite->getNumber() == numSpriteArray->numSprites[i - 1][j]->getNumber()) {
                return false;
            } else if (j > 0 && numSprite->getNumber() == numSpriteArray->numSprites[i][j - 1]->getNumber()) {
                return false;
            }
        }
    }
    return true;
};
