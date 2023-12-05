#include <stdlib.h>
#include "..\Menu.h"
#include "..\UI.h"

void list_Extend(ButtonList* list) {
	if (list == NULL) return;
	if (list->array == NULL) return;
	if (list->compacity <= list->size) {
		UI_DrawNotificationSTR("reallocing");
		Button** newList = (Button**)realloc(list->array, sizeof(Button*) * list->compacity * 2);
		if (newList == NULL) {
			return;
			UI_DrawNotificationSTR("Realloc failed");
		}
		UI_DrawNotificationSTR("~g~Reallocing success");
		list->array = newList;
		list->compacity *= 2;
	}
	return;
}
ButtonList list_Create(size_t compacity, size_t stride) {
	if (compacity < 0) {
		ButtonList emptyWrapper = { 0 };
		return emptyWrapper;
	}
	if (stride < 0) {
		ButtonList emptyWrapper = { 0 };
		return emptyWrapper;
	}
	ButtonList wrapper = { 0 };
	wrapper.array = (Button**)malloc(compacity*sizeof(Button));
	if (wrapper.array == NULL) {
		ButtonList empty = { 0 };
		return empty;
	}
	wrapper.compacity = compacity;
	wrapper.size = 0;
	wrapper.stride = stride;
	return wrapper;
}
size_t list_Size(const ButtonList* list) {
	return list->size;
}
size_t list_Compacity(const ButtonList* list) {
	return list->compacity;
}
void list_Add(ButtonList* wrapper, Button* data) {
	if (wrapper == NULL || data == NULL) return;
	if (wrapper->array == NULL) return;
	list_Extend(wrapper);
	size_t offset = wrapper->size * wrapper->stride;
	if (wrapper->size > 0) {
		//UI_DrawNotificationF(wrapper->size);
		wrapper->array[wrapper->size] = data;
		wrapper->size++;
		return;
	}else {
		//UI_DrawNotificationF(wrapper->size);
		wrapper->array[0] = data;
		wrapper->size++;
		return;
	}


}
void list_Remove(ButtonList* wrapper, int index) {
	if (wrapper == NULL || index < -1) return;
	if (index > wrapper->size - 1) return;
	memset(&wrapper->array[index], 0, wrapper->stride);
	wrapper->size--;
	return;
}
void list_Clear(ButtonList* wrapper) {
	wrapper->size = 0;
	wrapper->stride = 0;
	wrapper->compacity = 0;
	free(wrapper->array);
}
void list_Iterate(ButtonList* wrapper, ListFunc function) {
	if (wrapper == NULL) return;
	if (wrapper->array == NULL) return;
	for (int i = 0; i < wrapper->size; i++) {
		function();
	}
}
