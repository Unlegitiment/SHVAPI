#include "script.h"
#include "keyboard.h"
#include "Markers.h"
#include "UI.h"
#include "Scaleform.h"
#include <string>
#include <ctime>
void main();
#pragma warning(disable : 4244 4305) // double <-> float conversions

float square(float num) { return num * num; }
float distanceTo(Vector3 vec1, Vector3 vec2) {
    float xsub, ysub, zsub;
    xsub = vec2.x - vec1.x;
    ysub = vec2.y - vec1.y;
    zsub = vec2.z - vec1.z;
    float xsq, ysq, zsq;
    xsq = square(xsub);
    ysq = square(ysub);
    zsq = square(zsub);
    float tot = xsq + ysq + zsq;
    return (float)sqrt(tot);
}
float distanceTo(float x1, float y1, float z1, float x2,float y2, float z2) {
    float xsub, ysub, zsub;
    xsub = x2 - x1;
    ysub = y2 - y1;
    zsub = z2 - z1;
    float xsq, ysq, zsq;
    xsq = square(xsub);
    ysq = square(ysub);
    zsq = square(zsub);
    float tot = xsq + ysq + zsq;
    return (float)sqrt(tot);
}
float distanceTo(Vector3 vec1) {
    Vector3 vec2 = { 0,0,0 };
    float xsub, ysub, zsub;
    xsub = vec2.x - vec1.x;
    ysub = vec2.y - vec1.y;
    zsub = vec2.z - vec1.z;
    float xsq, ysq, zsq;
    xsq = square(xsub);
    ysq = square(ysub);
    zsq = square(zsub);
    float tot = xsq + ysq + zsq;
    return (float)sqrt(tot);
}
void DisableEclipse() {
    while (true) {
            HUD::THEFEED_FLUSH_QUEUE();
        
        GRAPHICS::SET_DISABLE_DECAL_RENDERING_THIS_FRAME();
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ss1_11_flats"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ss1_11_ss1_emissive_a"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ss1_11_detail01b"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ss1_11_Flats_LOD"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("SS1_02_Building01_LOD"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("SS1_LOD_01_02_08_09_10_11"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("SS1_02_SLOD1"));
        GRAPHICS::DISABLE_OCCLUSION_THIS_FRAME();
        GRAPHICS::SET_SCRIPT_GFX_DRAW_ORDER(1);
        UI_DRAWBOX(rgb_Create(0, 0, 0, 255), { 0.1F,0UL, 0.513F, 0UL }, 0.01F, 0.039F);
        GRAPHICS::SET_SCRIPT_GFX_DRAW_ORDER(2);
        UI_DrawText("TRUE", {0.1f, 0UL, 0.5F, 0UL});

        /*Thread Controller For Adding back that side of the building and transfering ownership of the program to that thread.*/
        if (IsKeyJustUp(VK_DIVIDE)) {
            UI_DrawNotificationSTR("FALSE");
            main();
        }
        WAIT(0);
    }
}
typedef enum {
    RGBA_R, RGBA_G, RGBA_B, RGBA_A
}RGBA_MOD_TYPE;
void RGBA_Mod(RGBA_t* ptr, RGBA_MOD_TYPE valToMod, float val) {
    switch (valToMod) {
    case RGBA_R:
        ptr->r = val;
        break;
    case RGBA_B:
        ptr->b = val;
        break;
    case RGBA_A: 
        ptr->a = val;
        break;
    case RGBA_G:
        ptr->g = val;
            break;
    }
    return;
}
void DisableAllApartments() {
    HUD::THEFEED_FLUSH_QUEUE();
    Vector2_t vec = { 0.15F, 0UL, 0.1F, 0UL };
    RGBA_t b_RGBA = rgb_Create(0, 0, 0, 255);
    while (true) {
        GRAPHICS::SET_DISABLE_DECAL_RENDERING_THIS_FRAME();
        /*Eclipse*/
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ss1_11_flats"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ss1_11_ss1_emissive_a"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ss1_11_detail01b"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ss1_11_Flats_LOD"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("SS1_02_Building01_LOD"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("SS1_LOD_01_02_08_09_10_11"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("SS1_02_SLOD1"));
        /*Alta*/
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("hei_dt1_20_build2"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("dt1_20_dt1_emissive_dt1_20"));
        /*Weazel*/
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("bh1_09_ema"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("hei_bh1_09_bld_01"));
        /*Del Parro*/
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("hei_sm_14_bld2"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("sm_14_emissive"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("prop_wall_light_12a"));
        /*Pillbox Hill*/
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("hei_dt1_03_build1x"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("DT1_Emissive_DT1_03_b1"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("dt1_03_dt1_Emissive_b1"));
        //Richard
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("hei_bh1_08_bld2"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("bh1_emissive_bh1_08"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("bh1_08_bld2_LOD"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("hei_bh1_08_bld2"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("bh1_08_em"));
        /*Tinsel*/
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ss1_02_building01"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("SS1_Emissive_SS1_02a_LOD"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ss1_02_ss1_emissive_ss1_02"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ss1_02_building01"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("SS1_02_Building01_LOD"));
        //STILT
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_05e_res5"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_05e_res5_LOD"));
        /*Stilt*/
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_04_house02"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_04_house02_d"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_04_M_a_LOD"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ch2_04_house02_railings"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ch2_04_emissive_04"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ch2_04_emissive_04_LOD"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_04_house02_details"));
        /*Stilt*/
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_09b_hs01a_details"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_09b_hs01"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_09b_hs01_balcony"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_09b_Emissive_11_LOD"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_09b_Emissive_11"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_CH2_09b_House08_LOD"));
        /*Stilt*/
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_09c_hs11"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("CH2_09c_Emissive_11_LOD"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("CH2_09c_Emissive_11"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_09c_hs11_details"));
        /*Stilt*/
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_05c_b4"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ch2_05c_decals_05"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ch2_05c_B4_LOD"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ch2_05c_emissive_07"));
        /*Stilt*/
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_09c_hs07"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ch2_09c_build_11_07_LOD"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("CH2_09c_Emissive_07_LOD"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_09c_build_11_07_LOD"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ch2_09c_hs07_details"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("CH2_09c_Emissive_07"));
        /*Stilt*/
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_09c_hs13"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_09c_hs13_details"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_CH2_09c_House11_LOD"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ch2_09c_Emissive_13_LOD"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ch2_09c_Emissive_13"));
        /*Stilt*/
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_09b_hs02"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_09b_hs02b_details"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_09b_Emissive_09_LOD"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ch2_09b_botpoolHouse02_LOD"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_09b_Emissive_09"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_09b_hs02_balcony"));
        /*Stilt*/
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_12b_house03mc"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ch2_12b_emissive_02"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ch2_12b_house03_MC_a_LOD"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ch2_12b_emissive_02_LOD"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ch2_12b_railing_06"));
        //STILT
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_04_house01"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_04_house01_d"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ch2_04_emissive_05_LOD"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_04_M_b_LOD"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ch2_04_emissive_05"));
        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ch2_04_house01_details"));

        GRAPHICS::DISABLE_OCCLUSION_THIS_FRAME();

        GRAPHICS::SET_SCRIPT_GFX_DRAW_ORDER(1); 
        UI_DRAWBOX(b_RGBA, { vec.x,vec._paddingX_, vec.y + 0.021F, vec._paddingY_}, 0.2, 0.044);
        GRAPHICS::SET_SCRIPT_GFX_DRAW_ORDER(2);
        UI_DrawText("ALL APARTMENTS CUT", vec);
        /*Thread Controller For Adding back that side of the building and transfering ownership of the program to that thread.*/
        if (IsKeyJustUp(VK_ADD)) {
            if (b_RGBA.r == 255 && b_RGBA.b == 255 && b_RGBA.g == 255) {
                RGBA_Mod(&b_RGBA, RGBA_R, 0);
                RGBA_Mod(&b_RGBA, RGBA_B, 0);
                RGBA_Mod(&b_RGBA, RGBA_G, 0);
            }
            else {
                RGBA_Mod(&b_RGBA, RGBA_R, 255);
                RGBA_Mod(&b_RGBA, RGBA_B, 255);
                RGBA_Mod(&b_RGBA, RGBA_G, 255);
            }
        }
        if (IsKeyJustUp(VK_DIVIDE)) {
            int startTime = MISC::GET_GAME_TIMER();
            int endTime = startTime + 2500;
            while (MISC::GET_GAME_TIMER() < endTime) {
                GRAPHICS::SET_SCRIPT_GFX_DRAW_ORDER(1);
                UI_DRAWBOX(b_RGBA, { vec.x,vec._paddingX_, vec.y + 0.021F, vec._paddingY_ }, 0.22, 0.044);
                if(IsKeyJustUp(VK_DIVIDE)){
                    DisableAllApartments();
                }
                GRAPHICS::SET_SCRIPT_GFX_DRAW_ORDER(2);
                UI_DrawText("ALL APARTMENTS ADDED", vec);
                WAIT(0);
            }
            main();
        }
        WAIT(0);
    }

}
#define CHARZ "CHAR_ALL_PLAYERS_CONF"
void main()
{
    // Ticks. 
    while (true)
    {
       if (IsKeyJustUp(VK_DIVIDE)) {   
           /*
           * StartRep = CurrentRepLocation
           * CurrentRank = the Rank You're Currently on
           * NextRank can be really anything you want both can however ideally it'd be CurrentRank+1
           * rpToNext = the nessicary rp to the next rank
           * minNext = if minNext > maxNext rpBar fills completely; if minNext < maxNext completely empty. if minNext == startRep+rpGain 1 bar gets filled
           * minNext is Better put as a 0. Because this reveals the animation and makes it more seemless.
           * maxNext = Represents the Maximum amount the bar can represent. It will trigger an animation extension if it goes past it.
           */
           DLC::ON_ENTER_MP();
           DisableAllApartments();
       }

        WAIT(0);
    }
}

void ScriptMain()
{
    srand(GetTickCount());
    main();
}

