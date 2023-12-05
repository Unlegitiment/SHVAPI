#pragma once
#include "utils.h"
#define BASE_TEXT_BUFF 64


typedef struct {
	char text[BASE_TEXT_BUFF];
	Vector2_t position;
	float size;
	int font;
	RGBA_t colour;
	BOOL_t hasOutline;
	BOOL_t hasDropshadow;
	BOOL_t isCenter;
	BOOL_t isDrawn;
}TextUI;
typedef struct {
	Vector2_t drawPos;
	Vector2_t topLeft;
	Vector2_t bottomLeft;
	Vector2_t topRight;
	Vector2_t bottomRight;
	RGBA_t colour;
	float height, width;
}BoxUI;
typedef void(*MenuAction)();
typedef struct {
	TextUI* leftText;
	TextUI* rightText;
	BoxUI* box;
	BOOL_t isSelected;
	MenuAction onClickInteraction;
}Button;

typedef void TextHandle;
typedef void BoxHandle;
typedef void ButtonHandle;
typedef void HeaderHandle;
typedef void MenuHandle;



extern MenuHandle* menu_Create(ButtonHandle* firstButton);


extern TextUI* t_Create(char* text, int font, Vector2_t position, RGBA_t textColour, float size, BOOL_t doesOutline, BOOL_t hasDropShadow, BOOL_t isCentered);
extern void t_Draw(TextUI* handle);
extern void t_Destroy(TextUI* handle);

extern BoxUI box_Create(RGBA_t boxColour, Vector2_t boxPosition = { NULL, NULL, NULL, NULL }, float width = 0.0F, float height = 0.0F);
extern void box_Draw(BoxUI box);
extern void box_Destroy(BoxHandle* handle);


extern Button* button_Create(BoxUI* box, TextUI* const leftText, TextUI* const rightText = t_Create("NULL", 0, { 0,0,0,0 }, { 255,0,0,255 }, 0.532, FALSE_, FALSE_, FALSE_));
extern void button_TextModify(ButtonHandle* handle, TextUI* newText, BOOL_t isRightText = FALSE_);
extern void button_Draw(Button ptr);
extern void button_Destroy(ButtonHandle* handle);

extern void button_Text_Draw(Button b, BOOL_t isRight);

typedef struct listBase {
	size_t compacity;
	size_t size;
	size_t stride;
	Button** array;
}ButtonList;
extern ButtonList list_Create(size_t compacity, size_t stride);
extern void list_Add(ButtonList* list, Button* data);
extern void list_Remove(ButtonList* wrapper, int index);
typedef void(*ListFunc)();
extern void list_Iterate(ButtonList* wrapper, ListFunc function);
extern size_t list_Size(const ButtonList* list);
extern size_t list_Compacity(const ButtonList* list);
#undef MAX_BUFF