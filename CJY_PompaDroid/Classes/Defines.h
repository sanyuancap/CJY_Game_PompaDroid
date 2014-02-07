//
//  Defines.h
//  CJY_PompaDroid
//
//  Created by CC on 14-1-28.
//
//

#ifndef CJY_PompaDroid_Defines_h
#define CJY_PompaDroid_Defines_h
#include "cocos2d.h"

// 1 - convenience measurements
#define SCREEN CCDirector::sharedDirector()->getWinSize()
#define CENTER ccp(SCREEN.width / 2, SCREEN.height / 2)
#define CURTIME GetCurTime()

// 2 - convenience functions
#ifndef UINT64_C
#define UINT64_C(val) val##ui64
#endif
#define random_range(low, high) (rand() % (high - low + 1)) + low
#define frandom (float)rand() / UINT64_C(0x100000000)
#define frandom_range(low, high) ((high - low) * frandom) + low

// 3 - enumerations
typedef enum _ActionState {
    kActionStateNone = 0,
    kActionStateIdle,
    kActionStateAttack,
    kActionStateWalk,
    kActionStateHurt,
    kActionStateKnockedOut
} ActionState;

// 4 - structures
typedef struct _BoundingBox {
    cocos2d::CCRect actual;
    cocos2d::CCRect original;
} BoundingBox;

inline float GetCurTime(){
    timeval time;
    gettimeofday(&time, NULL);
    unsigned long millisecs = (time.tv_sec * 1000) + (time.tv_usec / 1000);
    return (float)millisecs;
};
#endif
