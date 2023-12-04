#include "..\Menu.h"
#include "../ScriptHookV/natives.h"
#include "../ScriptHookV/enums.h"
#define BASE_TEXT_BUFF 64
typedef float f32;
typedef double f64;
/*
* Make it so that maybe the Button has the action tied to the struct? like a callback?
*/


TextUI* t_Create(
	char* text, 
	int font, 
	Vector2_t position, 
	RGBA_t textColour, 
	float size, 
	BOOL_t doesOutline, 
	BOOL_t hasDropShadow, 
	BOOL_t isCentered) {

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
	HUD::SET_TEXT_COLOUR(handle->colour.r, handle->colour.g, handle->colour.b, handle->colour.a);
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
	HUD::SET_TEXT_COLOUR(handle->colour.r, handle->colour.g, handle->colour.b, handle->colour.a);
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
	
	GRAPHICS::DRAW_RECT(box.drawPos.x, box.drawPos.y, box.width, box.height, box.colour.r, box.colour.g, box.colour.b, box.colour.a, TRUE);
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
Button* button_Create(BoxUI* box, TextUI* const leftText, TextUI* const rightText) {
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
	if (isRight && b.rightText == NULL) {
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
	HUD::SET_TEXT_COLOUR(handle->colour.r, handle->colour.g, handle->colour.b, handle->colour.a);
	HUD::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
	HUD::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(handle->text);

	//changed from t_Draw();
	if (isRight) {
		HUD::SET_TEXT_WRAP(b.box->drawPos.x, b.box->drawPos.x + (b.box->width/2.0F));
		HUD::SET_TEXT_JUSTIFICATION(2);
		HUD::END_TEXT_COMMAND_DISPLAY_TEXT(b.box->topRight.x, b.box->topRight.y + (b.box->height /5.0F), 1);
	}
	else {
		HUD::END_TEXT_COMMAND_DISPLAY_TEXT(b.box->topLeft.x, b.box->topLeft.y + (b.box->height / 5.0F),1);
	}
	return;
}

void button_Draw(Button ptr) {
	box_Draw(*ptr.box);
	t_Draw_NoFree(ptr.leftText);
	t_Draw_NoFree(ptr.rightText);
	ptr.isSelected = FALSE;
	return;
}
void button_Destroy(ButtonHandle* handle) {
	if (handle == NULL) { return; }
	Button* b = (Button*)handle;
	t_Destroy(b->leftText);/*we free the memory and return*/
	t_Destroy(b->rightText);
	free(b);
	return;
}

/*We need to create a ButtonArray and use pointer arth to prob determine stuff That or make a static list at first for the UI_Menu item(s)*/
typedef struct {

};
typedef struct {
	Button* b[10]; // Defines a array of 10 buttons
	int currentIndex;
	int prevIndex;
	int nextIndex;
	int currentBSize;
}MenuUI;

MenuHandle* menu_Create(ButtonHandle* firstButton) {
	
	if (firstButton == NULL) {
		firstButton = button_Create(&box_Create({ 255,0,0,255 }, {}, 0.5, 0.5), t_Create("firstButton NULL", 0, { 0,0,0,0 }, { 0,0,0,0 }, 1, FALSE, FALSE, FALSE), {});
	}
	Button* iButton = (Button*)firstButton;

	MenuUI* menu = (MenuUI*)malloc(sizeof(MenuUI));
	if (menu == NULL) return NULL;
	menu->b[0] = iButton;
	menu->currentBSize = 0;
	menu->currentIndex = 0;
	menu->nextIndex = 1;
	menu->prevIndex = -1;
	return (MenuHandle*)menu;
}
void menu_AddOption(MenuHandle* handle, ButtonHandle* bHandle) {

}
