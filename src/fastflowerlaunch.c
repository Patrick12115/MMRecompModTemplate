#include "modding.h"
#include "global.h"
#include "recomputils.h"
#include "recompconfig.h"
#include "z64extern.h"

RECOMP_HOOK("Player_Action_93")
void FastDekuFlowerLaunch_Player_Action_93(Player* this, PlayState* play) {

    DynaPolyActor* dyna;
    Input* input = &play->state.input[0];

    if (this->av1.actionVar1 != 0 && !(this->av1.actionVar1 == 1 && this->unk_B48 > -170.0f) &&
        this->av2.actionVar2 != 10 && !CHECK_BTN_ALL(input->cur.button, BTN_A)) {
        this->unk_ABC = -3900.0f;
        this->unk_B48 = -170.0f;
        this->av1.actionVar1 = 2;
        this->av2.actionVar2 = 10;
        this->actor.scale.y = 0.01f;
        dyna = DynaPoly_GetActor(&play->colCtx, this->actor.floorBgId);

        if (dyna != NULL) {
            this->actor.world.pos.x = dyna->actor.world.pos.x;
            this->actor.world.pos.z = dyna->actor.world.pos.z;
        }
    }
}

