#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = LabelTTF::create("Hello Beatrobo!", "Arial", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);
    
    // add robot
    auto robotSprite = Sprite::create();
    robotSprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(robotSprite, 0);
    
    auto leftLegSprite = Sprite::create("hide_leg.png");
    leftLegSprite->setPosition(Vec2(5, leftLegSprite->getContentSize().height/2 + 0));
    robotSprite->addChild(leftLegSprite, 1);
    
    auto rightLegSprite = Sprite::create("hide_leg.png");
    rightLegSprite->setPosition(Vec2(-5, rightLegSprite->getContentSize().height/2 + 0));
    robotSprite->addChild(rightLegSprite, 1);
    
    auto bodySprite = Sprite::create("hide_body.png");
    bodySprite->setPosition(Vec2(0, bodySprite->getContentSize().height/2 + 16));
    robotSprite->addChild(bodySprite, 3);
    
    auto leftArmSprite = Sprite::create("hide_arm.png");
    leftArmSprite->setPosition(Vec2(17, leftArmSprite->getContentSize().height/2 + 6));
    robotSprite->addChild(leftArmSprite, 4);
    
    auto rightArmSprite = Sprite::create("hide_arm.png");
    rightArmSprite->setPosition(Vec2(-17, rightArmSprite->getContentSize().height/2 + 6));
    robotSprite->addChild(rightArmSprite, 4);
    
    auto headSprite = Sprite::create("hide_head.png");
    headSprite->setPosition(Vec2(0, headSprite->getContentSize().height/2 + 50));
    robotSprite->addChild(headSprite, 6);
    
    auto leftHeadphoneSprite = Sprite::create("headphone_left.png");
    leftHeadphoneSprite->setPosition(Vec2(30, leftHeadphoneSprite->getContentSize().height/2 + 55));
    robotSprite->addChild(leftHeadphoneSprite, 5);
    
    auto rightHeadphoneSprite = Sprite::create("headphone_right.png");
    rightHeadphoneSprite->setPosition(Vec2(-15, rightHeadphoneSprite->getContentSize().height/2 + 55));
    robotSprite->addChild(rightHeadphoneSprite, 7);
    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
