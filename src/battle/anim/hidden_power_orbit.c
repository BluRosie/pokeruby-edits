#include "global.h"
#include "rom_8077ABC.h"
#include "trig.h"
#include "battle_anim.h"
#include "sound.h"

extern s16 gBattleAnimArgs[];
extern u8 gBattleAnimAttacker;
extern u8 gBattleAnimTarget;

void AnimOrbitFast(struct Sprite* sprite);
void AnimOrbitFastTarget(struct Sprite* sprite);
void AnimOrbitScatter(struct Sprite* sprite);
void AnimPulseScatter(struct Sprite* sprite);
void AnimJudgmentScatter(struct Sprite* sprite);
static void AnimOrbitFastStep(struct Sprite* sprite);
static void AnimPulseScatterStep(struct Sprite* sprite);
static void AnimOrbitScatterStep(struct Sprite* sprite);
static void AnimJudgmentScatterStep(struct Sprite* sprite);

const union AffineAnimCmd gSpriteAffineAnim_83D7AF8[] =
{
    AFFINEANIMCMD_FRAME(0x80, 0x80, 0, 0),
    AFFINEANIMCMD_FRAME(0x8, 0x8, 0, 1),
    AFFINEANIMCMD_JUMP(1),
};

const union AffineAnimCmd *const gSpriteAffineAnimTable_83D7B10[] =
{
    gSpriteAffineAnim_83D7AF8,
};

const struct SpriteTemplate gHiddenPowerOrbSpriteTemplate =
{
    .tileTag = ANIM_TAG_RED_ORB,
    .paletteTag = ANIM_TAG_RED_ORB,
    .oam = &gOamData_837DF8C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gSpriteAffineAnimTable_83D7B10,
    .callback = AnimOrbitFast,
};

const struct SpriteTemplate gHiddenPowerOrbTargetSpriteTemplate =
{
    .tileTag = ANIM_TAG_RED_ORB,
    .paletteTag = ANIM_TAG_RED_ORB,
    .oam = &gOamData_837DF8C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gSpriteAffineAnimTable_83D7B10,
    .callback = AnimOrbitFastTarget,
};

const struct SpriteTemplate gHiddenPowerOrbScatterSpriteTemplate =
{
    .tileTag = ANIM_TAG_RED_ORB,
    .paletteTag = ANIM_TAG_RED_ORB,
    .oam = &gOamData_837DFEC,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gSpriteAffineAnimTable_83D7B10,
    .callback = AnimOrbitScatter,
};

extern const struct OamData gOamData_AffineDouble_ObjBlend_32x16;

const struct SpriteTemplate gDarkPulseScatterSpriteTemplate =
{
    .tileTag = ANIM_TAG_POISON_JAB,
    .paletteTag = ANIM_TAG_POISON_JAB,
    .oam = &gOamData_AffineDouble_ObjBlend_32x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimPulseScatter,
};

const struct SpriteTemplate gJudgmentScatterSpriteTemplate =
{
    .tileTag = ANIM_TAG_POISON_JAB,
    .paletteTag = ANIM_TAG_POISON_JAB,
    .oam = &gOamData_AffineDouble_ObjBlend_32x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimJudgmentScatter,
};

// Orbits a sphere in an ellipse around the mon.
// Used by MOVE_HIDDEN_POWER
// arg 0: duration
// arg 1: initial wave offset
void AnimOrbitFast(struct Sprite* sprite)
{
    sprite->pos1.x = GetBattlerSpriteCoord(gBattleAnimAttacker, 2);
    sprite->pos1.y = GetBattlerSpriteCoord(gBattleAnimAttacker, 3);
    sprite->affineAnimPaused = 1;
    sprite->data[0] = gBattleAnimArgs[0];
    sprite->data[1] = gBattleAnimArgs[1];
    sprite->data[7] = GetBattlerSubpriority(gBattleAnimAttacker);
    sprite->callback = AnimOrbitFastStep;
    sprite->callback(sprite);
}

void AnimOrbitFastTarget(struct Sprite* sprite)
{
    sprite->pos1.x = GetBattlerSpriteCoord(gBattleAnimTarget, 2);
    sprite->pos1.y = GetBattlerSpriteCoord(gBattleAnimTarget, 3);
    sprite->affineAnimPaused = 1;
    sprite->data[0] = gBattleAnimArgs[0];
    sprite->data[1] = gBattleAnimArgs[1];
    sprite->data[7] = GetBattlerSubpriority(gBattleAnimTarget);
    sprite->callback = AnimOrbitFastStep;
    sprite->callback(sprite);
}

