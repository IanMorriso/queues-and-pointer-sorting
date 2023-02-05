#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
 * The following data structure is similar to a queue, but with both normal dequeue and priority dequeue functions.
 * The order of items in the queue is sorted by the order in which they were inserted.
 * The first item inserted is at the head of the queue, and the last item inserted is appended to the end.
 */

struct book {
    char *title;    //title string must be dynamically/heap allocated (malloc/calloc)
    unsigned int priority;
    struct book *prev;
    struct book *next;
};

struct book_queue {
    struct book *head;
    struct book *tail;
};


// queue_create() creates a new empty book_queue where head and tail are both NULL
// returns a pointer to it
struct book_queue *queue_create(void);

// queue_destroy(queue) destroys a queue and frees all the books in it
// 1) requires that `queue` is valid (not NULL)
// 2) set `queue` to NULL to avoid future use
void queue_destroy(struct book_queue **queue);

// queue_add(queue, title) adds a book to the end of the queue with 0 priority, making it the new tail
// 1) if `title` already exists in queue, increases priority of `title` by 1 (does not add book)
// 2) requires that `queue` is valid (not NULL)
void queue_add(struct book_queue *queue, const char *title);

// queue_remove(queue, title) removes a book from the queue with that title
// 1) must ensure that pointers are maintained:
// 		- *next of the previous book should point to *next of the deleted book
// 		- *prev of the next book should point to *prev of the deleted book
// 2) requires that `queue` is valid (not NULL) and title is in the queue
void queue_remove(struct book_queue *queue, const char *title);

// increase_priority(queue, title, num) increases the priority of `title` by num
// 1) requires that `queue` is valid (not NULL) and title is in the queue
void increase_priority(struct book_queue *queue, const char *title, int num);

// priority_dequeue(queue) returns the title of the book with the highest priority, then removes it
// 1) if two books have the same priority, remove the one that was inserted first (closer to *head book)
// 2) you may allocate memory for the title and return a pointer to it (do not free())
// 3) requires that `queue` is valid (not NULL)
// 4) returns NULL if `queue` is invalid (NULL) or `queue` is empty
char *priority_dequeue(struct book_queue *queue);

// normal_dequeue(queue) returns the title of the book pointed to by head, then removes it
// 1) you may allocate memory for the title and return a pointer to it (do not free())
// 2) requires that `queue` is valid (not NULL)
// 3) returns NULL if `queue` is invalid (NULL) or `queue` is empty
char *normal_dequeue(struct book_queue *queue);


// ignore the following function declarations
void check_queue_create(void);
void check_queue_add(struct book_queue *queue);
void check_queue_remove(struct book_queue *queue);
void check_increase_priority(struct book_queue *queue);
void check_priority_dequeue(struct book_queue *queue);
void check_normal_dequeue(struct book_queue *queue);
void check_queue_destroy(struct book_queue *queue);
