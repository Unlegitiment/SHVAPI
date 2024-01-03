#include "..\Menu.h"
#include "../ScriptHookV/natives.h"
#include "../ScriptHookV/enums.h"
#define BASE_TEXT_BUFF 64
TextUI* t_Create(char* text, int font, Vector2_t position, RGBA_t textColour, float size, BOOL_t doesOutline, BOOL_t hasDropShadow, BOOL_t isCentered) {
	TextUI* z = (TextUI*)malloc(sizeof(TextUI));
	if (z == NULL) { return NULL; }
	strncpy(z->text, text, 62);
	z->text[63] = '\0';
	z->position = position;
	z->font = (eFont)font;
	z->size = size;
	z->colour = textColour;
	z->hasDropshadow = hasDropShadow;
	z->isCenter = isCentered;
	z->hasOutline = doesOutline;
	return z;
}
void t_Draw_NoFree(TextUI* handle) {
	if (handle == NULL) return;
	HUD::SET_TEXT_FONT(handle->font);
	HUD::SET_TEXT_SCALE(1.0F, handle->size);
	if (handle->hasOutline) {
		HUD::SET_TEXT_OUTLINE();
	}
	if (handle->hasDropshadow) {
		HUD::SET_TEXT_DROP_SHADOW();
	}
	HUD::SET_TEXT_WRAP(0, 1);
	HUD::SET_TEXT_JUSTIFICATION(1);

	HUD::SET_TEXT_LEADING(1);
	HUD::SET_TEXT_CENTRE(handle->isCenter);
	HUD::SET_TEXT_COLOUR((int)handle->colour.r, (int)handle->colour.g, (int)handle->colour.b, (int)handle->colour.a);
	HUD::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
	HUD::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(handle->text);
	HUD::END_TEXT_COMMAND_DISPLAY_TEXT(handle->position.x, handle->position.y, 1);
	return;
}
void t_Draw(TextUI* handle) {
	HUD::SET_TEXT_FONT(handle->font);
	HUD::SET_TEXT_SCALE(1.0F, handle->size);
	if (handle->hasOutline) {
		HUD::SET_TEXT_OUTLINE();
	}
	if (handle->hasDropshadow) {
		HUD::SET_TEXT_DROP_SHADOW();
	}
	HUD::SET_TEXT_WRAP(0, 1);
	HUD::SET_TEXT_JUSTIFICATION(1);
	HUD::SET_TEXT_LEADING(1);
	HUD::SET_TEXT_CENTRE(handle->isCenter);
	HUD::SET_TEXT_COLOUR((int)handle->colour.r, (int)handle->colour.g, (int)handle->colour.b, (int)handle->colour.a);
	HUD::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
	HUD::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(handle->text);
	HUD::END_TEXT_COMMAND_DISPLAY_TEXT(handle->position.x, handle->position.y, 1);
	t_Destroy(handle);
	return;
}
void t_Destroy(TextUI* handle) {
	free(handle);
	return;
}
BOOL_t doVector2Equal(Vector2_t v1, Vector2_t v2) {
	if (v1.x == v2.x && v1.y == v2.y && v1._paddingX_ == v2._paddingX_ && v1._paddingY_ == v2._paddingY_) return TRUE_;
	return FALSE_;
}
BoxUI box_Create(RGBA_t boxColour, Vector2_t boxPosition, float width, float height) {
	Vector2_t nullPos = { NULL, NULL, NULL, NULL };
	BoxUI box{};

	box.colour = boxColour;
	box.drawPos = boxPosition;
	if (doVector2Equal(boxPosition, nullPos)) {
		box.drawPos.x = 0.09;
		box.drawPos.y = 0.109;
	}

	box.height = height;
	box.width = width;

	box.topLeft.x = box.drawPos.x - (box.width / 2.0F);
	box.topLeft.y = box.drawPos.y - (box.height / 2.0F);

	box.bottomLeft.x = box.topLeft.x;
	box.bottomLeft.y = box.topLeft.y + box.height;

	box.topRight.x = box.topLeft.x + box.width;
	box.topRight.y = box.topLeft.y;

	box.bottomRight.x = box.topRight.x;
	box.bottomRight.y = box.topRight.y + box.height;

	return box;
}
void box_Draw(BoxUI box) {
	GRAPHICS::DRAW_RECT(box.drawPos.x, box.drawPos.y, box.width, box.height, (int)box.colour.r, (int)box.colour.g, (int)box.colour.b, (int)box.colour.a, TRUE);
	return;
}
void box_Destroy(BoxHandle* handle) {
	if (handle == NULL)return;
	BoxUI* box = (BoxUI*)handle;
	free(box);
	return;
}
/*
* We're changing where they are pointing to by freeing the memory however the box doesn't need to be freed because its so small in comparison and its not dynamically hosted
*/
Button* button_Create(BoxUI box, TextUI* const leftText, TextUI* const rightText) {
	Button* b = (Button*)malloc(sizeof(Button));
	if (b == NULL) return NULL;
	b->box = box;
	b->leftText = leftText;
	b->rightText = rightText;
	t_Destroy(leftText);
	t_Destroy(rightText);
	return b;
}
void button_TextModify(ButtonHandle* handle, TextUI* newText, BOOL_t isRightText) {
	if (handle == NULL) return;
	Button* b = (Button*)handle;
	if (isRightText) {
		free(b->rightText);
		b->rightText = newText;
		return;
	}
	else {
		free(b->leftText);
		b->leftText = newText;
		return;
	}
}
void button_Text_Draw(Button b, BOOL_t isRight) {
	TextUI* handle = NULL;
	if (!isRight && b.rightText == NULL) {
		handle = b.leftText;
	}
	if (isRight) {
		handle = b.rightText;
	}
	else {
		handle = b.leftText;
	}
	if (handle == NULL) {
		return;
	}
	HUD::SET_TEXT_FONT(handle->font);
	HUD::SET_TEXT_SCALE(1.0F, handle->size);
	if (handle->hasOutline) {
		HUD::SET_TEXT_OUTLINE();
	}
	if (handle->hasDropshadow) {
		HUD::SET_TEXT_DROP_SHADOW();
	}
	HUD::SET_TEXT_LEADING(1);
	HUD::SET_TEXT_CENTRE(handle->isCenter);
	HUD::SET_TEXT_COLOUR((int)handle->colour.r, (int)handle->colour.g, (int)handle->colour.b, (int)handle->colour.a);
	HUD::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
	HUD::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(handle->text);
	if (isRight) {
		HUD::SET_TEXT_WRAP(b.box.drawPos.x, b.box.drawPos.x + (b.box.width/2.0F));
		HUD::SET_TEXT_JUSTIFICATION(2);
		HUD::END_TEXT_COMMAND_DISPLAY_TEXT(b.box.topRight.x, b.box.topRight.y + (b.box.height / 10.0F), 1);
	}
	else {
		HUD::END_TEXT_COMMAND_DISPLAY_TEXT(b.box.topLeft.x + 0.003F, b.box.topLeft.y + (b.box.height / 10.0F), 1);
	}
	return;
}

