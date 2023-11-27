#include "..\utils.h"
typedef struct l_internal {
	void** data;
	size_t size;
	size_t compacity;
	size_t element_size;
	void (*free_fn)(void*);
}ListInternal;
ListHandle* lh_CreateList(size_t element_size, void(*free_fn)(void*)) {
	ListInternal* lh = (ListInternal*)malloc(sizeof(ListInternal));
	if (lh == NULL) return NULL;
	lh->data = NULL;
	lh->compacity = NULL;
	lh->size = NULL;
	lh->element_size = element_size;
	lh->free_fn = free_fn;
	return (ListHandle*)lh;
}
void lh_pushback(ListHandle* handle, void* val) {
	ListInternal* lst = (ListInternal*)handle;
	if (lst == NULL) return;

	if (lst->compacity == 0) {
		lst->data = (void**)malloc(sizeof(val));
		lst->compacity = 1;
	}
	else if (lst->size == lst->compacity) {
		lst->compacity *= 2;
		void** tmp = (void**)realloc(lst->data, lst->compacity * sizeof(val));
		if (tmp != NULL) {
			lst->data = tmp;
		}
	}
	lst->data[lst->size] = val;
	if (lst->data[lst->size] == NULL) {
		return;
	}
	memcpy(lst->data[lst->size], val, lst->element_size);
	lst->size++;
}
void* lh_at(ListHandle* handle, size_t index) {
	ListInternal* list = (ListInternal*)handle;
	if (list == NULL) return (void*)-1;
	if (index < list->size) {
		return list->data[index];
	}
}
void lh_Destroy(ListHandle* handle) {
	if (handle == NULL) return;
	ListInternal* list = (ListInternal*)handle;
	for (size_t i = 0; i < list->size; i++) {
		if (list->free_fn) {
			list->free_fn(list->data[i]);
		}
		free(list->data[i]);
	}
	free(list->data);
	list->data		= NULL;
	list->size		= 0;
	list->compacity = 0;
}
size_t lh_Size(ListHandle* handle) {
	if (handle == NULL) return -1;
	ListInternal* list = (ListInternal*)handle;
	return list->size;
}