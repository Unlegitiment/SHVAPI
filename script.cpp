#include "script.h"
#include "keyboard.h"
#include "MP_NEXT_JOB_SELECT/MPVoteScreen.h"
#include "UserIO/Mouse.h"
#include "Scaleform/CScaleform.h"
#include "UI.h"
#include "UIEditor/TextDraw/Text.h"
#include "UIEditor/BoxDraw/CBoxUI.h"
#include "UIEditor/ButtonDraw/CButtonController.h"
#include "Logger/Logging.h"
#include "UIEditor/Menu/Menu Dependancy(s)/ArrowButton.h"
#include <string>
#include <ctime>
#pragma warning(disable : 4244 4305) // double <-> float conversions

void main();
void THREAD_2();
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
int GET_MP_INT_CHARACTER_STAT(int iSlot = -1) {
    int res = -1;
    if (STATS::STAT_GET_INT(MISC::GET_HASH_KEY("MP0_CHAR_RANK_FM"), &res, -1)) {
        return res;
    }
    return 0;
}
void ButtonDraw(CButtonUI& b) {
    b.GetBox().Draw();
    for (int i = 0; i < b.ETEXT_MAX; i++) {
        b.GetText(static_cast<CButtonUI::eText>(i))->Draw();
    }
}
void draw3d(std::string str,float x,float y,float z, float scale, int fontType, float r, float g, float b, float a, bool useOutline = true, bool useDropshadow = true, int layer = 0 ) {
    //    native.setDrawOrigin(x, y, z, 0);
    //    native.beginTextCommandDisplayText('STRING');
    //    native.addTextComponentSubstringPlayerName(msg);
    //    native.setTextFont(fontType);
    //    native.setTextScale(1, scale);
    //    native.setTextWrap(0.0, 1.0);
    //    native.setTextCentre(true);
    //    native.setTextColour(r, g, b, a);
    //    if (useOutline) {
    //        native.setTextOutline();
    //    }
    //    if (useDropShadow) {
    //        native.setTextDropShadow();
    //    }
    //    native.endTextCommandDisplayText(0, 0, 0);
    //    native.clearDrawOrigin();
    //}
    GRAPHICS::SET_DRAW_ORIGIN(x, y, z, 0);
    GRAPHICS::DRAW_RECT(x, y, 0.1, 0.1, 255, 255, 255, 255, 0);
    HUD::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
    HUD::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(str.c_str());
    HUD::SET_TEXT_FONT(fontType);
    HUD::SET_TEXT_SCALE(1, scale);
    HUD::SET_TEXT_WRAP(0.0, 1.0);
    //HUD::SET_TEXT_CENTRE(true);
    HUD::SET_TEXT_COLOUR(r, g, b, a);
    if (useOutline) HUD::SET_TEXT_OUTLINE();
    if (useDropshadow) HUD::SET_TEXT_DROP_SHADOW();

    HUD::END_TEXT_COMMAND_DISPLAY_TEXT(0, 0, 1);
    GRAPHICS::CLEAR_DRAW_ORIGIN();
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
void main() //Frontend Tick. 
{
	// Tick. 
	while (true)
	{

		if (IsKeyJustUp(VK_DIVIDE)) {
			bool isActive = true;
            CArrowButton b = CArrowButton(
                //CBox(CVector2(0.1,0.1),CRGBA(0,0,0,120),0.1,0.1),
                //CTextUI("1", CVector2(0.1,0.1),0.512,3,CRGBA(255,255,255,255),CTextDropshadow(0.1,CRGBA(0,0,0,180)),new CMiddleJustify(), false),
                CVector2(0.1,0.1), CArrowButton::eArrowBtn::AB_DWN);
            CArrowView v = CArrowView();
            
            /*
            * Predeclaring these objects allows us to effectively 
            */
            CButtonUI& button2 =  CButtonUI(CBox(CVector2(0.25, 0.7), CRGBA(000, 000, 000, 120), 0.25, 0.5));
            CButtonUI& button =   CButtonUI(CBox(CVector2(0.71, 0.7), CRGBA(00, 255, 255, 120), 0.5, 0.5));
            button.SetText(button.ETEXT_LEFT, new CTextUI("A", CVector2(0.2, 0.2), CRGBA(255, 255, 255, 255)));
            button.SetText(button.ETEXT_MIDDLE, new CTextUI("MIDDLE", CVector2(0.2, 0.2), CRGBA(255, 255, 255, 255)));
            button.SetText(button.ETEXT_RIGHT, new CTextUI("RIGHT",CVector2(0.2,0.2), CRGBA(255, 255, 255, 255)));
            button2.SetText(button.ETEXT_LEFT, new CTextUI("LEFT", CVector2(0.2, 0.2), CRGBA(255, 255, 255, 255)));
            button2.SetText(button.ETEXT_MIDDLE, new CTextUI("MIDDLE", CVector2(0.2, 0.2), CRGBA(255, 255, 255, 255)));
            button2.SetText(button.ETEXT_RIGHT, new CTextUI("RIGHT", CVector2(0.2, 0.2), CRGBA(255, 255, 255, 255)));

            int i = 0;
			while (isActive) {
                v.Draw(b.GetText(), b.GetBox());
                PAD::DISABLE_ALL_CONTROL_ACTIONS(0);
                PAD::ENABLE_CONTROL_ACTION(0, 239, 0);
                PAD::ENABLE_CONTROL_ACTION(0, 240, 0);

                bool contll2 = false;
                bool contrll1 = false;
				CButtonMgr controller = CButtonMgr(button);
                CButtonMgr controller2 = CButtonMgr(button2);
                if (IsKeyJustUp(VK_F14)) {
                    contrll1 = !contrll1;
                    contll2 = !contll2;
                }
                if (IsKeyJustUp(VK_F15)) { 
                    // Varying combinations of this font however the most important ones are that the arrows are in the first 4 characters. 
                    i++;
                    button.GetText(button.ETEXT_LEFT)->font = 3;
                    button.GetText(button.ETEXT_LEFT)->text = std::to_string(i);
                }

                if (button.GetBox().GetIfPointIsInside(CVector2(PAD::GET_CONTROL_NORMAL(0, 239), PAD::GET_CONTROL_NORMAL(0, 240)))) {
                    contrll1 = true;
                }
                if (button2.GetBox().GetIfPointIsInside(CVector2(PAD::GET_CONTROL_NORMAL(0, 239), PAD::GET_CONTROL_NORMAL(0, 240)))) {
                    contll2 = true;
                }
                controller.FlagDebugSymbols(contrll1);
                controller2.FlagDebugSymbols(contll2);
                CMouse& mouseRef = CMouse::GetInstance();  mouseRef.Tick(CMouse::Activation::ACT_FRAME);

                controller.handleMouse(CRGBA(0, 0, 0, 100), PAD::GET_CONTROL_NORMAL(0, 239), PAD::GET_CONTROL_NORMAL(0, 240));
                controller2.handleMouse(CRGBA(0, 255, 0, 120), PAD::GET_CONTROL_NORMAL(0, 239), PAD::GET_CONTROL_NORMAL(0, 240));
                if (IsKeyJustUp(VK_F13)) {
                    controller.UpdateDrawPos(CVector2(0.25, 0.25));
                    controller.SetHeight(button.GetBox().GetHeight() / 2.0F);
                    controller.SetWidth(button.GetBox().GetWidth() / 2.0F);
                    controller.SetNewColor(CRGBA(255, 255, 255, 10));
                }
				std::string str = "TOP:" + button.GetBox().GetCornerPos(button.GetBox().TOPLEFT).toStr() + "~n~" + button.GetBox().GetCornerPos(button.GetBox().TOPRIGHT).toStr();
				std::string btm = "BOT:";// + button.GetBox().GetCornerPos(button.GetBox().BOTTOMLEFT).toStr() + "~n~" + button.GetBox().GetCornerPos(button.GetBox().BOTTOMRIGHT).toStr() + "~n~" + button.GetBox().GetDrawPos().toStr();
				CTextUI* text = new CTextUI(str, CVector2(0.2, 0.1), CRGBA(255, 255, 255, 200));
				CTextUI* btmTxt = new CTextUI(btm, CVector2(0.2, text->pos.y + (text->size / 7.0F)), CRGBA(255, 255, 255, 200));
				if (IsKeyJustUp(VK_DIVIDE)) {
                    isActive = false;
				}
				WAIT(0);
			}
		}
		WAIT(0);
	}
}

void THREAD_2() { 
    while (true) {
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
//void menu_Tick() {
//    while (true) {
//        static BOOL z = FALSE;
//        if (IsKeyJustUp(VK_DIVIDE)) z = TRUE;
//        if (IsKeyJustUp(VK_DIVIDE) && z == TRUE) z = FALSE;
//        float scale = w + (h / 0.25F);
//        Vector2_t base = vec2_Create(0.163F, 0.201F);
//
//        BoxUI b = box_Create(rgb_Create(0.0F, 0.0F, 0.0F, 0.0F), { base.x, 0UL, base.y - h, 0UL }, w, h);
//        BoxUI b1 = box_Create(rgb_Create(0, 0, 0, 0), { base.x, 0UL, (base.y) + 0.004F, 0UL }, w, h);
//        BoxUI b2 = box_Create({ 0,0,0,0 }, { base.x, 0UL, b1.drawPos.y + h, 0UL }, w, h);
//        BoxUI b3 = box_Create({ 0,0,0,0 }, { base.x, 0UL, b2.drawPos.y + h, 0UL }, w, h);
//        BoxUI b4 = box_Create({ 0,0,0,0 }, { base.x, 0UL, b3.drawPos.y + h, 0UL }, w, h);
//        BoxUI b5 = box_Create({ 0,0,0,0 }, { base.x, 0UL, b4.drawPos.y + h, 0UL }, w, h);
//        BoxUI b6 = box_Create({ 0,0,0,0 }, { base.x, 0UL, b5.drawPos.y + h, 0UL }, w, h);
//        BoxUI b7 = box_Create({ 0,0,0,0 }, { base.x, 0UL, b6.drawPos.y + h, 0UL }, w, h);
//        std::string str = "<Quick GPS>";
//        TextUI* t = t_Create((char*)str.c_str(), 0, base, { 255,255,255,255 }, scale, FALSE, FALSE, FALSE);
//        TextUI* b2Text = t_Create("Teleport to Zancudo", 0, base, { 255,255,255,255 }, scale, FALSE, FALSE, FALSE);
//        Button newButton = { t, t,&b, FALSE, menuAction };
//        Button newButton2 = { b2Text, b2Text,&b1, FALSE, menuAction2 };
//        Button newButton3 = { t_Create("third",0, base, {255,255,255,255},scale, FALSE, FALSE, FALSE), t,&b2, FALSE, menuAction };
//        Button newButton4 = { t_Create("fourth",0,base, {255,255,255,255},scale, FALSE, FALSE, FALSE), t,&b3, FALSE, menuAction };
//        Button newButton5 = { t_Create("fifth",0,base, {255,255,255,255},scale, FALSE, FALSE, FALSE), t,&b4, FALSE, menuAction };
//        /*Third Font Seems to be a symbol Table? Of various null bytes and various default representations of characters like [] > < ^ (down) etc.*/
//        Button newButton6 = { t_Create(util_IntToStr(1),3,base, {255,255,255,255},scale, FALSE, FALSE, FALSE), t,&b5, FALSE, menuAction };
//        Button newButton7 = { t_Create(util_IntToStr(2),3,base, {255,255,255,255},scale, FALSE, FALSE, FALSE), t,&b6, FALSE, menuAction };
//        Button newButton8 = { t_Create(util_IntToStr(2),3,base, {255,255,255,255},scale, FALSE, FALSE, FALSE), t,&b7, FALSE, menuAction };
//
//        while (z) {
//            
//            int SCRx = 0, SCRy = 0;
//            GRAPHICS::GET_SCREEN_RESOLUTION(&SCRx, &SCRy);
//
//            /*Whatever the middle button is determines the background's draw position*/
//            //Vector2_t base = vec2_Create(0.363F, 0.201F);
//
//
//
//
//            //BoxUI addFirst = box_Create(rgb_Create(0.0F, 255.0F, 0.0F, 55.0F), { SCRx + 0.0F, 0UL, SCRy + 0.0F , 0UL }, 0.019F, 0.013F);
//            //BoxUI addSecond = box_Create(rgb_Create(0.0F, 255.0F, 0.0F, 55.0F), { SCRx + 0.0F, 0UL, SCRy + 0.0F , 0UL }, 0.013F, 0.019F);
//
//            BoxUI temp = b;
//            HUD::SET_MOUSE_CURSOR_THIS_FRAME();
//            float x = PAD::GET_CONTROL_NORMAL(0, 239);
//            float y = PAD::GET_CONTROL_NORMAL(0, 240);
//
//
//
//            //t->position = vec2_Create(base.x - (strlen(t->text)/2.0F)/100.0F, base.y);
//            //w = (t->position.x + (w *0.503F));
//
//            
//            List wrapper = list_Create(1,sizeof(Button*));
//            list_Add(&wrapper, &newButton);
//            list_Add(&wrapper, &newButton2);
//            list_Add(&wrapper, &newButton3);
//            list_Add(&wrapper, &newButton4);
//            list_Add(&wrapper, &newButton5);
//            list_Add(&wrapper, &newButton6);
//            list_Add(&wrapper, &newButton7);
//            list_Add(&wrapper, &newButton8);
//            BoxUI background;
//            Button** ptr = (Button**)wrapper.array;
//            if (wrapper.size % 2) {
//                background = box_Create(rgb_Create(0, 0, 0, 125), { base.x, 0UL, ptr[wrapper.size/2-1]->box->drawPos.y + (h), 0UL}, w, ((h * wrapper.size)));
//            }
//            else {
//                background = box_Create(rgb_Create(0, 0, 0, 125), { base.x, 0UL, ptr[wrapper.size / 2 - 1]->box->drawPos.y + (h/2.0F), 0UL }, w, ((h * wrapper.size)));
//
//            }
//            PAD::DISABLE_ALL_CONTROL_ACTIONS(0);
//            PAD::ENABLE_CONTROL_ACTION(0, 239, FALSE);
//            PAD::ENABLE_CONTROL_ACTION(0, 240, FALSE);
//            Vector2_t start = { 0 };
//            Vector2_t diff = { 0 };
//            static int index = 0;
//            BoxUI selectionBox = box_Create({ 255,255,255,0 }, {0,0,0,0},0,0);
//            TextUI* selectedText = t_Create("NULL", 0, { 0,0,0,0 }, { 0,0,0,0 }, 0, FALSE, FALSE, FALSE);
//
//            for (int i = 0; i < wrapper.size; i++) {
//                char* temp = ptr[i]->leftText->text;
//                if (IsKeyJustUp(VK_DOWN)) {
//                    index++;
//                }
//                if (index > wrapper.size || index == wrapper.size) {
//                    index = 0;
//                }
//                if (IsKeyJustUp(VK_UP)) {
//                    if (index == 0) {
//                        index = wrapper.size;
//                    }
//                    index--;
//                }
//                if (IsKeyJustUp(VK_RETURN)) {
//                    ptr[index]->onClickInteraction();
//                }
//                selectionBox = box_Create({ 255,255,255,200 }, ptr[index]->box->drawPos, w, h);
//                selectedText = t_Create(ptr[index]->leftText->text, ptr[index]->leftText->font, ptr[index]->leftText->position, { 0,0,0,255 }, ptr[index]->leftText->size, ptr[index]->leftText->hasOutline, ptr[index]->leftText->hasDropshadow, ptr[index]->leftText->isCenter);
//
//            }
//            for (int i = 0; i < wrapper.size; i++) {
//
//                char* temp = ptr[i]->leftText->text;
//                if (isPointInsideBox(x, y, ptr[i]->box)) {
//                    t_Draw(t_Create(util_IntToStr(i), 0, {0.3F,0UL, 0.3F, 0UL}, {255,255,255,255},0.5,TRUE, FALSE, FALSE));
//                    //if (ptr[i]->onClickInteraction == nullFunc) {
//                    //    strncpy(ptr[i]->leftText->text, "Unimplemented Item\0", 64);
//                    //}
//                    if (PAD::IS_DISABLED_CONTROL_JUST_PRESSED(0, 237)) {
//                        ptr[i]->onClickInteraction();
//                        //z = FALSE;
//                    }
//                    GRAPHICS::SET_SCRIPT_GFX_DRAW_ORDER(6);
//                    selectionBox = box_Create({ 255,255,255,200 }, ptr[i]->box->drawPos, w, h);
//                    selectedText = t_Create(ptr[i]->leftText->text, ptr[i]->leftText->font, ptr[i]->leftText->position, {0,0,0,255}, ptr[i]->leftText->size, ptr[i]->leftText->hasOutline, ptr[i]->leftText->hasDropshadow, ptr[i]->leftText->isCenter);
//                }
//                else {
//                    strncpy(ptr[i]->leftText->text, temp, 64);
//                }
//            }
//            Button selectedButton = { selectedText, NULL, &selectionBox, FALSE, NULL };
//            GRAPHICS::SET_SCRIPT_GFX_DRAW_ORDER(5);
//            box_Draw(background);
//            GRAPHICS::SET_SCRIPT_GFX_DRAW_ORDER(6);
//            //box_Draw(b1);
//            //box_Draw(b2);
//            //box_Draw(b3);
//            //box_Draw(b4);
//            for (int i = 0; i < wrapper.size; i++) {
//                box_Draw(*ptr[i]->box);
//                GRAPHICS::SET_SCRIPT_GFX_DRAW_ORDER(7);
//                button_Text_Draw(*ptr[i], FALSE);
//            }
//            GRAPHICS::SET_SCRIPT_GFX_DRAW_ORDER(8);
//            box_Draw(*selectedButton.box);
//            button_Text_Draw(selectedButton, FALSE);
//            
//            //box_Draw(temp);
//
//
//            //t_Draw(t_Create("Middle", 0, { b.topLeft.x + (b.width / 2.0F), 0UL, b.topLeft.y + (b.height / 2.5F), 0UL}, rgb_Create(255, 255, 255, 255), scale * 2.5F, FALSE, FALSE, TRUE));
//            //t_Draw(t_Create("< None >", 0, { b.topLeft.x * scale * 2.5F , 0UL, b.topLeft.y + (b.height / 2.5F), 0UL }, rgb_Create(255, 255, 255, 255), scale * 2.5F, FALSE, FALSE, FALSE));
//
//            if (IsKeyJustUp(VK_DIVIDE) && z) {
//                h = 0.034F;
//                w = 0.2249F;
//                index = 0;
//                list_Clear(&wrapper);
//                z = FALSE;
//            }
//            if (IsKeyJustUp(VK_ADD)) {
//                h += 0.1F;
//            }
//            if (IsKeyJustUp(VK_MULTIPLY)) {
//                w += 0.1F;
//            }
//            WAIT(0);
//        }
//        WAIT(0);
//    }
//}
/* Just Random Stuff to do with the API.
  PAD::DISABLE_ALL_CONTROL_ACTIONS(0);
  PAD::ENABLE_CONTROL_ACTION(0, 239, FALSE);
  PAD::ENABLE_CONTROL_ACTION(0, 240, FALSE);
  PAD::ENABLE_CONTROL_ACTION(0, 237, FALSE);
  PAD::ENABLE_CONTROL_ACTION(0, 238, FALSE);
  HUD::SET_MOUSE_CURSOR_THIS_FRAME();
  float x = PAD::GET_CONTROL_NORMAL(0, 239);
  float y = PAD::GET_CONTROL_NORMAL(0, 240);
  float click = PAD::GET_CONTROL_NORMAL(0, 237);
  float cancel = PAD::GET_CONTROL_NORMAL(0, 238);
  float unNormalx = 0.0F;
  float unNormaly = 0.0F;
  deNormalizeONSCR({ x + 0.0F, 0, y + 0.0F, 0 }, &unNormalx, &unNormaly);
  std::string str = "Base: (" + std::to_string(x) + "," + std::to_string(y) + ")" + "\nUnN: (" + std::to_string(unNormalx) + "," + std::to_string(unNormaly) + ")";
  std::string str2 = "Click: " + std::to_string(click) + "\nCancel:" + std::to_string(cancel);
  float lmfaoso = lmfao(1,,)
  Button b = { t_Create((char*)str.c_str(), 0, {x, 0, y + 0.04F, 0}, {255,255,255,255},0.512, FALSE, FALSE, FALSE), NULL, box_Create({0,0,0,120}, {x , 0, y - 0.2F, 0},0.3F, 0.15F), FALSE, NULL };
  Button b1 = { t_Create((char*)str2.c_str(), 0, {x, 0, y + 0.04F, 0}, {255,255,255,255},0.512, FALSE, FALSE, FALSE), NULL, box_Create({0,0,0,120}, {b.box.drawPos.x , 0, b.box.drawPos.y + b.box.height , 0},0.3F, 0.15F), FALSE, NULL };
  box_Draw(b.box);
  button_Text_Draw(b, FALSE);
  box_Draw(b1.box);
  button_Text_Draw(b1, FALSE);
*/


//Any thing After this point is depricated Code or code that will eventually be reworked into a seperate class/file.


//void deNormalizeONSCR(Vector2_t conversion, float* x, float* y) {
//    int SCRx = 0;
//    int SCRy = 0;
//    GRAPHICS::GET_ACTUAL_SCREEN_RESOLUTION(&SCRx, &SCRy);
//    *x = conversion.x * SCRx;
//    *y = conversion.y * SCRy;
//    return;
//}
//void normalizeScr(Vector2_t conversion, float* x, float* y) {
//    int SCRX = 0;
//    int SCRY = 0;
//    GRAPHICS::GET_ACTUAL_SCREEN_RESOLUTION(&SCRX, &SCRY);
//    *x = conversion.x / SCRX;
//    *y = conversion.y / SCRY;
//    return;
//}
//float easeInOut(float t, float b, float c, float d) {
//    return (-c) / 2 * (cos(3.141592653589793 * t / d) - 1) + b;
//}
//
//void DrawBox(float x, float y, float width, float height) {
//    GRAPHICS::DRAW_RECT(x, y, width, height, 0, 0, 255, 100, TRUE);
//}
//
//void AnimateBox(float startTime, float duration, float startX, float endX) {
//    float endTime = MISC::GET_GAME_TIMER() - startTime;
//    if (endTime > duration)
//        endTime = duration;
//
//    float currentX = easeInOut(endTime, startX, endX - startX, duration);
//    float currentY = SYSTEM::SIN(endTime * 0.15F);
//    float normalizedY = fabs((currentY));
//
//    UI_DrawText(util_FloatToStr(currentX), { 0.8,0,0.5,0 });
//    UI_DrawText(util_FloatToStr(currentY), { 0.8,0,0.55,0 });
//    UI_DrawText(util_FloatToStr(normalizedY), { 0.8,0,0.6,0 });
//    //DrawBox(currentX, 0.5F, w, h);
//
//    GRAPHICS::DRAW_RECT(currentX, normalizedY, 0.16, 0.16F, 0, 0, 255, 125, TRUE);
//}

//void disable2(signed flags) {
//    DLC::ON_ENTER_MP();
//    GRAPHICS::SET_DISABLE_DECAL_RENDERING_THIS_FRAME();
//
//    // Define an array of hash keys corresponding to each case
//    const Hash hashKeys[] = {
//        MISC::GET_HASH_KEY("apa_ss1_11_flats"),
//        MISC::GET_HASH_KEY("ss1_11_ss1_emissive_a"),
//        MISC::GET_HASH_KEY("ss1_11_detail01b"),
//        MISC::GET_HASH_KEY("ss1_11_Flats_LOD"),
//        MISC::GET_HASH_KEY("SS1_02_Building01_LOD"),
//        MISC::GET_HASH_KEY("SS1_LOD_01_02_08_09_10_11"),
//        MISC::GET_HASH_KEY("SS1_02_SLOD1"),
//        MISC::GET_HASH_KEY("hei_dt1_20_build2"),
//        MISC::GET_HASH_KEY("dt1_20_dt1_emissive_dt1_20"),
//        MISC::GET_HASH_KEY("bh1_09_ema"),
//        MISC::GET_HASH_KEY("hei_bh1_09_bld_01"),
//        MISC::GET_HASH_KEY("hei_sm_14_bld2"),
//        MISC::GET_HASH_KEY("sm_14_emissive"),
//        MISC::GET_HASH_KEY("prop_wall_light_12a"),
//        MISC::GET_HASH_KEY("hei_dt1_03_build1x"),
//        MISC::GET_HASH_KEY("DT1_Emissive_DT1_03_b1"),
//        MISC::GET_HASH_KEY("dt1_03_dt1_Emissive_b1"),
//        MISC::GET_HASH_KEY("hei_bh1_08_bld2"),
//        MISC::GET_HASH_KEY("bh1_emissive_bh1_08"),
//        MISC::GET_HASH_KEY("bh1_08_bld2_LOD"),
//        MISC::GET_HASH_KEY("hei_bh1_08_bld2"),
//        MISC::GET_HASH_KEY("bh1_08_em"),
//        MISC::GET_HASH_KEY("apa_ss1_02_building01"),
//        MISC::GET_HASH_KEY("SS1_Emissive_SS1_02a_LOD"),
//        MISC::GET_HASH_KEY("ss1_02_ss1_emissive_ss1_02"),
//        MISC::GET_HASH_KEY("apa_ss1_02_building01"),
//        MISC::GET_HASH_KEY("SS1_02_Building01_LOD"),
//        MISC::GET_HASH_KEY("apa_ch2_05e_res5"),
//        MISC::GET_HASH_KEY("apa_ch2_05e_res5_LOD"),
//        MISC::GET_HASH_KEY("apa_ch2_04_house02"),
//        MISC::GET_HASH_KEY("apa_ch2_04_house02_d"),
//        MISC::GET_HASH_KEY("apa_ch2_04_M_a_LOD"),
//        MISC::GET_HASH_KEY("ch2_04_house02_railings"),
//        MISC::GET_HASH_KEY("ch2_04_emissive_04"),
//        MISC::GET_HASH_KEY("ch2_04_emissive_04_LOD"),
//        MISC::GET_HASH_KEY("apa_ch2_09b_hs01a_details"),
//        MISC::GET_HASH_KEY("apa_ch2_09b_hs01"),
//        MISC::GET_HASH_KEY("apa_ch2_09b_hs01_balcony"),
//        MISC::GET_HASH_KEY("apa_ch2_09b_Emissive_11_LOD"),
//        MISC::GET_HASH_KEY("apa_ch2_09b_Emissive_11"),
//        MISC::GET_HASH_KEY("apa_CH2_09b_House08_LOD"),
//        MISC::GET_HASH_KEY("apa_ch2_09c_hs11"),
//        MISC::GET_HASH_KEY("CH2_09c_Emissive_11_LOD"),
//        MISC::GET_HASH_KEY("CH2_09c_Emissive_11"),
//        MISC::GET_HASH_KEY("apa_ch2_09c_hs11_details"),
//        MISC::GET_HASH_KEY("apa_ch2_05c_b4"),
//        MISC::GET_HASH_KEY("ch2_05c_decals_05"),
//        MISC::GET_HASH_KEY("ch2_05c_B4_LOD"),
//        MISC::GET_HASH_KEY("ch2_05c_emissive_07"),
//        MISC::GET_HASH_KEY("apa_ch2_09c_hs07"),
//        MISC::GET_HASH_KEY("ch2_09c_build_11_07_LOD"),
//        MISC::GET_HASH_KEY("CH2_09c_Emissive_07_LOD"),
//        MISC::GET_HASH_KEY("apa_ch2_09c_build_11_07_LOD"),
//        MISC::GET_HASH_KEY("ch2_09c_hs07_details"),
//        MISC::GET_HASH_KEY("CH2_09c_Emissive_07"),
//        MISC::GET_HASH_KEY("apa_ch2_09c_hs13"),
//        MISC::GET_HASH_KEY("apa_ch2_09c_hs13_details"),
//        MISC::GET_HASH_KEY("apa_CH2_09c_House11_LOD"),
//        MISC::GET_HASH_KEY("ch2_09c_Emissive_13_LOD"),
//        MISC::GET_HASH_KEY("ch2_09c_Emissive_13"),
//        MISC::GET_HASH_KEY("apa_ch2_09b_hs02"),
//        MISC::GET_HASH_KEY("apa_ch2_09b_hs02b_details"),
//        MISC::GET_HASH_KEY("apa_ch2_09b_Emissive_09_LOD"),
//        MISC::GET_HASH_KEY("ch2_09b_botpoolHouse02_LOD"),
//        MISC::GET_HASH_KEY("apa_ch2_09b_Emissive_09"),
//        MISC::GET_HASH_KEY("apa_ch2_09b_hs02_balcony"),
//        MISC::GET_HASH_KEY("apa_ch2_12b_house03mc"),
//        MISC::GET_HASH_KEY("ch2_12b_emissive_02"),
//        MISC::GET_HASH_KEY("ch2_12b_house03_MC_a_LOD"),
//        MISC::GET_HASH_KEY("ch2_12b_emissive_02_LOD"),
//        MISC::GET_HASH_KEY("ch2_12b_railing_06"),
//        MISC::GET_HASH_KEY("apa_ch2_04_house01"),
//        MISC::GET_HASH_KEY("apa_ch2_04_house01_d"),
//        MISC::GET_HASH_KEY("ch2_04_emissive_05_LOD"),
//        MISC::GET_HASH_KEY("apa_ch2_04_M_b_LOD"),
//        MISC::GET_HASH_KEY("ch2_04_emissive_05"),
//        MISC::GET_HASH_KEY("ch2_04_house01_details"),
//    };
//
//    // Iterate through the array based on the flags
//    for (int i = 0; i < sizeof(hashKeys) / sizeof(hashKeys[0]); ++i) {
//        if (flags & (1 << i)) {
//            INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(hashKeys[i]);
//        }
//    }
//}

/*
So Intotal what I should do definitely is basically when I create a button we add it to the list. (NO)
So we apply the button to the menu maybe so that we can have buttons that are shared across a potential List.
So like apply the button to the menu and create specific instances of a menu?
*/
//const char* boolO_STR(BOOL t) {
//    if (t == 1) {
//        return "TRUE";
//    }
//    else {
//        return "FALSE";
//    }
//}

//void DisableEclipse() {
//    while (true) {
//        HUD::THEFEED_FLUSH_QUEUE();
//
//        GRAPHICS::SET_DISABLE_DECAL_RENDERING_THIS_FRAME();
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ss1_11_flats"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ss1_11_ss1_emissive_a"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ss1_11_detail01b"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ss1_11_Flats_LOD"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("SS1_02_Building01_LOD"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("SS1_LOD_01_02_08_09_10_11"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("SS1_02_SLOD1"));
//        GRAPHICS::DISABLE_OCCLUSION_THIS_FRAME();
//        GRAPHICS::SET_SCRIPT_GFX_DRAW_ORDER(1);
//        UI_DRAWBOX(rgb_Create(0, 0, 0, 255), { 0.1F,0UL, 0.513F, 0UL }, 0.01F, 0.039F);
//        GRAPHICS::SET_SCRIPT_GFX_DRAW_ORDER(2);
//
//
//        /*Thread Controller For Adding back that side of the building and transfering ownership of the program to that thread.*/
//        if (IsKeyJustUp(VK_DIVIDE)) {
//            UI_DrawNotificationSTR("FALSE");
//            main();
//        }
//        WAIT(0);
//    }
//}

//typedef enum {
//    RGBA_R, RGBA_G, RGBA_B, RGBA_A
//}RGBA_MOD_TYPE;
//void RGBA_Mod(RGBA_t* ptr, RGBA_MOD_TYPE valToMod, float val) {
//    switch (valToMod) {
//    case RGBA_R:
//        ptr->r = val;
//        break;
//    case RGBA_B:
//        ptr->b = val;
//        break;
//    case RGBA_A:
//        ptr->a = val;
//        break;
//    case RGBA_G:
//        ptr->g = val;
//        break;
//    }
//    return;
//}
//void flashColour(RGBA_t* colour) {
//    RGBA_t* temp = colour;
//
//    *colour = { 255,255,255,255 };
//    WAIT(0);
//    colour = temp;
//    return;
//}
//void disable(signed flags) {
//    DLC::ON_ENTER_MP();
//    GRAPHICS::SET_DISABLE_DECAL_RENDERING_THIS_FRAME();
//
//    //switch (flags) {
//    //case 1 << 0:
//    //    /*Eclipse*/
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ss1_11_flats"));
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ss1_11_ss1_emissive_a"));
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ss1_11_detail01b"));
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ss1_11_Flats_LOD"));
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("SS1_02_Building01_LOD"));
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("SS1_LOD_01_02_08_09_10_11"));
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("SS1_02_SLOD1"));
//    //    break;
//    //case 1 << 1:
//    //    /*Alta*/
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("hei_dt1_20_build2"));
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("dt1_20_dt1_emissive_dt1_20"));
//    //    break;
//    //case 1 << 2:
//    //    /*Weazel*/
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("bh1_09_ema"));
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("hei_bh1_09_bld_01"));
//    //    break;
//    //case 1 << 3:
//    //    /*Del Parro*/
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("hei_sm_14_bld2"));
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("sm_14_emissive"));
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("prop_wall_light_12a"));
//    //    break;
//    //case 1 << 4:
//    //    /*Pillbox Hill*/
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("hei_dt1_03_build1x"));
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("DT1_Emissive_DT1_03_b1"));
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("dt1_03_dt1_Emissive_b1"));
//    //    break;
//    //case 1 << 5:
//    //    //Richard
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("hei_bh1_08_bld2"));
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("bh1_emissive_bh1_08"));
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("bh1_08_bld2_LOD"));
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("hei_bh1_08_bld2"));
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("bh1_08_em"));
//    //    break;
//    //case 1 << 6:
//    //            /*Tinsel*/
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ss1_02_building01"      ));
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("SS1_Emissive_SS1_02a_LOD"   ));
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ss1_02_ss1_emissive_ss1_02" ));
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ss1_02_building01"      ));
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("SS1_02_Building01_LOD"      ));
//    //    break;
//    //case 1 << 7:
//    //    //STILT
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_05e_res5"));
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_05e_res5_LOD"));
//    //    break;
//    //case 1 << 8:
//    //    /*Stilt*/
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_04_house02"));
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_04_house02_d"));
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_04_M_a_LOD"));
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ch2_04_house02_railings"));
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ch2_04_emissive_04"));
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ch2_04_emissive_04_LOD"));
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_04_house02_details"));
//    //    break;
//    //case 1 << 9:
//    //    /*Stilt*/
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_09b_hs01a_details"));
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_09b_hs01"));
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_09b_hs01_balcony"));
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_09b_Emissive_11_LOD"));
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_09b_Emissive_11"));
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_CH2_09b_House08_LOD"));
//    //    break;
//    //case 1 << 10:
//    //    /*Stilt*/
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_09c_hs11"));
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("CH2_09c_Emissive_11_LOD"));
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("CH2_09c_Emissive_11"));
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_09c_hs11_details"));
//    //    break;
//    //case 1 << 11:
//    //    /*Stilt*/
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_05c_b4"));
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ch2_05c_decals_05"));
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ch2_05c_B4_LOD"));
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ch2_05c_emissive_07"));
//    //    break;
//    //case 1 << 12:
//    //    /*Stilt*/
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_09c_hs07"));
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ch2_09c_build_11_07_LOD"));
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("CH2_09c_Emissive_07_LOD"));
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_09c_build_11_07_LOD"));
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ch2_09c_hs07_details"));
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("CH2_09c_Emissive_07"));
//    //    break;
//    //case 1 << 13:
//    //    /*Stilt*/
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_09c_hs13"));
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_09c_hs13_details"));
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_CH2_09c_House11_LOD"));
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ch2_09c_Emissive_13_LOD"));
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ch2_09c_Emissive_13"));
//    //    break;
//    //case 1 << 14:
//    //    /*Stilt*/
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_09b_hs02"));
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_09b_hs02b_details"));
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_09b_Emissive_09_LOD"));
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ch2_09b_botpoolHouse02_LOD"));
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_09b_Emissive_09"));
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_09b_hs02_balcony"));
//    //    break;
//    //case 1 << 15:
//    //    /*Stilt*/
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_12b_house03mc"));
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ch2_12b_emissive_02"));
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ch2_12b_house03_MC_a_LOD"));
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ch2_12b_emissive_02_LOD"));
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ch2_12b_railing_06"));
//    //    break;
//    //case 1 << 16:
//    //    //STILT
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_04_house01"));
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_04_house01_d"));
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ch2_04_emissive_05_LOD"));
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_04_M_b_LOD"));
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ch2_04_emissive_05"));
//    //    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ch2_04_house01_details"));
//    //    break;
//    //}
//
//    if (flags & (1 << 0)) {
//        /*Eclipse*/
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ss1_11_flats"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ss1_11_ss1_emissive_a"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ss1_11_detail01b"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ss1_11_Flats_LOD"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("SS1_02_Building01_LOD"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("SS1_LOD_01_02_08_09_10_11"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("SS1_02_SLOD1"));
//    }
//    if (flags & (1 << 1)) {
//        /*Alta*/
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("hei_dt1_20_build2"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("dt1_20_dt1_emissive_dt1_20"));
//    }
//    if (flags & (1 << 2)) {
//        /*Weazel*/
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("bh1_09_ema"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("hei_bh1_09_bld_01"));
//    }
//    if (flags & (1 << 3)) {
//        /*Del Parro*/
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("hei_sm_14_bld2"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("sm_14_emissive"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("prop_wall_light_12a"));
//    }
//    if (flags & (1 << 4)) {
//        /*Pillbox Hill*/
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("hei_dt1_03_build1x"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("DT1_Emissive_DT1_03_b1"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("dt1_03_dt1_Emissive_b1"));
//    }
//    if (flags & (1 << 5)) {
//        //Richard
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("hei_bh1_08_bld2"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("bh1_emissive_bh1_08"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("bh1_08_bld2_LOD"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("hei_bh1_08_bld2"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("bh1_08_em"));
//    }
//    if (flags & (1 << 6)) {
//        /*Tinsel*/
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ss1_02_building01"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("SS1_Emissive_SS1_02a_LOD"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ss1_02_ss1_emissive_ss1_02"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ss1_02_building01"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("SS1_02_Building01_LOD"));
//    }
//    if (flags & (1 << 7)) {
//        //STILT
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_05e_res5"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_05e_res5_LOD"));
//    }
//    if (flags & (1 << 8)) {
//        /*Stilt*/
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_04_house02"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_04_house02_d"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_04_M_a_LOD"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ch2_04_house02_railings"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ch2_04_emissive_04"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ch2_04_emissive_04_LOD"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_04_house02_details"));
//    }
//    if (flags & (1 << 9)) {
//        /*Stilt*/
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_09b_hs01a_details"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_09b_hs01"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_09b_hs01_balcony"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_09b_Emissive_11_LOD"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_09b_Emissive_11"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_CH2_09b_House08_LOD"));
//    }
//    if (flags & (1 << 10)) {
//        /*Stilt*/
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_09c_hs11"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("CH2_09c_Emissive_11_LOD"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("CH2_09c_Emissive_11"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_09c_hs11_details"));
//    }
//    if (flags & (1 << 11)) {
//        /*Stilt*/
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_05c_b4"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ch2_05c_decals_05"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ch2_05c_B4_LOD"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ch2_05c_emissive_07"));
//    }
//    if (flags & (1 << 12)) {
//        /*Stilt*/
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_09c_hs07"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ch2_09c_build_11_07_LOD"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("CH2_09c_Emissive_07_LOD"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_09c_build_11_07_LOD"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ch2_09c_hs07_details"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("CH2_09c_Emissive_07"));
//    }
//
//    if (flags & (1 << 13)) {
//        /*Stilt*/
//
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_09c_hs13"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_09c_hs13_details"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_CH2_09c_House11_LOD"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ch2_09c_Emissive_13_LOD"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ch2_09c_Emissive_13"));
//    }
//    if (flags & (1 << 14)) {
//        /*Stilt*/
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_09b_hs02"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_09b_hs02b_details"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_09b_Emissive_09_LOD"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ch2_09b_botpoolHouse02_LOD"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_09b_Emissive_09"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_09b_hs02_balcony"));
//    }
//    if (flags & (1 << 15)) {
//        /*Stilt*/
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_12b_house03mc"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ch2_12b_emissive_02"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ch2_12b_house03_MC_a_LOD"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ch2_12b_emissive_02_LOD"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ch2_12b_railing_06"));
//    }
//    if (flags & (1 << 16)) {
//        //STILT
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_04_house01"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_04_house01_d"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ch2_04_emissive_05_LOD"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ch2_04_M_b_LOD"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ch2_04_emissive_05"));
//        INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ch2_04_house01_details"));
//    }
//
//    GRAPHICS::DISABLE_OCCLUSION_THIS_FRAME();
//}
//
//void DisableDelPerro() {
//    DLC::ON_ENTER_MP();
//    HUD::THEFEED_FLUSH_QUEUE();
//    Vector2_t vec = { 0.55F, 0UL, 0.5F, 0UL };
//    RGBA_t b_RGBA = rgb_Create(0, 0, 0, 255);
//    static BOOL toggle = FALSE;
//
//    for (int i = 0; i < MISC::GET_GAME_TIMER(); i++) {
//        if (IsKeyJustUp(VK_ADD)) {
//            toggle = TRUE;
//        }
//        if (toggle == FALSE) { return; }
//        disable((1 << 3));
//        GRAPHICS::SET_SCRIPT_GFX_DRAW_ORDER(1);
//        box_Draw(box_Create(rgb_Create(255, 0, 0, 255), { vec.x, 0UL, vec.y + 0.019F , 0UL }, 0.0512F, 0.09F));
//        GRAPHICS::SET_SCRIPT_GFX_DRAW_ORDER(2);
//        t_Draw(t_Create("Del Perro Removed", 0, { vec.x, 0UL, vec.y + 0.019F, 0UL }, { 0,0,0,255 }, 0.513, FALSE, TRUE, TRUE));
//        /*Thread Controller For Adding back that side of the building and transfering ownership of the program to that thread.*/
//        if (IsKeyJustUp(VK_ADD)) {
//            int startTime = MISC::GET_GAME_TIMER();
//            int endTime = startTime + 2500;
//            while (MISC::GET_GAME_TIMER() < endTime) {
//                if (IsKeyJustUp(VK_ADD)) {
//                    toggle = TRUE;
//                    DisableDelPerro();
//                }
//                GRAPHICS::SET_SCRIPT_GFX_DRAW_ORDER(1);
//                box_Draw(box_Create(rgb_Create(255, 0, 0, 255), vec, 0.0512F, 0.09F));
//                GRAPHICS::SET_SCRIPT_GFX_DRAW_ORDER(2);
//                t_Draw(t_Create("NULL", 0, { vec.x, 0UL, vec.y, 0UL }, { 0,0,0,255 }, 0.513, FALSE, TRUE, TRUE));
//                WAIT(0);
//            }
//            THREAD_2();
//        }
//        WAIT(0);
//    }
//
//}
//
//BOOL DisableAllApartments(signed zxd) {
//    DLC::ON_ENTER_MP();
//    HUD::THEFEED_FLUSH_QUEUE();
//    Vector2_t vec = { 0.55F, 0UL, 0.5F, 0UL };
//    RGBA_t b_RGBA = rgb_Create(0, 0, 0, 255);
//
//    for (int i = 0; i < MISC::GET_GAME_TIMER(); i++) {
//        if (zxd != FALSE) {
//            disable((1 << 16) - 1);
//            GRAPHICS::SET_SCRIPT_GFX_DRAW_ORDER(1);
//            box_Draw(box_Create(rgb_Create(255, 0, 0, 255), vec, 0.0512F, 0.09F));
//            GRAPHICS::SET_SCRIPT_GFX_DRAW_ORDER(2);
//            t_Draw(t_Create("All Apartments Cleansed.", 0, { vec.x, 0UL, vec.y, 0UL }, { 0,0,0,255 }, 0.513, FALSE, TRUE, TRUE));
//
//            /*Thread Controller For Adding back that side of the building and transfering ownership of the program to that thread.*/
//            if (IsKeyJustUp(VK_DIVIDE)) {
//                int startTime = MISC::GET_GAME_TIMER();
//                int endTime = startTime + 2500;
//                zxd = FALSE;
//                while (MISC::GET_GAME_TIMER() < endTime) {
//                    if (IsKeyJustUp(VK_DIVIDE)) {
//                        zxd = TRUE;
//                        DisableAllApartments(zxd);
//                    }
//                    GRAPHICS::SET_SCRIPT_GFX_DRAW_ORDER(1);
//                    box_Draw(box_Create(rgb_Create(255, 0, 0, 255), vec, 0.0512F, 0.09F));
//                    GRAPHICS::SET_SCRIPT_GFX_DRAW_ORDER(2);
//                    t_Draw(t_Create("NULL", 0, { vec.x, 0UL, vec.y, 0UL }, { 0,0,0,255 }, 0.513, FALSE, TRUE, TRUE));
//                }
//
//                THREAD_2();
//            }
//        }
//        return zxd;
//        WAIT(0);
//    }
//    return NULL;
//}




