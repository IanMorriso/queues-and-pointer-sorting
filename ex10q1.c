/* Purpose: Library Book System
 * Author: Ian Morrison
 * Date: December 07
 * References:
 */

#include "lab10a.h"
#define IDENTICAL 0

// Creates a book queue. See lab10a.h for more details.
struct book_queue *queue_create(void) {

    struct book_queue *queue = malloc(sizeof(struct book_queue));
    queue->head = NULL;
    queue->tail = NULL;
    printf("creates queue: %p\n", queue);
    return queue;
}

// Destroys a book list. See lab10a.h for more details.
void queue_destroy(struct book_queue **queue) {

    // Checks validity of queue
    if (queue == NULL) {
        return;
    } 

    // This block interates through our queue and free's each title and book inside the queue
    struct book *temp;
    struct book *current = (*queue)->head;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp->title);
        free(temp);
    }

    // This block sets the queue, along with it's head and tail to NULL
    (*queue)->head = NULL;
    (*queue)->tail = NULL;
    free(*queue);
    (*queue) = NULL;
    queue = NULL;

    return;
}

// Adds a book to the end of the list with 0 priority. See lab10a.h for more details.
void queue_add(struct book_queue *queue, const char *title) {

    // Checks validity of queue
    if (queue == NULL) {
        return;
    }

    // Allocate memory for new book and it's title, set priority to 0
    struct book *new_book = malloc(sizeof(struct book));
    new_book->title = malloc((strlen(title) + 1));
    strcpy(new_book->title, title);
    new_book->priority = 0;
    new_book->next = NULL;
    new_book->prev = NULL;

    // If queue is empty, new book is head and tail.
    if (queue->head == NULL) {
        queue->head = new_book;
        queue->tail = new_book;
        return;
    }

    //Traverse queue looking for same title
    struct book *temp = queue->head;
    while(temp != NULL) {

        // If book title matches title to be added, increase book's priority.
        if (!strcmp(temp->title, title)) {
            temp->priority += 1;
            free(new_book->title);
            free(new_book);
            return;
        }
        temp = temp->next;
    }

    // If book not found, add to end of queue
    new_book->prev = queue->tail;
    queue->tail->next = new_book;
    queue->tail = new_book;
    return;

}

// Removes a book with the specified title. See lab10a.h for more details.
void queue_remove(struct book_queue *queue, const char *title) {

    // Checks validity of queue
    if (queue == NULL) {
        return;
    }

    // If queue has only one book, remove it and set queue to NULL
    if ((queue->head != NULL) && (queue->head == queue->tail)) {
        free(queue->head->title);
        free(queue->head);
        queue->head = NULL;
        queue->tail = NULL;
        queue = NULL;
        free(queue);
        return;
    }

    // If the queue has only two elements, and head has title we need to remove, set head to equal tail
    struct book *temp = queue->head;
    if (temp->next == queue->tail) {
        free(queue->head->title);
        free(queue->head);
        queue->head = queue->tail;
        return;
    }
        
    // If title matches head, set new head
    else if ((queue->head != NULL) && !strcmp(title, queue->head->title)) {
        temp = temp->next;
        temp->prev = NULL;
        free(queue->head->title);
        free(queue->head);
        queue->head = temp;
        return;
    }

    // If title is at tail, set new tail
    else if (!strcmp(title, queue->tail->title)) {
        struct book *temp = queue->tail->prev;
        temp->next = NULL;
        free(queue->tail->title);
        free(queue->tail);
        queue->tail = temp;
        return;
    }

    // Traverse queue looking for matching title
    temp = queue->head;
    while(temp != NULL) {
        if (!strcmp(temp->title, title)) {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            free(temp->title);
            free(temp);
            return;
        }
        temp = temp->next;
    }
    return;
}


// Increases the priority of the book with `title` by num. See lab10a.h for more details.
void increase_priority(struct book_queue *queue, const char *title, int num) {

    // Checks validity of queue
    if (queue == NULL) {
        return;
    }

    // Traverse queue looking for matching title. If found, increase prioritty by given number
    struct book *temp = queue->head;
    while (temp != NULL) {
        if (!strcmp(temp->title, title)) {
            temp->priority += num;
            return;
        }
        temp = temp->next;
    }
    return;
}

// Returns title of book with highest priority, then deletes it. See lab10a.h for more details.
char *priority_dequeue(struct book_queue *queue) {

    // Checks validity of queue
    if (queue == NULL) {
        return NULL;
    }

    // Traverse queue looking for book with highest priority
    struct book *temp = queue->head;
    struct book *priority;              // First book encountered gets set as priority. If another has same, keep looking
    int max = 0;
    while (temp != NULL) {
        if (temp->priority > max) {
            max = temp->priority;
            priority = temp;
        }
        temp = temp->next;
    }

    // Allocate memory for priority title, copy and return. Removes piority book
    char *title = malloc(strlen(priority->title) + 1);
    strcpy(title, priority->title);
    queue_remove(queue, priority->title);

    return title;
}


// Returns title of book at the front of the queue, then deletes it. See lab10a.h for more details.
char *normal_dequeue(struct book_queue *queue) {
    
    // Checks validity of queue
    if (queue == NULL) {
        return NULL;
    }

    // Allocate memory for title of book removed, copy it, and return it. Remove book
    char *title = malloc(strlen(queue->head->title) + 1);
    strcpy(title, queue->head->title);
    queue_remove(queue, title);

    return title;
}