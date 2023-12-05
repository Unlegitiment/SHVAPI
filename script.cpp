#include "script.h"
#include "keyboard.h"
#include "Markers.h"
#include "UI.h"
#include "Scaleform.h"
#include "Menu.h"
#include <string>
#include <ctime>


void main();
void THREAD_2();
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
void flashColour(RGBA_t* colour) {
    RGBA_t* temp = colour;
    
    *colour = { 255,255,255,255 };
    WAIT(0);
    colour = temp;
    return;
}
void disable() {
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
}

void DisableDelPerro() {
    DLC::ON_ENTER_MP();
    HUD::THEFEED_FLUSH_QUEUE();
    Vector2_t vec = { 0.55F, 0UL, 0.5F, 0UL };
    RGBA_t b_RGBA = rgb_Create(0, 0, 0, 255);
    static BOOL toggle = FALSE;

    for (int i = 0; i < MISC::GET_GAME_TIMER(); i++) {
        if (IsKeyJustUp(VK_ADD)) {
            toggle = TRUE;
        }
        if (toggle == FALSE) { return; }
        disable();
        GRAPHICS::SET_SCRIPT_GFX_DRAW_ORDER(1);
        box_Draw(box_Create(rgb_Create(255, 0, 0, 255), {vec.x, 0UL, vec.y+0.019F , 0UL}, 0.0512F, 0.09F));
        GRAPHICS::SET_SCRIPT_GFX_DRAW_ORDER(2);
        t_Draw(t_Create("Del Perro Removed", 0, { vec.x, 0UL, vec.y + 0.019F, 0UL }, { 0,0,0,255 }, 0.513, FALSE, TRUE, TRUE));
        /*Thread Controller For Adding back that side of the building and transfering ownership of the program to that thread.*/
        if (IsKeyJustUp(VK_ADD)) {
            int startTime = MISC::GET_GAME_TIMER();
            int endTime = startTime + 2500;
            while (MISC::GET_GAME_TIMER() < endTime) {
                if (IsKeyJustUp(VK_ADD)) {
                    toggle = TRUE;
                    DisableDelPerro();
                }
                GRAPHICS::SET_SCRIPT_GFX_DRAW_ORDER(1);
                box_Draw(box_Create(rgb_Create(255, 0, 0, 255), vec, 0.0512F, 0.09F));
                GRAPHICS::SET_SCRIPT_GFX_DRAW_ORDER(2);
                t_Draw(t_Create("NULL", 0, { vec.x, 0UL, vec.y, 0UL }, { 0,0,0,255 }, 0.513, FALSE, TRUE, TRUE));
                WAIT(0);
            }
            THREAD_2();
        }
        WAIT(0);
    }
    
}

BOOL DisableAllApartments(BOOL zxd) {
    DLC::ON_ENTER_MP();
    HUD::THEFEED_FLUSH_QUEUE();
    Vector2_t vec = { 0.55F, 0UL, 0.5F, 0UL };
    RGBA_t b_RGBA = rgb_Create(0, 0, 0, 255);

    for (int i = 0; i < MISC::GET_GAME_TIMER(); i++) {
        if (zxd != FALSE) {
            disable();
            GRAPHICS::SET_SCRIPT_GFX_DRAW_ORDER(1);
            box_Draw(box_Create(rgb_Create(255, 0, 0, 255), vec, 0.0512F, 0.09F));
            GRAPHICS::SET_SCRIPT_GFX_DRAW_ORDER(2);
            t_Draw(t_Create("All Apartments Cleansed.", 0, { vec.x, 0UL, vec.y, 0UL }, { 0,0,0,255 }, 0.513, FALSE, TRUE, TRUE));

            /*Thread Controller For Adding back that side of the building and transfering ownership of the program to that thread.*/
            if (IsKeyJustUp(VK_DIVIDE)) {
                int startTime = MISC::GET_GAME_TIMER();
                int endTime = startTime + 2500;
                zxd = FALSE;
                while (MISC::GET_GAME_TIMER() < endTime) {
                    if (IsKeyJustUp(VK_DIVIDE)) {
                        zxd = TRUE;
                        DisableAllApartments(zxd);
                    }
                    GRAPHICS::SET_SCRIPT_GFX_DRAW_ORDER(1);
                    box_Draw(box_Create(rgb_Create(255, 0, 0, 255), vec, 0.0512F, 0.09F));
                    GRAPHICS::SET_SCRIPT_GFX_DRAW_ORDER(2);
                    t_Draw(t_Create("NULL", 0, { vec.x, 0UL, vec.y, 0UL }, { 0,0,0,255 }, 0.513, FALSE, TRUE, TRUE));
                }
                
                THREAD_2();
            }
        }
        return zxd;
        WAIT(0);
    }
    return NULL;
}
BOOL_t isPointInsideBox( float x, float y, BoxUI* box) {
    // Check if the point's x-coordinate is within the box's x-range
    if (x >= box->topLeft.x && x <= box->bottomRight.x) {
        // Check if the point's y-coordinate is within the box's y-range
        if (y >= box->topLeft.y && y <= box->bottomRight.y) {
            // The point is inside the box
            return TRUE;
        }
    }
    return FALSE;
}

