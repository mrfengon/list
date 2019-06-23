#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

int main() {
    list* root;
    char info;
    int temp = 0;
    while(temp != 6) {
        printf("\n0 - init, 1 - push, 2 - pop, 3 - size, 4 - print, "
               "5 - is ordered, 6 - exit\n");
        scanf("%d", &temp);
        if(temp == 0) {
            printf("\nenter info: ");
            scanf(" %c", &info);
            list_init(&root, info);
        }
        else if(temp == 1) {
            printf("\nenter info: ");
            scanf(" %c", &info);
            list_push_element(&root, info);
        }
        else if(temp == 2) {
            list_pop_element(&root);
        }
        else if(temp == 3) {
            printf("%lu\n", list_size(root));
        }
        else if(temp == 4) {
            list_print(root);
        }
        else if(temp == 5) {
            if(is_list_ordered(root)){
                printf("is ordered\n");
            } else {
                printf("isn't ordered");
            }
        }
    }
    return 0;
}