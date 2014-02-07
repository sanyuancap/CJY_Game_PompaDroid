//
//  Hero.h
//  CJY_PompaDroid
//
//  Created by CC on 14-1-28.
//
//

#ifndef __CJY_PompaDroid__Hero__
#define __CJY_PompaDroid__Hero__

#include <iostream>
#include "cocos2d.h"
#include "ActionSprite.h"

class Hero : public ActionSprite
{
public:
    Hero();
    ~Hero();
    
    void knockout();
    
    CREATE_FUNC(Hero);
    bool init();
};

#endif /* defined(__CJY_PompaDroid__Hero__) */
