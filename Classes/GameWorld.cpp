#include "GameWorld.h"
#include "NumSprite.h"
#include "DataUtil.h"
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
    score = 0;
    LayerColor* layerColorBg = LayerColor::create(Color4B(180, 170, 160, 255));
    labelTTFScore = cocos2d::LabelTTF::create("0", "HiraKakuProN-W6", 50);
    labelTTFScore->setPosition(Point(visiableSize.width / 2 + 120, visiableSize.height - 150));
    this->addChild(layerColorBg);
    this->addChild(labelTTFScore);
    LabelTTF *labelTTFScoreNote = cocos2d::LabelTTF::create("score: ", "HiraKakuProN-W6", 50);
    labelTTFScoreNote->setPosition(Point(visiableSize.width / 2 , visiableSize.height - 150));
    this->addChild(labelTTFScoreNote);
    EventListenerTouchOneByOne* touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = CC_CALLBACK_2(GameWorld::onTouchBegan, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(GameWorld::onTouchEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
    createNumSprite(visiableSize);
    return true;
}

bool GameWorld::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
    Point touchPoint = touch->getLocation();
    touchX = touchPoint.x;
    touchY = touchPoint.y;
    return true;
}
void GameWorld::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{
    int offest = 5;
    bool isMoved = false;
    Point touchPoint = touch->getLocation();
    int endX = touchX - touchPoint.x;
    int endY = touchY - touchPoint.y;
    if (abs(endX) > abs(endY)) {
        if (endX + offest > 0) {
            isMoved = moveLeft();
        } else {
            isMoved = moveRight();
        }
    } else {
        if (endY + offest > 0) {
            isMoved = moveDown();
        } else {
            isMoved = moveUp();
        }
    }
    if (isMoved) {
        randomFill();
        if (isGameOver()) {
            Director::getInstance()->replaceScene(TransitionFade::create(1, GameWorld::createScene()));
        }
    }
    labelTTFScore->setString(__String::createWithFormat("%ld", score)->getCString());
}

void GameWorld::createNumSprite(cocos2d::Size size)
{
    int margin = 28;
    int singleMargin = 20;
    int singleLon = (size.width - margin) / LINE_COUNT;
    for (int i = 0; i < LINE_COUNT; i++) {
        for (int j = 0; j < LINE_COUNT; j++) {
            NumSprite* cardSprite = NumSprite::createNumSprite(0, singleLon, singleLon, singleLon * i + singleMargin, singleLon * j + singleMargin + size.height / 6);
            numSprites[i][j] = cardSprite;
            addChild(cardSprite);
        }
    }
    randomFill();
}

void GameWorld::randomFill()
{
    int emptyCount = 0;
    for (int i = 0; i < LINE_COUNT; i++) {
        for (int j = 0; j < LINE_COUNT; j++) {
            if (numSprites[i][j]->getNumber() <= 0) {
                emptyCount++;
            }
        }
    }
    if (emptyCount == 0) {
        return;
    }
    int randomIndex = DataUtil::getRand(0, emptyCount - 1);
    emptyCount = 0;
    for (int i = 0; i < LINE_COUNT; i++) {
        for (int j = 0; j < LINE_COUNT; j++) {
            if (numSprites[i][j]->getNumber() <= 0) {
                if (emptyCount == randomIndex) {
                    numSprites[i][j]->setNumber(DataUtil::getRand(1, 2) * 2);
                    return;
                }
                emptyCount++;
            }
        }
    }
}

bool GameWorld::moveLeft()
{
    bool result = false;
    for (int j = 0; j < LINE_COUNT; j++) {
        for (int i = 0; i < LINE_COUNT; i++) {
            for (int ii = i + 1; ii < LINE_COUNT; ii++) {
                if (numSprites[ii][j]->getNumber() > 0) {
                    if (numSprites[i][j]->getNumber() <= 0) {
                        numSprites[i][j]->setNumber(numSprites[ii][j]->getNumber());
                        numSprites[ii][j]->setNumber(0);
                        score = score + numSprites[i][j]->getNumber();
                        i--;
                        result = true;
                    } else if (numSprites[ii][j]->getNumber() == numSprites[i][j]->getNumber()) {
                        numSprites[i][j]->setNumber(numSprites[i][j]->getNumber() * 2);
                        numSprites[ii][j]->setNumber(0);
                        score = score + numSprites[i][j]->getNumber();
                        result = true;
                    }
                    break;
                }
            }
        }
    }
    return result;
}

