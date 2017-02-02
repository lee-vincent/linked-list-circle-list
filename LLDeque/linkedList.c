#include "linkedList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

// Double link
struct Link
{
	TYPE value;
	struct Link* next;
	struct Link* prev;
};

// Double linked list with front and back sentinels
struct LinkedList
{
	int size;
	struct Link* frontSentinel;
	struct Link* backSentinel;
};

/**
 * Allocates the list's sentinel and sets the size to 0.
 * The sentinels' next and prev should point to eachother or NULL
 * as appropriate.
 */
static void init(struct LinkedList* list) {
	// FIXME: you must write this
    assert(list != 0);
    list->frontSentinel = (struct Link* )malloc(sizeof(struct Link));
    assert(list->frontSentinel != 0);
    list->backSentinel = (struct Link* )malloc(sizeof(struct Link));
    assert(list->backSentinel != 0);
    list->frontSentinel->next = list->backSentinel;
    list->backSentinel->prev = list->frontSentinel;
    list->frontSentinel->prev = 0;
    list->backSentinel->next = 0;
    list->size = 0;
}

/**
 * Adds a new link with the given value before the given link and
 * increments the list's size.
 */
static void addLinkBefore(struct LinkedList* list, struct Link* link, TYPE value)
{
	// FIXME: you must write this
    assert(list != 0);
    assert(link != 0);
    assert(list->size > 0 || link == list->backSentinel);
    
    struct Link* temp = list->frontSentinel;
    while(temp->next != 0) {
        if(temp->next == link) {
            struct Link *new = (struct Link*)malloc(sizeof(struct Link));
            assert(new != 0);
            new->value = value;
            link->prev = new;
            new->next = link;
            new->prev = temp;
            temp->next = new;
            list->size++;
            return;
        }
        temp = temp->next;
    }
    
    printf("Given link not found. Value not inserted");
}

/**
 * Removes the given link from the list and
 * decrements the list's size.
 */
static void removeLink(struct LinkedList* list, struct Link* link)
{
	// FIXME: you must write this
    assert(list != 0);
    assert(list->size > 0);
    assert(link != 0);
    assert(link != list->frontSentinel && link != list->backSentinel);
    
    struct Link* temp = list->frontSentinel;
    while(temp->next != 0) {
        if(temp->next == link) {
            temp->next = link->next;
            link->next->prev = temp;
            link->next = 0;
            link->prev = 0;
            free(link);
            list->size--;
            return;
        }
        temp = temp->next;
    }
    printf("Given link not found. No links removed\n");
}

/**
 * Allocates and initializes a list.
 */
struct LinkedList* linkedListCreate()
{
	struct LinkedList* newDeque = malloc(sizeof(struct LinkedList));
	init(newDeque);
	return newDeque;
}

/**
 * Deallocates every link in the list including the sentinels,
 * and frees the list itself.
 */
void linkedListDestroy(struct LinkedList* list)
{
	while (!linkedListIsEmpty(list))
	{
		linkedListRemoveFront(list);
	}
	free(list->frontSentinel);
	free(list->backSentinel);
	free(list);
}

/**
 * Adds a new link with the given value to the front of the deque.
 */
void linkedListAddFront(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this
    assert(list != 0);
    addLinkBefore(list, list->frontSentinel->next, value);
}

/**
 * Adds a new link with the given value to the back of the deque.
 */
void linkedListAddBack(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this
    assert(list != 0);
    addLinkBefore(list, list->backSentinel, value);

}

/**
 * Returns the value of the link at the front of the deque.
 */
TYPE linkedListFront(struct LinkedList* list)
{
	// FIXME: you must write this
    assert(list != 0);
    assert(list->size > 0);
    return list->frontSentinel->next->value;

}

/**
 * Returns the value of the link at the back of the deque.
 */
TYPE linkedListBack(struct LinkedList* list)
{
	// FIXME: you must write this
    assert(list != 0);
    assert(list->size > 0);
    return list->backSentinel->prev->value;
}

/**
 * Removes the link at the front of the deque.
 */
void linkedListRemoveFront(struct LinkedList* list)
{
	// FIXME: you must write this
    assert(list != 0);
    assert(list->size > 0);
    removeLink(list, list->frontSentinel->next);
}

/**
 * Removes the link at the back of the deque.
 */
void linkedListRemoveBack(struct LinkedList* list)
{
	// FIXME: you must write this
    assert(list != 0);
    assert(list->size > 0);
    removeLink(list, list->backSentinel->prev);
}

/**
 * Returns 1 if the deque is empty and 0 otherwise.
 */
int linkedListIsEmpty(struct LinkedList* list)
{
	// FIXME: you must write this
    assert(list != 0);
    return list->size > 0 ? 0 : 1;
}

/**
 * Prints the values of the links in the deque from front to back.
 */
void linkedListPrint(struct LinkedList* list)
{
	// FIXME: you must write this
    assert(list != 0);
    assert(list->size > 0);
    struct Link *temp = list->frontSentinel;
    while(temp->next != list->backSentinel) {
        printf("Value = %i\n", temp->next->value);
        temp = temp->next;
    }
}

/**
 * Adds a link with the given value to the bag.
 */
void linkedListAdd(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this
    linkedListAddBack(list, value);
}

/**
 * Returns 1 if a link with the value is in the bag and 0 otherwise.
 */
int linkedListContains(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this
    assert(list != 0);
    struct Link *temp = list->frontSentinel;
    while(temp->next != 0) {
        if(temp->next->value == value) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

/**
 * Removes the first occurrence of a link with the given value.
 */
void linkedListRemove(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this
    assert(list != 0);
    struct Link *temp = list->frontSentinel;
    while(temp->next != 0) {
        if(temp->next->value == value) {
            removeLink(list, temp->next);
        }
        temp = temp->next;
    }
}
