//
//  GameLayer.h
//  CJY_PompaDroid
//
//  Created by CC on 14-1-28.
//
//

#ifndef __CJY_PompaDroid__GameLayer__
#define __CJY_PompaDroid__GameLayer__

#include <iostream>
#include "cocos2d.h"
#include "Hero.h"
#include "SimpleDPad.h"
#include "HudLayer.h"

class GameLayer : public cocos2d::CCLayer, public SimpleDPadDelegate
{
public:
    
    virtual void didChangeDirectionTo(SimpleDPad *simpleDPad, cocos2d::CCPoint direction);
    virtual void isHoldingDirection(SimpleDPad *simpleDPad, cocos2d::CCPoint direction);
    virtual void simpleDPadTouchEnded(SimpleDPad *simpleDPad);
    
    GameLayer();
    ~GameLayer();
    CREATE_FUNC(GameLayer);
    
    bool init();
    void initTileMap();
    void initHero();
    void initRobots();
    void update(float dt);
    void updatePositions();
    void updateRobots(float dt);
    void setViewpointCenter(cocos2d::CCPoint position);
    void reorderActors();
    void endGame();
    void restartGame(cocos2d::CCObject* pSender);
    
    
    
    virtual void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
    
    
    cocos2d::CCTMXTiledMap *_tileMap;
    cocos2d::CCSpriteBatchNode *_actor;
    Hero *_hero;
    CC_SYNTHESIZE(HudLayer*, _hud, Hud);
    CC_SYNTHESIZE_RETAIN(cocos2d::CCArray*, _robots, Robots);
};

#endif /* defined(__CJY_PompaDroid__GameLayer__) */