/*
* StartRep = CurrentRepLocation
* CurrentRank = the Rank You're Currently on
* NextRank can be really anything you want both can however ideally it'd be CurrentRank+1
* rpToNext = the nessicary rp to the next rank
* minNext = if minNext > maxNext rpBar fills completely; if minNext < maxNext completely empty. if minNext == startRep+rpGain 1 bar gets filled
* minNext is Better put as a 0. Because this reveals the animation and makes it more seemless.
* maxNext = Represents the Maximum amount the bar can represent. It will trigger an animation extension if it goes past it.
*/


#define CHARZ "CHAR_ALL_PLAYERS_CONF"
void updateBox(BoxUI* box, Vector2_t newPosition, float height, float width) {
    box->drawPos = newPosition;

    box->width = width;
    box->height = height;

    box->topLeft.x = box->drawPos.x - (box->width / 2.0F);
    box->topLeft.y = box->drawPos.y - (box->height / 2.0F);

    box->bottomLeft.x = box->topLeft.x;
    box->bottomLeft.y = box->topLeft.y + box->height;

    box->topRight.x = box->topLeft.x + box->width;
    box->topRight.y = box->topLeft.y;

    box->bottomRight.x = box->topRight.x;
    box->bottomRight.y = box->topRight.y + box->height;
    return;
}
void nullFunc() {
    HUD::THEFEED_FLUSH_QUEUE();
    HUD::BEGIN_TEXT_COMMAND_THEFEED_POST("STRING");
    HUD::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("~r~Unimplemented Item!");
    HUD::END_TEXT_COMMAND_THEFEED_POST_TICKER(TRUE, FALSE);
    return;
}
void menuAction() {
    STREAMING::REQUEST_MODEL(MISC::GET_HASH_KEY("ADDER"));
    VEHICLE::CREATE_VEHICLE(MISC::GET_HASH_KEY("ADDER"), ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1).x, ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1).y, ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1).z, 0.0F, TRUE, TRUE, FALSE);
}
void menuAction2() {
    if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 1)) {
        ENTITY::SET_ENTITY_COORDS(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 1), -2477, 3265, 32, 1, 0, 0, 1);
        VEHICLE::SET_VEHICLE_FORWARD_SPEED(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 1), 0.0F);
    }
    else {
        ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), -2477, 3265, 32, TRUE, FALSE, FALSE, TRUE);
    }
    return;
}
float h = 0.034F, w = 0.2249F;
void menu_Tick() {
    while (true) {
        static BOOL z = FALSE;
        if (IsKeyJustUp(VK_DIVIDE)) z = TRUE;
        if (IsKeyJustUp(VK_DIVIDE) && z == TRUE) z = FALSE;
        while (z) {
            float scale = w + (h/0.25F);
            int SCRx = 0, SCRy = 0;
            GRAPHICS::GET_SCREEN_RESOLUTION(&SCRx, &SCRy);

            /*Whatever the middle button is determines the background's draw position*/
            Vector2_t base = vec2_Create(0.163F, 0.201F);
            //Vector2_t base = vec2_Create(0.363F, 0.201F);

            BoxUI b = box_Create(rgb_Create(0.0F, 0.0F, 0.0F, 0.0F), { base.x, 0UL, base.y-h, 0UL }, w, h);
            BoxUI b1 = box_Create(rgb_Create(0, 0, 0, 0), { base.x, 0UL, (base.y) + 0.004F, 0UL }, w, h);
            BoxUI b2 = box_Create({ 0,0,0,0 }, { base.x, 0UL, b1.drawPos.y + h, 0UL }, w, h);
            BoxUI b3 = box_Create({ 0,0,0,0 }, { base.x, 0UL, b2.drawPos.y + h, 0UL }, w, h);
            BoxUI b4 = box_Create({ 0,0,0,0 }, { base.x, 0UL, b3.drawPos.y + h, 0UL }, w, h);
            BoxUI b5 = box_Create({ 0,0,0,0 }, { base.x, 0UL, b4.drawPos.y + h, 0UL }, w, h);
            BoxUI b6 = box_Create({ 0,0,0,0 }, { base.x, 0UL, b5.drawPos.y + h, 0UL }, w, h);
            BoxUI background = box_Create(rgb_Create(0, 0, 0, 125), { base.x, 0UL, b2.drawPos.y + (h/2.0F), 0UL}, w, ((h * 6)));

            //BoxUI addFirst = box_Create(rgb_Create(0.0F, 255.0F, 0.0F, 55.0F), { SCRx + 0.0F, 0UL, SCRy + 0.0F , 0UL }, 0.019F, 0.013F);
            //BoxUI addSecond = box_Create(rgb_Create(0.0F, 255.0F, 0.0F, 55.0F), { SCRx + 0.0F, 0UL, SCRy + 0.0F , 0UL }, 0.013F, 0.019F);

            BoxUI temp = b;
            HUD::SET_MOUSE_CURSOR_THIS_FRAME();
            float x = PAD::GET_CONTROL_NORMAL(0, 239);
            float y = PAD::GET_CONTROL_NORMAL(0, 240);
            std::string str = "Spawn Adder";
            TextUI* t = t_Create((char*)str.c_str(), 0, base, { 255,255,255,255 }, scale, FALSE, FALSE, FALSE);
            TextUI* b2Text = t_Create("Teleport to Zancudo", 1, base, { 255,255,255,255 }, scale, FALSE, FALSE, FALSE);

            //t->position = vec2_Create(base.x - (strlen(t->text)/2.0F)/100.0F, base.y);
            //w = (t->position.x + (w *0.503F));

            Button newButton = { t, t,&b, FALSE, menuAction};
            Button newButton2 = { b2Text, b2Text,&b1, FALSE, menuAction2};
            Button newButton3 = { t_Create("third",2, base, {255,255,255,255},scale, FALSE, FALSE, FALSE), t,&b2, FALSE, nullFunc };
            Button newButton4 = { t_Create("fourth",4,base, {255,255,255,255},scale, FALSE, FALSE, FALSE), t,&b3, FALSE, nullFunc };
            Button newButton5 = { t_Create("fifth",7,base, {255,255,255,255},scale, FALSE, FALSE, FALSE), t,&b4, FALSE, nullFunc };
            /*Third Font Seems to be a symbol Table? Of various null bytes and various default representations of characters like [] > < ^ (down) etc.*/
            Button newButton6 = { t_Create(util_IntToStr(25),3,base, {255,255,255,255},scale, FALSE, FALSE, FALSE), t,&b5, FALSE, nullFunc};
            Button newButton7 = { t_Create(util_IntToStr(25),3,base, {255,255,255,255},scale, FALSE, FALSE, FALSE), t,&b6, FALSE, nullFunc};
            
            ButtonList wrapper = list_Create(1,sizeof(Button*));
            list_Add(&wrapper, &newButton);
            list_Add(&wrapper, &newButton2);
            list_Add(&wrapper, &newButton3);
            list_Add(&wrapper, &newButton4);
            list_Add(&wrapper, &newButton5);
            list_Add(&wrapper, &newButton6);
            list_Add(&wrapper, &newButton7);

            Button* bS[6] = { &newButton, &newButton2, &newButton3, &newButton4, &newButton5, &newButton6 };

            PAD::DISABLE_ALL_CONTROL_ACTIONS(0);
            PAD::ENABLE_CONTROL_ACTION(0, 239, FALSE);
            PAD::ENABLE_CONTROL_ACTION(0, 240, FALSE);
            Vector2_t start = { 0 };
            Vector2_t diff = { 0 };

            for (int i = 0; i < wrapper.size; i++) {
                char* temp = wrapper.array[i]->leftText->text;
                if (isPointInsideBox(x, y, wrapper.array[i]->box)) {
                    t_Draw(t_Create(util_IntToStr(i), 0, {0.3F,0UL, 0.3F, 0UL}, {255,255,255,255},0.5,TRUE, FALSE, FALSE));
                    if (wrapper.array[i]->onClickInteraction == nullFunc) {
                        strncpy(wrapper.array[i]->leftText->text, "Unimplemented Item\0", 64);
                    }
                    if (PAD::IS_DISABLED_CONTROL_JUST_PRESSED(0, 237)) {
                        wrapper.array[i]->onClickInteraction();
                        //z = FALSE;
                    }
                    wrapper.array[i]->box->colour = { 255,255,255,255 };
                    wrapper.array[i]->leftText->colour = { 0,0,0,255 };
                }
                else {
                    strncpy(wrapper.array[i]->leftText->text, temp, 64);
                }
            }
            GRAPHICS::SET_SCRIPT_GFX_DRAW_ORDER(5);
            box_Draw(background);
            GRAPHICS::SET_SCRIPT_GFX_DRAW_ORDER(6);
            //box_Draw(b1);
            //box_Draw(b2);
            //box_Draw(b3);
            //box_Draw(b4);
            

            for (int i = 0; i < wrapper.size; i++) {
                box_Draw(*wrapper.array[i]->box);
                button_Text_Draw(*wrapper.array[i], FALSE);
            }
            //box_Draw(temp);


            //t_Draw(t_Create("Middle", 0, { b.topLeft.x + (b.width / 2.0F), 0UL, b.topLeft.y + (b.height / 2.5F), 0UL}, rgb_Create(255, 255, 255, 255), scale * 2.5F, FALSE, FALSE, TRUE));
            //t_Draw(t_Create("< None >", 0, { b.topLeft.x * scale * 2.5F , 0UL, b.topLeft.y + (b.height / 2.5F), 0UL }, rgb_Create(255, 255, 255, 255), scale * 2.5F, FALSE, FALSE, FALSE));

            if (IsKeyJustUp(VK_DIVIDE) && z) {
                h = 0.034F;
                w = 0.2249F;
                z = FALSE;
            }
            if (IsKeyJustUp(VK_ADD)) {
                h += 0.1F;
            }
            if (IsKeyJustUp(VK_MULTIPLY)) {
                w += 0.1F;
            }
            WAIT(0);
        }
        WAIT(0);
    }
}
void main()
{
    
    // Tick. 
    while (true)
    {   
        menu_Tick();

        WAIT(0);
    }
}

