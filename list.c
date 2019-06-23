#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void list_init(list **root, char info){
    *root = (list *)(malloc(sizeof(list)));
    (*root)->info = info;
    (*root)->is_barrier = false;

    list* bar = (list *)(malloc(sizeof(list)));
    bar->prev = *root;
    bar->next = *root;
    bar->is_barrier = true;
    (*root)->next = bar;
    (*root)->prev = bar;
}

void list_push_element(list** root, char info) {
    list *pushed_elem = (list *)(malloc(sizeof(list)));
    list* last_elem = (*root)->prev->prev;
    
    pushed_elem->next = last_elem->next;
    last_elem->next = pushed_elem;
    pushed_elem->prev = last_elem;
    pushed_elem->next->prev = pushed_elem;
    
    pushed_elem->info = info;
    pushed_elem->is_barrier = false;
}

void list_pop_element(list** root) {
    list *popped_elem = (*root)->prev->prev;
    list* new_last_elem = popped_elem->prev;
    new_last_elem->next = popped_elem->next;
    new_last_elem->next->prev = new_last_elem;

    free(popped_elem);
}

size_t list_size(list* root) {
    size_t size = 0;
    list* iter = root;
    while((iter != NULL) && !(iter->is_barrier)) {
        size++;
        iter = iter->next;
    }
    return size;
}

void list_print(list* root) {
    list* printed_elem = root;
    while ((printed_elem != NULL) && !(printed_elem->is_barrier))
    {
        printf("%c ", printed_elem->info);
        printed_elem = printed_elem->next;
    }
    printf("\n");
}

bool is_list_ordered(list* root) {
    list* iter = root;
    char info;
    bool is_ordered;
    while(iter != NULL && !(iter->next->is_barrier)) {
        if(iter->info > iter->next->info) {
            return false;
        }
        iter = iter->next;
    }
    return true;
}