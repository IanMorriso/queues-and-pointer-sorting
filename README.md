# queues-and-pointer-sorting
Priority queue for library books, and a Merge Sort with my own function pointers

**ex10q1.c** contains the program for our **Priority Queue**.
* Books can be added via **enqueu** as in a normal queue, but if the same book is added again, it updated the "priority" of the existing book in the queue instead.
* Books can be removed via **dequeu** as in a normal queue
* Books can be removed via **priority_dequeue**, in which the queue is searched for the book with the highest priority. The book object is returned, book is removed from queue and memory freed, and queue structure is maintained.


**ex10q2.c** contains the program for an altered Merge Sort that uses **Function Pointers** for comparisons of string length and alphabetic order.
* msort() works as our Merge Sort fucntion, but takes in an additional parameter of a **Function Pointer** to use in its comparisons.
* In it's current state, **msort()** can take in any funciton pointers that return -1, 0, or 1, as a result of comparisons, and use it to correctly sort an array of **String structs** into lexigraphic order.
