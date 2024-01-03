#pragma once
#include "utils.h"
#define BASE_TEXT_BUFF 64
typedef enum __menu_input_base__ {
	controller_ARROWS = 2, controller_MOUSE = 4, controller_ARROWS_AND_MOUSE = 8
}MenuInputType;

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
	BoxUI box;
	BOOL_t isSelected;
	MenuAction onClickInteraction;
}Button;
typedef struct listBase {
	size_t compacity;
	size_t size;
	size_t stride;
	void** array;
}List;
typedef struct{
	char title[16];
	char description[64];
	//__menu_utils__** subMenus;
	List b; // Defines a buttonList
	Button	selectionButton;
	int currentIndex;
	int prevIndex;
	int nextIndex;
	MenuInputType controllerType;
	BOOL_t doesHaveArrows;
	BOOL_t doesHaveHeader;
	BOOL_t isVisible;
}MenuUI;

typedef void TextHandle;
typedef void BoxHandle;
typedef void ButtonHandle;
typedef void HeaderHandle;
typedef void MenuHandle;

extern void selButton_Custom(MenuUI* ptr, TextUI* text, BoxUI box);

extern MenuUI* menu_Create();
extern void menu_AddOption(MenuUI* handle, Button* bHandle);
extern void menu_Switch(MenuUI* primaryMenu, MenuUI* newMenu);
extern void menu_Draw(MenuUI* ptr, DWORD_t toggleKey);
extern void menu_CancelDraw(MenuUI* ptr);

extern TextUI* t_Create(char* text, int font, Vector2_t position, RGBA_t textColour, float size, BOOL_t doesOutline, BOOL_t hasDropShadow, BOOL_t isCentered);
extern void t_Draw(TextUI* handle);
extern void t_Destroy(TextUI* handle);
/*
* @brief If you are using this function for creating boxes for menus if I never wrap it. the box's Position can be the same as the previous box because I implemented a fix in  menu_AddOption().
*/
extern BoxUI box_Create(RGBA_t boxColour, Vector2_t boxPosition = { NULL, NULL, NULL, NULL }, float width = 0.0F, float height = 0.0F);
extern void box_Draw(BoxUI box);
extern void box_Destroy(BoxHandle* handle);


extern Button* button_Create(BoxUI box, TextUI* const leftText, TextUI* const rightText = t_Create("NULL", 0, { 0,0,0,0 }, { 255,0,0,255 }, 0.532, FALSE_, FALSE_, FALSE_));
extern void button_TextModify(ButtonHandle* handle, TextUI* newText, BOOL_t isRightText = FALSE_);
extern void button_Draw(Button ptr);
extern void button_Destroy(ButtonHandle* handle);


extern void button_Text_Draw(Button b, BOOL_t isRight);
extern BOOL_t isPointInsideBox(float x, float y, BoxUI* box);

extern List list_Create(size_t compacity, size_t stride);
extern void list_Add(List* list, void* data);
extern void list_Remove(List* wrapper, int index);
typedef void(*ListFunc)();
extern void list_Iterate(List* wrapper, ListFunc function);
extern size_t list_Size(const List* list);
extern size_t list_Compacity(const List* list);
extern void list_Clear(List* wrapper);
#undef MAX_BUFF