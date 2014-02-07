//
//  GameScene.h
//  CJY_PompaDroid
//
//  Created by CC on 14-1-28.
//
//

#ifndef __CJY_PompaDroid__GameScene__
#define __CJY_PompaDroid__GameScene__

#include <iostream>
#include "cocos2d.h"
#include "GameLayer.h"
#include "HudLayer.h"

class GameScene : public cocos2d::CCScene
{
public:
    GameScene(void);
    ~GameScene(void);
    
    virtual bool init();
    CREATE_FUNC(GameScene);
    
    CC_SYNTHESIZE(GameLayer*, _gameLayer, GameLayer);
    CC_SYNTHESIZE(HudLayer*, _hudLayer, HudLayer);
};




#endif /* defined(__CJY_PompaDroid__GameScene__) */
