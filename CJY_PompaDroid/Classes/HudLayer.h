//
//  HudLayer.h
//  CJY_PompaDroid
//
//  Created by CC on 14-1-28.
//
//

#ifndef __CJY_PompaDroid__HudLayer__
#define __CJY_PompaDroid__HudLayer__

#include <iostream>
#include "cocos2d.h"
#include "SimpleDPad.h"

class HudLayer : public cocos2d::CCLayer
{
public:
    
    HudLayer(void);
    
    CREATE_FUNC(HudLayer);
    bool init();
    CC_SYNTHESIZE(SimpleDPad*, _dPad, DPad);
};


#endif /* defined(__CJY_PompaDroid__HudLayer__) */
