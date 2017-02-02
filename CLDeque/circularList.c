#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "circularList.h"

// Double link
struct Link
{
	TYPE value;
	struct Link * next;
	struct Link * prev;
};

struct CircularList
{
	int size;
	struct Link* sentinel;
};

/**
 * Allocates the list's sentinel and sets the size to 0.
 * The sentinel's next and prev should point to the sentinel itself.
 */
static void init(struct CircularList* list)
{
	// FIXME: you must write this
    assert(list != 0);
    list->sentinel = (struct Link *)malloc(sizeof(struct Link));
    assert(list->sentinel != 0);
    list->sentinel->next = list->sentinel;
    list->sentinel->prev = list->sentinel;
    list->size = 0;
}

/**
 * Creates a link with the given value and NULL next and prev pointers.
 */
static struct Link* createLink(TYPE value)
{
	// FIXME: you must write this
    struct Link *new = (struct Link*)malloc(sizeof(struct Link));
    assert(new != 0);
    new->value = value;
    new->next = 0;
    new->prev = 0;
	return new;
}

/**
 * Adds a new link with the given value after the given link and
 * increments the list's size.
 */
static void addLinkAfter(struct CircularList* list, struct Link* link, TYPE value)
{
	// FIXME: you must write this
    assert(list != 0);
    assert(link != 0);
    
    struct Link *sent = list->sentinel;
    while(1) {
        if(sent == link) {
            struct Link *new =  createLink(value);
            
            sent->next->prev = new;
            new->prev = sent;
            new->next = sent->next;
            sent->next = new;
            list->size++;
            return;
        }
        
        sent = sent->next;
        if(sent == list->sentinel) {
            printf("Link provided not found. No link added");
            return;
        }
    }
}

/**
 * Removes the given link from the list and
 * decrements the list's size.
 */
static void removeLink(struct CircularList* list, struct Link* link)
{
    // FIXME: you must write this
    assert(list != 0);
    assert(link != 0);
    assert(list->size > 0);
    assert(link != list->sentinel);
    
    struct Link *current = list->sentinel->next;
    while(current != list->sentinel) {
        if(current == link) {
            struct Link *newLinkNext = current->next;
            current->prev->next = newLinkNext;
            current->next->prev = current->prev;
            current->next = 0;
            current->prev = 0;
            free(current);
            return;
        } else  {
            current = current->next;
        }
    }

}


/**
 * Allocates and initializes a list.
 */
struct CircularList* circularListCreate()
{
	struct CircularList* list = malloc(sizeof(struct CircularList));
	init(list);
	return list;
}

/**
 * Deallocates every link in the list and frees the list pointer.
 */
void circularListDestroy(struct CircularList* list)
{
	// FIXME: you must write this
    while(!circularListIsEmpty(list)) {
        removeLink(list, list->sentinel->next);
    }
    
    free(list->sentinel);
    free(list);
}

/**
 * Adds a new link with the given value to the front of the deque.
 */
void circularListAddFront(struct CircularList* list, TYPE value)
{
	// FIXME: you must write this
    assert(list != 0);
    addLinkAfter(list, list->sentinel, value);
}

/**
 * Adds a new link with the given value to the back of the deque.
 */
void circularListAddBack(struct CircularList* list, TYPE value)
{
	// FIXME: you must write this
    assert(list != 0);
    addLinkAfter(list, list->sentinel->prev, value);
}

/**
 * Returns the value of the link at the front of the deque.
 */
TYPE circularListFront(struct CircularList* list)
{
	// FIXME: you must write this
    assert(list != 0);
    assert( list->size > 0);
	return list->sentinel->next->value;
}

/**
 * Returns the value of the link at the back of the deque.
 */
TYPE circularListBack(struct CircularList* list)
{
	// FIXME: you must write this
    assert(list != 0);
    assert( list->size > 0);
    return list->sentinel->prev->value;}

/**
 * Removes the link at the front of the deque.
 */
void circularListRemoveFront(struct CircularList* list)
{
	// FIXME: you must write this
    assert(list != 0);
    assert( list->size > 0);
    removeLink(list, list->sentinel->next);
}

/**
 * Removes the link at the back of the deque.
 */
void circularListRemoveBack(struct CircularList* list)
{
	// FIXME: you must write this
    assert(list != 0);
    assert( list->size > 0);
    removeLink(list, list->sentinel->prev);
}

/**
 * Returns 1 if the deque is empty and 0 otherwise.
 */
int circularListIsEmpty(struct CircularList* list)
{
	// FIXME: you must write this
    assert(list != 0);
    if(list->size > 0) {
        return 1;
    } else {
        return 0;
    }
}

/**
 * Prints the values of the links in the deque from front to back.
 */
void circularListPrint(struct CircularList* list)
{
	// FIXME: you must write this
    assert(list != 0);
    if(list->size == 0) {
        printf("The List is empty\n");
        return;
    } else {
        struct Link *current = list->sentinel->next;
        while(current != list->sentinel) {
            printf("Value = %f\n", current->value);
            current = current->next;
        }
    }
}

/**
 * Reverses the deque.
 */
void circularListReverse(struct CircularList* list)
{
	// FIXME: you must write this
    assert(list != 0);
    assert(list->size > 0);
    struct Link *current = list->sentinel;
    
    do{
        struct Link *newLinkPrev = current->next;
        current->next = current->prev;
        current->prev = newLinkPrev;
        current = current->next;
    } while(current != list->sentinel);
}













































