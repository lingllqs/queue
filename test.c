#include <stdint.h>
#include <stdio.h>

#include "queue.h"

#define N 10

int main() {
    Queue *queue = queue_new(N, sizeof(int32_t));
    printf("capacity: %d\n", queue->capacity);

    int32_t num;
    for (uint32_t i = 0; i < N; i++) {
        num = i + 10;
        push(queue, &num);
    }

    void *p = queue->elems;
    for (uint32_t i = 0; i < N - 1; i++){
        printf("%d ", *(uint32_t*)p);
        p = p + queue->elem_type;
    }

    free_queue(queue);

    return 0;
}
