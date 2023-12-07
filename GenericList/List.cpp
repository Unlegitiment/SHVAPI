#include <stdlib.h>
#include "..\Menu.h"
#include "..\UI.h"

void list_Extend(List* list) {
	if (list == NULL) return;
	if (list->array == NULL) return;
	if (list->compacity <= list->size) {
		void** newList = (void**)realloc(list->array, list->stride * list->compacity * 2);
		if (newList == NULL) {
			return;
		}
		list->array = newList;
		list->compacity *= 2;
	}
	return;
}
List list_Create(size_t compacity, size_t stride) {
	if (compacity < 0) {
		List emptyWrapper = { 0 };
		return emptyWrapper;
	}
	if (stride < 0) {
		List emptyWrapper = { 0 };
		return emptyWrapper;
	}
	List wrapper = { 0 };
	wrapper.array = (void**)malloc(compacity*stride);
	if (wrapper.array == NULL) {
		List empty = { 0 };
		return empty;
	}
	wrapper.compacity = compacity;
	wrapper.size = 0;
	wrapper.stride = stride;
	return wrapper;
}
size_t list_Size(const List* list) {
	return list->size;
}
size_t list_Compacity(const List* list) {
	return list->compacity;
}
void list_Add(List* wrapper, void* data) {
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
void list_Remove(List* wrapper, int index) {
	if (wrapper == NULL || index < -1) return;
	if (index > wrapper->size - 1) return;
	memset(&wrapper->array[index], 0, wrapper->stride);
	wrapper->size--;
	return;
}
void list_Clear(List* wrapper) {
	wrapper->size = 0;
	wrapper->stride = 0;
	wrapper->compacity = 0;
	free(wrapper->array);
}
void list_Iterate(List* wrapper, ListFunc function) {
	if (wrapper == NULL) return;
	if (wrapper->array == NULL) return;
	for (int i = 0; i < wrapper->size; i++) {
		function();
	}
}
