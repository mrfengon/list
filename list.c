#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void list_init(list **root, char info){
    *root = (list *)(malloc(sizeof(list)));
    (*root)->info = info;
    (*root)->is_barrier = 0;
    list* bar;
    bar = (list *)(malloc(sizeof(list)));
    bar->prev = *root;
    bar->next = *root;
    bar->is_barrier = 1;
    (*root)->next = bar;
    (*root)->prev = bar;
}

void list_push_element(list** root, char info) {
    list* pushed_elem;
    list* temp = *root;
    pushed_elem = (list*) (malloc(sizeof(list)));
    temp = temp->prev->prev;
    pushed_elem->next = temp->next;
    temp->next = pushed_elem;
    pushed_elem->prev = temp;
    pushed_elem->info = info;
    pushed_elem->next->prev = pushed_elem;
    pushed_elem->is_barrier = 0;
}

void list_pop_element(list** root) {
    list* popped_elem = *root;
    list* temp;
    popped_elem = popped_elem->prev->prev;
    temp = popped_elem->prev;
    temp->next = popped_elem->next;
    free(popped_elem);
}

size_t list_size(list* root) {
    size_t size = 0;
    list* temp = root;
    while(temp->next != root) {
        size++;
        temp = temp->next;
    }
    return size;
}

void list_print(list* root) {
    list* printing_elem = root;
    while(printing_elem->next->next != root) {
        printf("%s ", printing_elem->info);
        printing_elem = printing_elem->next;
    }
}

bool is_list_ordered(list* root) {
    list* temp = root;
    char info;
    bool is_ordered;
    while(temp->next->next != root) {
        info = temp->info;
        temp = temp->next;
        if(temp->info <= info) {
            is_ordered = 1;
        } else {
            is_ordered = 0;
            return is_ordered;
        }
    }
    return is_ordered;
}