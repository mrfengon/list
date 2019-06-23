#ifndef LIST_H_
#define LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct list {
    char info;
    struct list* next;
    struct list* prev;
    bool is_barrier;
} list;

void list_init(list** root, char info);
void list_push_element(list** root, char info);
void list_pop_element(list **root);
size_t list_size(list *root);
void list_print(list *root);
bool is_list_ordered(list *root);

#endif