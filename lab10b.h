#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *word; //word string must be dynamically allocated to store a string
    unsigned int length;
} String;

int comp_length(String e1, String e2);
int comp_alphabetical(String e1, String e2);
void msort(String arr[], int l, int r, int (*comp)(String e1, String e2));

void check_msort(void);
