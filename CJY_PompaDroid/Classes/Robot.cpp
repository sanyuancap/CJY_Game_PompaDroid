//
//  Robot.cpp
//  CJY_PompaDroid
//
//  Created by CC on 14-1-28.
//
//

#include "Robot.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;

Robot::Robot(){

}
Robot::~Robot(){

}

bool Robot::init()
{
    bool bRet = false;
    do
    {
        CC_BREAK_IF(!ActionSprite::initWithSpriteFrameName("robot_idle_00.png"));
        
        int i;
        //idle animation
        CCArray *idleFrames = CCArray::createWithCapacity(5);
        for (i = 0; i < 5; i++)
        {
            CCSpriteFrame *frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(
                                                                                                   CCString::createWithFormat("robot_idle_%02d.png", i)->getCString());
            idleFrames->addObject(frame);
        }
        CCAnimation *idleAnimation = CCAnimation::createWithSpriteFrames(idleFrames, float(1.0 / 12.0));
        this->setIdleAction(CCRepeatForever::create(CCAnimate::create(idleAnimation)));
        
        //attack animation
        CCArray *attackFrames = CCArray::createWithCapacity(5);
        for (i = 0; i < 5; i++)
        {
            CCSpriteFrame *frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(
                                                                                                   CCString::createWithFormat("robot_attack_%02d.png", i)->getCString());
            attackFrames->addObject(frame);
        }
        CCAnimation *attackAnimation = CCAnimation::createWithSpriteFrames(attackFrames, float(1.0 / 24.0));
        this->setAttackAction(CCSequence::create(CCAnimate::create(attackAnimation), CCCallFunc::create(this, callfunc_selector(Robot::idle)), NULL));
        
        //walk animation
        CCArray *walkFrames = CCArray::createWithCapacity(6);
        for (i = 0; i < 6; i++)
        {
            CCSpriteFrame *frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(
                                                                                                   CCString::createWithFormat("robot_walk_%02d.png", i)->getCString());
            walkFrames->addObject(frame);
        }
        CCAnimation *walkAnimation = CCAnimation::createWithSpriteFrames(walkFrames, float(1.0 / 12.0));
        this->setWalkAction(CCRepeatForever::create(CCAnimate::create(walkAnimation)));
        
        //hurt animation
        CCArray *hurtFrames = CCArray::createWithCapacity(3);
        for (i = 0; i < 3; i++)
        {
            CCSpriteFrame *frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(CCString::createWithFormat("robot_hurt_%02d.png", i)->getCString());
            hurtFrames->addObject(frame);
        }
        CCAnimation *hurtAnimation = CCAnimation::createWithSpriteFrames(hurtFrames, float(1.0 / 12.0));
        this->setHurtAction(CCSequence::create(CCAnimate::create(hurtAnimation), CCCallFunc::create(this, callfunc_selector(Robot::idle)), NULL));
        
        //knocked out animation
        CCArray *knockedOutFrames = CCArray::createWithCapacity(5);
        for (i = 0; i < 5; i++)
        {
            CCSpriteFrame *frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(CCString::createWithFormat("robot_knockout_%02d.png", i)->getCString());
            knockedOutFrames->addObject(frame);
        }
        CCAnimation *knockedOutAnimation = CCAnimation::createWithSpriteFrames(knockedOutFrames, float(1.0 / 12.0));
        this->setKnockedOutAction(CCSequence::create(CCAnimate::create(knockedOutAnimation), CCBlink::create(2.0, 10.0), NULL));

        
        this->setWalkSpeed(80.0);
        this->setCenterToBottom(39.0);
        this->setCenterToSides(29.0);
        this->setHitPoints(100.0);
        this->setDamage(10.0);
        
            this->setHitbox(this->createBoundingBoxWithOrigin(ccp(-this->getCenterToSides(), -this->getCenterToBottom()),
                                                           CCSizeMake(this->getCenterToSides() * 2, this->getCenterToBottom() * 2)));
        this->setAttackBox(this->createBoundingBoxWithOrigin(ccp(this->getCenterToSides(), -5), CCSizeMake(25, 20)));

        _nextDecisionTime = 0;
        
        bRet = true;
    } while (0);
    
    return bRet;
}

void Robot::knockout()
{
    ActionSprite::knockout();
    CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("pd_botdeath.wav");
}













