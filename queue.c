#include "queue.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Queue *queue_new(uint32_t capacity, uint32_t elem_type) {
    if (capacity > 0) {
        Queue *new_queue = malloc(sizeof(Queue));
        if (NULL == new_queue) {
            perror("malloc new_queue failure");
            return NULL;
        }

        new_queue->capacity = capacity;
        new_queue->elem_type = elem_type;
        new_queue->front = 0;
        new_queue->end = 0;
        new_queue->size = 0;

        new_queue->elems = malloc(elem_type * capacity);
        if (!new_queue->elems) {
            perror("malloc new_queue->elems failure");
            free(new_queue);
            return NULL;
        }

        return new_queue;
    }

    return NULL;
}

bool is_empty(Queue *queue) {
    return queue->front == queue->end ? true : false;
}

bool is_full(Queue *queue) {
    return (queue->end + 1) % queue->capacity == queue->front ? true : false;
}

void push(Queue *queue, void *elem) {
    if (is_full(queue)) {
        printf("队列满，push 失败\n");
        return;
    }

    printf("push\n");
    memcpy(queue->elems + queue->end * queue->elem_type, elem, queue->elem_type);
    queue->end = (queue->end + 1) % queue->capacity;
    queue->size++;
}

void *pop(Queue *queue) {
    if (is_empty(queue)) {
        printf("队列为空，pop 失败\n");
        return NULL;
    }

    void *elem = malloc(queue->elem_type);
    if (NULL == elem) {
        perror("malloc elem failure");
        return NULL;
    }

    memcpy(elem, queue->elems + queue->front * queue->elem_type, queue->elem_type);
    queue->front = (queue->front + 1) % queue->capacity;

    queue->size--;

    return elem;
}

void free_queue(Queue *queue) {
    if (queue) {
        if (queue->elems) {
            free(queue->elems);
        }
        free(queue);
    }
}
