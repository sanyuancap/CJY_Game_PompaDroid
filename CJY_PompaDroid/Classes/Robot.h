//
//  Robot.h
//  CJY_PompaDroid
//
//  Created by CC on 14-1-28.
//
//

#ifndef __CJY_PompaDroid__Robot__
#define __CJY_PompaDroid__Robot__

#include <iostream>
#include "cocos2d.h"
#include "ActionSprite.h"

class Robot : public ActionSprite
{
public:
    Robot();
    ~Robot();
    
    CREATE_FUNC(Robot);
    bool init();
    void knockout();
    
    CC_SYNTHESIZE(float, _nextDecisionTime, NextDecisionTime);
};

#endif /* defined(__CJY_PompaDroid__Robot__) */