bool GameWorld::moveRight()
{
    bool result = false;
    for (int j = 0; j < LINE_COUNT; j++) {
        for (int i = LINE_COUNT - 1; i >= 0; i--) {
            for (int ii = i - 1; ii >= 0; ii--) {
                if (numSprites[ii][j]->getNumber() > 0) {
                    if (numSprites[i][j]->getNumber() <= 0) {
                        numSprites[i][j]->setNumber(numSprites[ii][j]->getNumber());
                        numSprites[ii][j]->setNumber(0);
                        score = score + numSprites[i][j]->getNumber();
                        i++;
                        result = true;
                    } else if (numSprites[ii][j]->getNumber() == numSprites[i][j]->getNumber()) {
                        numSprites[i][j]->setNumber(numSprites[i][j]->getNumber() * 2);
                        numSprites[ii][j]->setNumber(0);
                        score = score + numSprites[i][j]->getNumber();
                        result = true;
                    }
                    break;
                }
            }
        }
    }
    return result;
}

bool GameWorld::moveDown()
{
    bool result = false;
    for (int i = 0; i < LINE_COUNT; i++) {
        for (int j = 0; j < LINE_COUNT; j++) {
            for (int jj = j + 1; jj < LINE_COUNT; jj++) {
                if (numSprites[i][jj]->getNumber() > 0) {
                    if (numSprites[i][j]->getNumber() <= 0) {
                        numSprites[i][j]->setNumber(numSprites[i][jj]->getNumber());
                        numSprites[i][jj]->setNumber(0);
                        score = score + numSprites[i][j]->getNumber();
                        j--;
                        result = true;
                    } else if (numSprites[i][jj]->getNumber() == numSprites[i][j]->getNumber()) {
                        numSprites[i][j]->setNumber(numSprites[i][j]->getNumber() * 2);
                        numSprites[i][jj]->setNumber(0);
                        score = score + numSprites[i][j]->getNumber();
                        result = true;
                    }
                    break;
                }
            }
        }
    }
    return result;
}

bool GameWorld::moveUp()
{
    bool result = false;
    for (int i = 0; i < LINE_COUNT; i++) {
        for (int j = LINE_COUNT - 1; j >= 0; j--) {
            for (int jj = j - 1; jj >= 0; jj--) {
                if (numSprites[i][jj]->getNumber() > 0) {
                    if (numSprites[i][j]->getNumber() <= 0) {
                        numSprites[i][j]->setNumber(numSprites[i][jj]->getNumber());
                        numSprites[i][jj]->setNumber(0);
                        j++;
                        score = score + numSprites[i][j]->getNumber();
                        result = true;
                    } else if (numSprites[i][jj]->getNumber() == numSprites[i][j]->getNumber()) {
                        numSprites[i][j]->setNumber(numSprites[i][j]->getNumber() * 2);
                        numSprites[i][jj]->setNumber(0);
                        score = score + numSprites[i][j]->getNumber();
                        result = true;
                    }
                    break;
                }
            }
        }
    }
    return result;
}

bool GameWorld::isGameOver()
{
    for (int i = 0; i < LINE_COUNT; i++) {
        for (int j = 0; j < LINE_COUNT; j++) {
            NumSprite* numSprite = numSprites[i][j];
            if (numSprite->getNumber() <= 0) {
                return false;
            } else if (i > 0 && numSprite->getNumber() == numSprites[i - 1][j]->getNumber()) {
                return false;
            } else if (j > 0 && numSprite->getNumber() == numSprites[i][j - 1]->getNumber()) {
                return false;
            }
        }
    }
    return true;
};
