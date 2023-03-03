#ifndef __ARRAYLIST_H__
#define __ARRAYLIST_H__

#include <stddef.h>

/*
 * arraylist_alloc:
 * 	allocate list in the heap
 * 	@param size_t type: size of members of the list
 * 	@param size_t size: initial size of the list
 * 	@returns the list if success or NULL if failure
 * */
void *arraylist_alloc(size_t type, size_t size);
/*
 * arraylist_alloc:
 * 	push back the value into the list
 * 	@param void *restrict ptr_to_list: a pointer to the list (I.e. &list)
 * 	@param void *restrict value: a pointer to the value
 * 	@returns 1 if success or 0 if failure
 * */
_Bool arraylist_push(void *restrict ptr_to_list, const void *restrict value);
/*
 * arraylist_alloc:
 * 	pop back the list into the dest
 * 	@param void *restrict list: the list
 * 	@param void *restrict value: a pointer to the dest
 * 	@returns 1 if success or 0 if failure
 * */
_Bool arraylist_pop(void *restrict list, void *restrict dest);
/*
 * arraylist_alloc:
 * 	similar to arraylist_push, but allow memory collision between the list and the value
 * 	@param void *ptr_to_list: a pointer to the list (I.e. &list)
 * 	@param void *value: a pointer to the value
 * 	@returns 1 if success or 0 if failure
 * */
_Bool arraylist_add(void *ptr_to_list, const void *value);
/*
 * arraylist_alloc:
 * 	similar to arraylist_pop, but allow memory collision between the list and the value
 * 	@param void *list: the list
 * 	@param void *value: a pointer to the dest
 * 	@returns 1 if success or 0 if failure
 * */
_Bool arraylist_delete(void *list, void *dest);
/*
 * arraylist_size:
 * 	get the size of list
 * 	@param void *list: the list
 * 	@returns size of list
 * */
size_t arraylist_size(void *list);
/*
 * arraylist_capacity:
 * 	get the capacity of list
 * 	@param void *list: the list
 * 	@returns capacity of list
 * */
size_t arraylist_capacity(void *list);
/*
 * arraylist_capacity:
 * 	free just the list memory
 * 	the members of list needs to be freed manually
 * 	@param void *list: the list
 * */
void arraylist_free(void *list);

#endif/*__ARRAYLIST_H__*/