void PUSH_GFX(char* sParam0)//Position - 0x947C
{
    GRAPHICS::BEGIN_TEXT_COMMAND_SCALEFORM_STRING(sParam0);
    GRAPHICS::END_TEXT_COMMAND_SCALEFORM_STRING();
}
int switchIndex = 0;
int SCL_HANDLE = 0;
int timer = 0 ;
void THREAD_2() {
    for (;;) {
        //if (IsKeyDown(VK_RETURN)) {
        //    BigMsgHandle* handle = BIGMSG_Create("PURCHASED", "P");
        //    BIGMSG_ApplyWeapon(handle, "NAME", MISC::GET_HASH_KEY("WEAPON_PISTOL"), (char*)VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(MISC::GET_HASH_KEY("WEAPON_PISTOL")));
        //    BIGMSG_Tick(handle);
        //    BIGMSG_Free(handle);
        //}
        WAIT(0);
    }
}

void THREAD_MAIN_2() {
    srand(GetTickCount());
    THREAD_2();
}
void ScriptMain()
{
    srand(GetTickCount());
    main();
}

/*
*  t_Draw(t_Create(util_IntToStr(switchIndex), 0, { 0.17F, 0UL, 0.2F, 0UL }, rgb_Create(255, 255, 255, 255), 0.5, FALSE, FALSE, FALSE));
        t_Draw(t_Create(util_IntToStr(SCL_HANDLE), 0, { 0.17F, 0UL, 0.23F, 0UL }, rgb_Create(255, 255, 255, 255), 0.5, FALSE, FALSE, FALSE));
        t_Draw(t_Create(util_IntToStr(timer), 0, { 0.17F, 0UL, 0.26F, 0UL }, rgb_Create(255, 255, 255, 255), 0.5, FALSE, FALSE, FALSE));
        if (IsKeyJustUp(VK_ACCEPT)) {
            switchIndex = 0 ;
        } 
        switch (switchIndex)
        {
        case 0: //Set up Draw
            SCL_HANDLE = GRAPHICS::REQUEST_SCALEFORM_MOVIE("MP_BIG_MESSAGE_FREEMODE");
            timer = MISC::GET_GAME_TIMER() + 3000;
            switchIndex = 1;
            break;

        case 1: //Set up SCL
            if (MISC::GET_GAME_TIMER() > timer)
            {
                if (GRAPHICS::HAS_SCALEFORM_MOVIE_LOADED(SCL_HANDLE))
                {
                    GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(SCL_HANDLE, "SHOW_MISSION_PASSED_MESSAGE");
                    PUSH_GFX("M_FB4P3_P" /* GXT: ~y~Mission Passed );
                    PUSH_GFX("M_FB4P3" /* GXT: Getaway Vehicle );
                    GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_INT(100);
                    GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_BOOL(TRUE);
                    GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_INT(0);
                    GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_BOOL(TRUE);
                    GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
                    timer = MISC::GET_GAME_TIMER() + 10000;
                    switchIndex = 2;
                }
            }
            break;

        case 2: // Draw
            if (GRAPHICS::HAS_SCALEFORM_MOVIE_LOADED(SCL_HANDLE))
            {
                if (MISC::GET_GAME_TIMER() < timer)
                {
                    GRAPHICS::DRAW_SCALEFORM_MOVIE(SCL_HANDLE, 0.5f, 0.3f, 1.0f, 1.0f, 255, 255, 255, 255, 0);
                }
                else if (MISC::GET_GAME_TIMER() < timer + 100)
                {
                    GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(SCL_HANDLE, "TRANSITION_OUT");
                    GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
                    timer = (timer - 100);
                }
                else if (MISC::GET_GAME_TIMER() < timer + 500)
                {
                    GRAPHICS::DRAW_SCALEFORM_MOVIE(SCL_HANDLE, 0.5f, 0.3f, 1.0f, 1.0f, 255, 255, 255, 255, 0);
                }
                else
                {
                    switchIndex = 3;
                }
            }
            break;

        case 3: // CleanUp

            if (GRAPHICS::HAS_SCALEFORM_MOVIE_LOADED(SCL_HANDLE))
            {
                GRAPHICS::SET_SCALEFORM_MOVIE_AS_NO_LONGER_NEEDED(&SCL_HANDLE);
            }
            break;
        }
*/