void button_Draw(Button ptr) {
	box_Draw(ptr.box);
	t_Draw_NoFree(ptr.leftText);
	t_Draw_NoFree(ptr.rightText);
	ptr.isSelected = FALSE;
	return;
}
void button_Destroy(ButtonHandle* handle) {
	if (handle == NULL) { return; }
	Button* b = (Button*)handle;
	t_Destroy(b->leftText);
	t_Destroy(b->rightText);
	free(b);
	return;
}

BOOL_t isPointInsideBox(float x, float y, BoxUI* box) {
	if (x >= box->topLeft.x && x <= box->bottomRight.x) {
		if (y >= box->topLeft.y && y <= box->bottomRight.y) {
			return TRUE;
		}
	}
	return FALSE;
}

void selButton_Custom(MenuUI* ptr, TextUI* text, BoxUI box)
{
	return;
}
MenuUI* menu_Create(){
	MenuUI* menu = (MenuUI*)malloc(sizeof(MenuUI));
	if (menu == NULL) return NULL;
	memset(menu, 0, sizeof(MenuUI));
	menu->b = list_Create(1, sizeof(Button*));
	menu->currentIndex = 0;
	menu->nextIndex = 1;
	menu->prevIndex = -1;
	menu->doesHaveArrows = FALSE;
	menu->doesHaveHeader = FALSE;
	menu->isVisible = FALSE;
	menu->selectionButton = { t_Create("NULL", 0, { 0,0,0,0 }, { 0,0,0,0 }, 0, FALSE, FALSE, FALSE) ,t_Create("NULL", 0, { 0,0,0,0 }, { 0,0,0,0 }, 0, FALSE, FALSE, FALSE), box_Create({ 255,255,255,0}, {0,0,0,0},0,0), FALSE, NULL};
	return menu;
}
void UI_DrawVector(Vector2_t vec) {
	char* vecX = util_FloatToStr(vec.x);
	char* vecY = util_FloatToStr(vec.y);
	char* finalStr = (char*)malloc(sizeof(char) * 64);
	if (finalStr == NULL) return;
	memset(finalStr, 0, sizeof(finalStr));
	strcpy(finalStr, "X: ");
	strcat(finalStr, vecX);
	strcat(finalStr, " Y: ");
	strcat(finalStr, vecY);
	finalStr[63] = '\0';
	HUD::BEGIN_TEXT_COMMAND_THEFEED_POST("STRING");
	HUD::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(finalStr);
	HUD::END_TEXT_COMMAND_THEFEED_POST_TICKER(FALSE, FALSE);
	free(finalStr);
}
#include "..\UI.h"
void menu_UpdateBoxPositions(Button* ptr, Vector2_t newPosition) {
	ptr->box.drawPos			= newPosition;
	ptr->box.topLeft.x			= ptr->box.drawPos.x - (ptr->box.width / 2.0F);
	ptr->box.topLeft.y			= ptr->box.drawPos.y - (ptr->box.height / 2.0F);
	ptr->box.bottomLeft.x		= ptr->box.topLeft.x;
	ptr->box.bottomLeft.y		= ptr->box.topLeft.y + ptr->box.height;
	ptr->box.topRight.x			= ptr->box.topLeft.x + ptr->box.width;
	ptr->box.topRight.y			= ptr->box.topLeft.y;
	ptr->box.bottomRight.x		= ptr->box.topRight.x;
	ptr->box.bottomRight.y		= ptr->box.topRight.y + ptr->box.height;
}
void menu_AddOption(MenuUI* handle, Button* bHandle) {
	Button** buttons = (Button**)handle->b.array;
	int i = 0;
	for (; i < handle->b.size; i++) {
		if (vec2_Comp(bHandle->box.drawPos, buttons[i]->box.drawPos)) {
			menu_UpdateBoxPositions(bHandle, { buttons[i]->box.drawPos.x, 0UL, buttons[i]->box.drawPos.y + bHandle->box.height, 0UL } );
		}
	}
	list_Add(&handle->b, bHandle);
	return;
}
/*Unimplemented Now. Test.*/
void menu_Switch(MenuUI* primaryMenu, MenuUI* newMenu) {
	primaryMenu->isVisible = FALSE; //cancel previous's draw.
	menu_Draw(newMenu, NULL); // switch Draw.
	return;
}
static int index;
void nullFunc() {
	HUD::THEFEED_FLUSH_QUEUE();
	HUD::BEGIN_TEXT_COMMAND_THEFEED_POST("STRING");
	HUD::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("~r~Unimplemented Item!");
	HUD::END_TEXT_COMMAND_THEFEED_POST_TICKER(TRUE, FALSE);
	return;
}




