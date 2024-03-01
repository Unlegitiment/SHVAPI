#include "PlayerList.h"
#include "../ScriptHookV/natives.h"
void DrawTriangle(float x1, float y1, float x2, float y2, float x3, float y3, int r, int g, int b, int alpha) {
    int x = GRAPHICS::REQUEST_SCALEFORM_MOVIE("MP_CREW_TAG");
    while (!GRAPHICS::HAS_SCALEFORM_MOVIE_LOADED(x)) {
        WAIT(0);
    }
    //GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(x, "SET_CREW_TAG");
    //GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_BOOL(0); //should draw the triangle but it doesn't :
    //GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_BOOL(1); //rsg logo
    //GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING("RSG");
    //GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_INT(1);
    //GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
    GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(x, "debug");
    GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("mparrow",1);
    while (!GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("mparrow")) {
        WAIT(0);
    }
    GRAPHICS::DRAW_SPRITE("mparrow", "mp_arrowxlarge", 0.757453f, 0.759722f, 0.125, 0.225, 180, 0, 0, 0, 255, 1, 1);
    GRAPHICS::DRAW_SPRITE("mparrow", "mp_arrowxlarge", 0.754453f, 0.759722f, 0.1, 0.2, 180, 255, 255, 255, 255, 1, 1);
    GRAPHICS::DRAW_SCALEFORM_MOVIE(x, 1, 0.75, 0.446, 0.25, 255, 255, 255, 255, 0);
    //GRAPHICS::SET_STREAMED_TEXTURE_DICT_AS_NO_LONGER_NEEDED("mparrow");
    //GRAPHICS::SET_SCALEFORM_MOVIE_AS_NO_LONGER_NEEDED(&x);
}
#include "../UIEditor/BoxDraw/CBoxUI.h"
void ClanTag::Draw(float scaleF) {
    if (m_BIsActive) {
        CBox b = CBox(CVector2(0.5, 0.5), CRGBA(0, 0, 0, 180), 2 * scaleF, 2 * (1.24 * scaleF));
        b.Draw();
        b.ShowDebugInfo(0.1, 17);
    }
}