/*After this Point is ALL BoxUI/Button/TextUI Code found within the main function.*/

//Vector2_t base = vec2_Create(0.163F, 0.201F);
//float scale = w + (h / 0.25F);
//BoxUI b1 = box_Create({ 0,0,0,0 }, base, w, h);
//BoxUI b2 = box_Create({ 0,0,0,0 }, base, w, h);
//BoxUI b3 = box_Create({ 0,0,0,0 }, base, w, h);
//BoxUI b4 = box_Create({ 0,0,0,0 }, base, w, h);
//BoxUI b5 = box_Create({ 0,0,0,0 }, base, w, h);
///*menuAction Takes a pointer to a Button because say if you wanted to modify the button's text to change the buttons colour or others you'd need this. This only works with the current indexed button that the user has selected and does NOT apply to anything else.*/
///*To as well preface. Ideally as well you should probably do a union inside the structure that can be used to represent different types of interactions like for example handling a menu change to a newly created menu etc. */
//
//Button button;
//for (int i = 0; i < MAX_LOBBY_SIZE; i++) {
//    if (NETWORK::NETWORK_IS_PLAYER_ACTIVE(i)) {
//        button = { t_Create((char*)PLAYER::GET_PLAYER_NAME(i), 0,base, {255,255,255,255},scale, FALSE, FALSE, FALSE), NULL, b1, FALSE, menuAction };
//    }
//}
//
//
//Button button2 = { t_Create("Activate Online Native", 0,base, {255,255,255,255},scale, FALSE, FALSE, FALSE), NULL, b2, FALSE,  menuAction2 };
//Button button3 = { t_Create((char*)boolO_STR(DLC::IS_DLC_PRESENT(MISC::GET_HASH_KEY("XX_I$RAWKST4H_D3V_XX"))), 0,base, {255,255,255,255},scale, FALSE, FALSE, FALSE), NULL, b3, FALSE,  menuAction2 };
//Button button4 = { t_Create("fourth", 0,base, {255,255,255,255},scale, FALSE, FALSE, FALSE),NULL, b4, FALSE,  menuAction2 };
//Button button5 = { t_Create("Time Modifier", 0,base, {255,255,255,255},scale, FALSE, FALSE, FALSE),NULL, b5, FALSE,  timeCycleModifier };
//
//
//MenuUI* menu = menu_Create();
//
//menu_AddOption(menu, &button);  //  1    Index: 0
//menu_AddOption(menu, &button2); //  2    Index: 1
//menu_AddOption(menu, &button3); //  3    Index: 2
//menu_AddOption(menu, &button4); //  4    Index: 3
//menu_AddOption(menu, &button5); //  5    Index: 4
//
//menu_Draw(menu, VK_DIVIDE);
//#define CHARZ "CHAR_ALL_PLAYERS_CONF"
//void updateBox(BoxUI* box, Vector2_t newPosition, float height, float width) {
//    box->drawPos = newPosition;
//
//    box->width = width;
//    box->height = height;
//
//    box->topLeft.x = box->drawPos.x - (box->width / 2.0F);
//    box->topLeft.y = box->drawPos.y - (box->height / 2.0F);
//
//    box->bottomLeft.x = box->topLeft.x;
//    box->bottomLeft.y = box->topLeft.y + box->height;
//
//    box->topRight.x = box->topLeft.x + box->width;
//    box->topRight.y = box->topLeft.y;
//
//    box->bottomRight.x = box->topRight.x;
//    box->bottomRight.y = box->topRight.y + box->height;
//    return;
//}
//void menu_Action_TIMER(Button* ptr) {
//    return;
//}
//void button_CanBeSelected(Button* ptr, int duration) {
//    int endTime = MISC::GET_GAME_TIMER() + duration;
//    RGBA_t preChangeColour = ptr->leftText->colour;
//    void(*PreChangeButtonFunc)(Button*) = ptr->OnClickInteraction;
//    ptr->OnClickInteraction = menu_Action_TIMER;
//    ptr->leftText->colour = { 64,64,64,255 };
//    if (MISC::GET_GAME_TIMER() > endTime - 1) {
//        ptr->leftText->colour = preChangeColour;
//        ptr->OnClickInteraction = PreChangeButtonFunc;
//    }
//}
//void invert_Colours(Button* ptr) {
//    ptr->leftText->colour = { 0,0,0,255 };
//    ptr->box.colour = { 0,0,156,ptr->box.colour.a };
//    return;
//}
//void timeCycleModifier(Button* ptr) {
//
//    GRAPHICS::SET_TIMECYCLE_MODIFIER("DLC_Island_main_hanger");
//    GRAPHICS::SET_TIMECYCLE_MODIFIER_STRENGTH(1);
//
//    return;
//}
//void menuAction(Button* ptr) {
//    SCRIPT::REQUEST_SCRIPT("fm_content_drug_vehicle");
//
//    if (SCRIPT::HAS_SCRIPT_LOADED("fm_content_drug_vehicle")) {
//        int reqID = SYSTEM::START_NEW_SCRIPT("fm_content_drug_vehicle", 5000);
//        ptr->box.colour = { 0,255,0,255 };
//        //strncpy(ptr->leftText->text, util_IntToStr(reqID), 64);
//        //ptr->leftText->text = util_FloatToStr(reqID);
//        WAIT(0);
//        return;
//    }
//    ptr->box.colour = { 255,0,0,255 };
//
//}
//void menuAction2(Button* ptr) {
//    DLC::ON_ENTER_MP();
//}
//
//constexpr int MAX_LOBBY_SIZE = 30;
//float h = 0.034F, w = 0.2249F;
