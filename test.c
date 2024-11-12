#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

#define CAPACITY 10

int main() {
    Queue *queue = queue_new(CAPACITY, sizeof(int32_t));
    printf("capacity: %d\n", queue->capacity);

    int32_t num;
    for (uint32_t i = 0; i < CAPACITY; i++) {
        num = i + 10;
        push(queue, &num);
    }

    for (uint32_t i = 0; i < CAPACITY; i++) {
        void *elem = pop(queue);
        if (elem) printf("elem: %d\n", *(int *)elem);
        free(elem);
    }

    free_queue(queue);

    return 0;
}