#define USES_WINDOWS_H
#ifdef USES_WINDOWS_H
#include "..\keyboard.h"

void menu_Logic(MenuUI* ptr, MenuInputType controller) {
	Button** buttons = (Button**)ptr->b.array;

	float x;
	float y;
	UI_DrawText(util_IntToStr(ptr->currentIndex), { 0.3,0,0.3,0 });
	switch (controller) {
	case controller_ARROWS:
		for (int i = 0; i < ptr->b.size; i++) {
			char* temp = buttons[i]->leftText->text;
			if (IsKeyJustUp(VK_DOWN)) {
				ptr->currentIndex++;
			}
			if (ptr->currentIndex > ptr->b.size || ptr->currentIndex == ptr->b.size) {
				ptr->currentIndex = 0;
			}

			if (IsKeyJustUp(VK_UP)) {
				if (ptr->currentIndex == 0) {
					ptr->currentIndex = (int)ptr->b.size;
				}
				ptr->currentIndex--;
			}
			if (IsKeyJustUp(VK_RETURN)) {
				buttons[ptr->currentIndex]->onClickInteraction();
			}
		}
			ptr->selectionButton.box = box_Create({ 255,255,255,200 }, buttons[ptr->currentIndex]->box.drawPos, buttons[ptr->currentIndex]->box.width, buttons[ptr->currentIndex]->box.height);
			ptr->selectionButton.leftText = t_Create(buttons[ptr->currentIndex]->leftText->text, buttons[ptr->currentIndex]->leftText->font, buttons[ptr->currentIndex]->leftText->position, { 255,0,0,255 }, buttons[ptr->currentIndex]->leftText->size, buttons[ptr->currentIndex]->leftText->hasOutline, buttons[ptr->currentIndex]->leftText->hasDropshadow, buttons[ptr->currentIndex]->leftText->isCenter);
			if (buttons[ptr->currentIndex]->rightText != NULL) {
				ptr->selectionButton.rightText = t_Create(buttons[ptr->currentIndex]->rightText->text, buttons[ptr->currentIndex]->rightText->font, buttons[ptr->currentIndex]->rightText->position, { 0,0,0,255 }, buttons[ptr->currentIndex]->rightText->size, buttons[ptr->currentIndex]->rightText->hasOutline, buttons[ptr->currentIndex]->rightText->hasDropshadow, buttons[ptr->currentIndex]->rightText->isCenter);
			}	break;
	case controller_MOUSE:
		HUD::SET_MOUSE_CURSOR_THIS_FRAME();
		y = PAD::GET_CONTROL_NORMAL(0, 240);
		x = PAD::GET_CONTROL_NORMAL(0, 239);
		for (int i = 0; i < ptr->b.size; i++) {
			char* temp = buttons[i]->leftText->text;
			Button button = {};
			if (isPointInsideBox(x, y, &buttons[i]->box)) {
				ptr->currentIndex = i;
				if (buttons[ptr->currentIndex]->onClickInteraction == nullFunc) {
					strncpy(buttons[ptr->currentIndex]->leftText->text, "Unimplemented Item\0", 64);
				}
				if (PAD::IS_DISABLED_CONTROL_JUST_PRESSED(0, 237)) {
					buttons[ptr->currentIndex]->onClickInteraction();
				}
				ptr->selectionButton.box = box_Create({ 255,255,255,200 }, buttons[ptr->currentIndex]->box.drawPos, buttons[0]->box.width, buttons[0]->box.height);
				ptr->selectionButton.leftText = t_Create(buttons[ptr->currentIndex]->leftText->text, buttons[ptr->currentIndex]->leftText->font, buttons[ptr->currentIndex]->leftText->position, { 0,0,0,255 }, buttons[ptr->currentIndex]->leftText->size, buttons[ptr->currentIndex]->leftText->hasOutline, buttons[ptr->currentIndex]->leftText->hasDropshadow, buttons[ptr->currentIndex]->leftText->isCenter);
				if (buttons[i]->rightText != NULL) {
					ptr->selectionButton.rightText = t_Create(buttons[ptr->currentIndex]->rightText->text, buttons[ptr->currentIndex]->rightText->font, buttons[ptr->currentIndex]->rightText->position, { 0,0,0,255 }, buttons[ptr->currentIndex]->rightText->size, buttons[ptr->currentIndex]->rightText->hasOutline, buttons[ptr->currentIndex]->rightText->hasDropshadow, buttons[ptr->currentIndex]->rightText->isCenter);
				}
			}
			else {
				//ptr->selectionButton = { t_Create("NULL", 0, { 0,0,0,0 }, { 0,0,0,0 }, 0, FALSE, FALSE, FALSE) ,t_Create("NULL", 0, { 0,0,0,0 }, { 0,0,0,0 }, 0, FALSE, FALSE, FALSE), box_Create({ 255,255,255,0}, {0,0,0,0},0,0), FALSE, NULL };
				strncpy(buttons[ptr->currentIndex]->leftText->text, temp, 64);
			}
		}
		break;
	case controller_ARROWS_AND_MOUSE:
		HUD::SET_MOUSE_CURSOR_THIS_FRAME();
		Vector2_t mouse_Coordinates = { PAD::GET_CONTROL_NORMAL(0,239), 0UL, PAD::GET_CONTROL_NORMAL(0,240), 0UL };
		for (int i = 0; i < ptr->b.size; i++) {

			if (isPointInsideBox(mouse_Coordinates.x, mouse_Coordinates.y, &buttons[i]->box)) {
				ptr->currentIndex = i;
				if (PAD::IS_CONTROL_JUST_PRESSED(0, 237) || PAD::IS_DISABLED_CONTROL_JUST_PRESSED(0, 237)) {
					buttons[ptr->currentIndex]->onClickInteraction();
				}
			}
			if (IsKeyJustUp(VK_UP)) {
				if (ptr->currentIndex == 0) {
					ptr->currentIndex = (int)ptr->b.size;
				}
				ptr->currentIndex--;
			}
			if (IsKeyJustUp(VK_DOWN)) {
				ptr->currentIndex++;
			}
			if (ptr->currentIndex > ptr->b.size || ptr->currentIndex == ptr->b.size) {
				ptr->currentIndex = 0;
			}
			if (IsKeyJustUp(VK_RETURN)) {
				buttons[ptr->currentIndex]->onClickInteraction();
			}
			buttons[ptr->currentIndex]->box.drawPos;
			ptr->selectionButton.box = box_Create({ 255,255,255,200 }, buttons[ptr->currentIndex]->box.drawPos, buttons[0]->box.width, buttons[0]->box.height);
			ptr->selectionButton.leftText = t_Create(buttons[ptr->currentIndex]->leftText->text, buttons[ptr->currentIndex]->leftText->font, buttons[ptr->currentIndex]->leftText->position, { 0,0,0,255 }, buttons[ptr->currentIndex]->leftText->size, buttons[ptr->currentIndex]->leftText->hasOutline, buttons[ptr->currentIndex]->leftText->hasDropshadow, buttons[ptr->currentIndex]->leftText->isCenter);
			if (buttons[i]->rightText != NULL) {
				ptr->selectionButton.rightText = t_Create(buttons[ptr->currentIndex]->rightText->text, buttons[ptr->currentIndex]->rightText->font, buttons[ptr->currentIndex]->rightText->position, { 0,0,0,255 }, buttons[ptr->currentIndex]->rightText->size, buttons[ptr->currentIndex]->rightText->hasOutline, buttons[ptr->currentIndex]->rightText->hasDropshadow, buttons[ptr->currentIndex]->rightText->isCenter);
			}
		}
		break;
	}
	return;
}
#endif
/*So notes for tomorrow
Potentially going to have to employ a Doubly Linked List to keep track of the various submenus. However either way its going to be a clusterfuck at the begining.
Not sure how ScaleformUI did it however I think they used a internal Tuple.
*/
/*Main Loop where everything is finally ran for the user.*/
void menu_Draw(MenuUI* ptr, DWORD_t toggleKey) {
	ptr->isVisible = TRUE;
	while (ptr->isVisible) {
		PAD::DISABLE_ALL_CONTROL_ACTIONS(0);
		PAD::ENABLE_CONTROL_ACTION(0, 239, 0);
		PAD::ENABLE_CONTROL_ACTION(0, 240, 0);
		Button** buttons = (Button**)ptr->b.array;
		menu_Logic(ptr, controller_ARROWS_AND_MOUSE);
		BoxUI background;
		if (ptr->b.size % 2) {
			background = box_Create(rgb_Create(0, 0, 0, 125), { buttons[0]->box.drawPos.x, 0UL, buttons[ptr->b.size / 2 - 1]->box.drawPos.y + buttons[0]->box.height, 0UL }, buttons[0]->box.width, ((buttons[0]->box.height * ptr->b.size)));
		}
		else {
			background = box_Create(rgb_Create(0, 0, 0, 125), { buttons[0]->box.drawPos.x, 0UL, buttons[ptr->b.size / 2 - 1]->box.drawPos.y + (buttons[0]->box.height / 2.0F), 0UL}, buttons[0]->box.width, ((buttons[0]->box.height * ptr->b.size)));
		}
		GRAPHICS::SET_SCRIPT_GFX_DRAW_ORDER(5);
		box_Draw(background);
		/*Where issue is for somereason.*/
		for (int i = 0; i < ptr->b.size; i++) {
			GRAPHICS::SET_SCRIPT_GFX_DRAW_ORDER(6);
			box_Draw(buttons[i]->box);
			GRAPHICS::SET_SCRIPT_GFX_DRAW_ORDER(7);
			button_Text_Draw(*buttons[i], FALSE);
			button_Text_Draw(*buttons[i], TRUE);
		}
		GRAPHICS::SET_SCRIPT_GFX_DRAW_ORDER(8);

		box_Draw(ptr->selectionButton.box);
		button_Text_Draw(ptr->selectionButton, FALSE);
		button_Text_Draw(ptr->selectionButton, TRUE);
		/*CleanUp*/

		if (IsKeyJustUp((DWORD)toggleKey) || IsKeyJustUp(VK_BACK) || IsKeyJustUp(VK_ESCAPE)) {
			ptr->currentIndex = 0;
			for (int i = 0; i < ptr->b.size; i++) {
				free(buttons[i]->leftText);
				if (buttons[i]->rightText != NULL) {
					free(buttons[i]->rightText);
				}
			}
			list_Clear(&ptr->b);
			ptr->isVisible = FALSE;
		}
		WAIT(0);
	}
	return;
}
void menu_CancelDraw(MenuUI* ptr) {
	ptr->isVisible = FALSE;
	return;
}