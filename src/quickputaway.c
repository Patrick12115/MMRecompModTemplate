#include "modding.h"
#include "global.h"
#include "recomputils.h"
#include "recompconfig.h"
#include "z64extern.h"

RECOMP_HOOK("Player_UpdateInterface")
void Quick_Putaway(PlayState* play, Player* this) {

    this->putAwayCooldownTimer = 0;
}

