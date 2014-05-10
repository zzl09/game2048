#include "MainMenuScene.h"
#include "MainMenuLayer.h"
USING_NS_CC;
Scene* MainMenuScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = MainMenuLayer::create();

    // add layer as a child to scene
    scene->addChild(layer);
    // return the scene
    return scene;
}


