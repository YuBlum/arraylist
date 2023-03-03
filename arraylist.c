#include <stdlib.h>
#include <string.h>
#include "arraylist.h"

struct arraylist_header {
	size_t typ;
	size_t siz;
	size_t cap;
};

#define ARRAYLIST_HEADER(list) (((struct arraylist_header *)(list)) - 1)

void *
arraylist_alloc(size_t type, size_t size) {
	struct arraylist_header *header = malloc(sizeof (struct arraylist_header) + type * (size + 1));
	if (!header) return NULL;
	header->typ = type;
	header->siz = size;
	header->cap = size+1;
	return header + 1;
}

_Bool
arraylist_push(void *restrict ptr_to_list, const void *restrict value) {
	void **list = ptr_to_list;
	struct arraylist_header *header = ARRAYLIST_HEADER(*list);
	if (header->cap <= header->siz) {
		header->cap *= 2;
		header = realloc(header, sizeof (struct arraylist_header) + (header->typ * header->cap));
		if (!header) {
			*list = NULL;
			return 0;
		}
	}
	*list = header + 1;
	memcpy((*list) + header->typ * header->siz++, value, header->typ);
	return 1;
}

_Bool
arraylist_pop(void *restrict list, void *restrict dest) {
	struct arraylist_header *header = ARRAYLIST_HEADER(list);
	if (!header->siz) return 0;
	header->siz--;
	if (!dest) return 1;
	memcpy(dest, list + header->typ * header->siz, header->typ);
	return 1;
}

_Bool
arraylist_add(void *ptr_to_list, const void *value) {
	void **list = ptr_to_list;
	struct arraylist_header *header = ARRAYLIST_HEADER(*list);
	if (header->cap <= header->siz) {
		header->cap *= 2;
		header = realloc(header, sizeof (struct arraylist_header) + (header->typ * header->cap));
		if (!header) {
			*list = NULL;
			return 0;
		}
	}
	*list = header + 1;
	memmove((*list) + header->typ * header->siz++, value, header->typ);
	return 1;
}

_Bool
arraylist_delete(void *list, void *dest) {
	struct arraylist_header *header = ARRAYLIST_HEADER(list);
	if (!header->siz) return 0;
	header->siz--;
	if (!dest) return 1;
	memmove(dest, list + header->typ * header->siz, header->typ);
	return 1;
}

size_t
arraylist_size(void *list) {
	return ARRAYLIST_HEADER(list)->siz;
}

size_t
arraylist_capacity(void *list) {
	return ARRAYLIST_HEADER(list)->siz;
}

void 
arraylist_free(void *list) {
	free(ARRAYLIST_HEADER(list));
}