static void AnimOrbitFastStep(struct Sprite* sprite)
{
    if ((u16)(sprite->data[1] - 0x40) <= 0x7F)
        sprite->subpriority = sprite->data[7] + 1;
    else
        sprite->subpriority = sprite->data[7] - 1;

    sprite->pos2.x = Sin(sprite->data[1], sprite->data[2] >> 8);
    sprite->pos2.y = Cos(sprite->data[1], sprite->data[3] >> 8);
    sprite->data[1] = (sprite->data[1] + 9) & 0xFF;
    switch (sprite->data[5])
    {
    case 1:
        sprite->data[2] -= 0x400;
        sprite->data[3] -= 0x100;
        if (++sprite->data[4] == sprite->data[0])
        {
            sprite->data[5] = 2;
            return;
        }
        break;
    case 0:
        sprite->data[2] += 0x400;
        sprite->data[3] += 0x100;
        if (++sprite->data[4] == sprite->data[0])
        {
            sprite->data[4] = 0;
            sprite->data[5] = 1;
        }
        break;
    }

    if ((u16)gBattleAnimArgs[7] == 0xFFFF)
        DestroyAnimSprite(sprite);
}

// Moves orbs away from the mon, based on where they are in their orbit.
// Used in MOVE_HIDDEN_POWER.
// arg 0: initial wave offset
void AnimOrbitScatter(struct Sprite* sprite)
{
    sprite->pos1.x = GetBattlerSpriteCoord(gBattleAnimAttacker, 2);
    sprite->pos1.y = GetBattlerSpriteCoord(gBattleAnimAttacker, 3);
    sprite->data[0] = Sin(gBattleAnimArgs[0], 10);
    sprite->data[1] = Cos(gBattleAnimArgs[0], 7);
    sprite->callback = AnimOrbitScatterStep;
}

// Moves pulses away from the mon while setting rotscale based on where they are in their orbit and slowing down the particle.
// Used in MOVE_DARK_PULSE.
// arg 0: initial wave offset
void AnimPulseScatter(struct Sprite* sprite)
{
    sprite->pos1.x = GetBattlerSpriteCoord(gBattleAnimAttacker, 2);
    sprite->pos1.y = GetBattlerSpriteCoord(gBattleAnimAttacker, 3);
    sprite->data[0] = Sin(gBattleAnimArgs[0], 10);
    sprite->data[1] = Cos(gBattleAnimArgs[0], 7);
    sprite->data[4] = 3;
    sprite->callback = AnimPulseScatterStep;
}

// Moves pulses away from the mon while setting rotscale based on where they are in their orbit and slowing down the particle.
// Used in MOVE_DARK_PULSE.
// arg 0: initial wave offset
void AnimJudgmentScatter(struct Sprite* sprite)
{
    sprite->pos1.x = GetBattlerSpriteCoord(gBattleAnimAttacker, 2);
    sprite->pos1.y = GetBattlerSpriteCoord(gBattleAnimAttacker, 3);
    sprite->data[0] = Sin(gBattleAnimArgs[0], 10);
    sprite->data[1] = Cos(gBattleAnimArgs[0], 7);
    sprite->callback = AnimJudgmentScatterStep;
}

static void AnimOrbitScatterStep(struct Sprite* sprite)
{
    sprite->pos2.x += sprite->data[0];
    sprite->pos2.y += sprite->data[1];

    if (sprite->pos1.x + sprite->pos2.x + 16 > 0x110u || sprite->pos1.y + sprite->pos2.y > 0xA0 || sprite->pos1.y + sprite->pos2.y < -16)
        DestroyAnimSprite(sprite);
}

static void AnimPulseScatterStep(struct Sprite* sprite)
{
    u16 rotation;
    sprite->pos2.x += sprite->data[0] / (sprite->data[4] / 3);
    sprite->pos2.y += sprite->data[1] / (sprite->data[4] / 3);

    rotation = ArcTan2Neg(sprite->data[0], sprite->data[1]);
    TrySetSpriteRotScale(sprite, FALSE, 0x100, 0x100, rotation);

    if (sprite->pos1.x + sprite->pos2.x + 16 > 0x110u 
     || sprite->pos1.y + sprite->pos2.y > 0xA0 
     || sprite->pos1.y + sprite->pos2.y < -16
     || sprite->data[0] / (sprite->data[4] / 3) == 0)
        DestroyAnimSprite(sprite);
    else
        sprite->data[4]++;
}

static void AnimJudgmentScatterStep(struct Sprite* sprite)
{
    u16 rotation;
    sprite->pos2.x += sprite->data[0];
    sprite->pos2.y += sprite->data[1];

    rotation = ArcTan2Neg(sprite->data[0], sprite->data[1]);
    TrySetSpriteRotScale(sprite, FALSE, 0x100, 0x100, rotation);

    if (sprite->pos1.x + sprite->pos2.x + 16 > 0x110u 
     || sprite->pos1.y + sprite->pos2.y > 0xA0 
     || sprite->pos1.y + sprite->pos2.y < -16)
        DestroyAnimSprite(sprite);
}
