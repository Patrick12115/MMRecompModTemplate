#include "modding.h"
#include "global.h"
#include "recomputils.h"
#include "recompconfig.h"
#include "z64extern.h"

RECOMP_HOOK("ObjSound_Init")
void MuteCarpenterSfx(Actor* thisx, PlayState* play) {
    ObjSound* this = (ObjSound*)thisx;

    if ((play->sceneId == SCENE_CLOCKTOWER || play->sceneId == SCENE_TOWN) &&
        (this->actor.params & OBJ_SOUND_ID_MASK) == 16) {
        Actor_Kill(thisx);
        return;
    }
}
