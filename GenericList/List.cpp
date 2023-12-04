#include <stdlib.h>
#include "..\Menu.h"
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
	wrapper.array = (Button*)malloc(compacity*sizeof(Button));
	if (wrapper.array == NULL) {
		ButtonList empty = { 0 };
		return empty;
	}
	wrapper.compacity = compacity;
	wrapper.size = 0;
	wrapper.stride = stride;
	return wrapper;
}
void list_Add(ButtonList* list, Button* data) {
	if (list == NULL || data == NULL) return;
	if (list->stride < sizeof(data)) { // if the size of the data is greater than the element index we return;
		return;
	}
	size_t offset = list->size * list->stride;
	if (list->size > 0) {
		Button* button = (Button*)list->array + offset; 
		button = data;
		list->size++;
	}
	else {
		list->array = data;
		list->size++;
	}
	return;
}
size_t list_Size(const ButtonList* list) {
	return list->size;
}
size_t list_Compacity(const ButtonList* list) {
	return list->compacity;
}