//
//  ActionSprite.h
//  CJY_PompaDroid
//
//  Created by CC on 14-1-28.
//
//

#ifndef __CJY_PompaDroid__ActionSprite__
#define __CJY_PompaDroid__ActionSprite__

#include <iostream>
#include "cocos2d.h"
#include "Defines.h"

class ActionSprite : public cocos2d::CCSprite
{
public:
    ActionSprite(void);
    ~ActionSprite(void);
    
    //action methods
    void idle();
    void attack();
    void hurtWithDamage(float damage);
    virtual void knockout();
    void walkWithDirection(cocos2d::CCPoint direction);
    BoundingBox createBoundingBoxWithOrigin(cocos2d::CCPoint origin, cocos2d::CCSize size);
    void transformBoxes();
    void setPosition(cocos2d::CCPoint position);
    
    
    //scheduled methods
    void update(float dt);
    
    //actions
    CC_SYNTHESIZE_RETAIN(cocos2d::CCAction*, _idleAction, IdleAction);
    CC_SYNTHESIZE_RETAIN(cocos2d::CCAction*, _attackAction, AttackAction);
    CC_SYNTHESIZE_RETAIN(cocos2d::CCAction*, _walkAction, WalkAction);
    CC_SYNTHESIZE_RETAIN(cocos2d::CCAction*, _hurtAction, HurtAction);
    CC_SYNTHESIZE_RETAIN(cocos2d::CCAction*, _knockedOutAction, KnockedOutAction);
    
    //states
    CC_SYNTHESIZE(ActionState, _actionState, ActionState);
    
    //attributes
    CC_SYNTHESIZE(float, _walkSpeed, WalkSpeed);
    CC_SYNTHESIZE(float, _hitPoints, HitPoints);
    CC_SYNTHESIZE(float, _damage, Damage);
    
    //movement
    CC_SYNTHESIZE(cocos2d::CCPoint, _velocity, Velocity);
    CC_SYNTHESIZE(cocos2d::CCPoint, _desiredPosition, DesiredPosition);
    
    //measurements
    CC_SYNTHESIZE(float, _centerToSides, CenterToSides);
    CC_SYNTHESIZE(float, _centerToBottom, CenterToBottom);
    
    //碰撞检测
    CC_SYNTHESIZE(BoundingBox, _hitBox, Hitbox);
    CC_SYNTHESIZE(BoundingBox, _attackBox, AttackBox);
    
};

#endif /* defined(__CJY_PompaDroid__ActionSprite__) */
