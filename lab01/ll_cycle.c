#include <stddef.h>
#include "ll_cycle.h"

#define var __auto_type

int ll_has_cycle(node *head) {
    /* 1. */
    var tortoise = head;
    var hare = head;

    while (1) {
        if (hare == NULL) { /* empty list check */
            return 0;
        }
        if (hare -> next != NULL) {
            if (hare -> next -> next != NULL) {
                /* 2 */
                hare = hare -> next -> next;
            } else {
                return 0;
            }
        } else {
            return 0;
        }

        tortoise = tortoise -> next;
        if (hare == tortoise) {
            return 1;
        }
    }

    return 0;
}
