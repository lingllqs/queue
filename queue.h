#ifndef QUEUE_H
#define QUEUE_H

#include <stdint.h>
#include <stdbool.h>

typedef struct Queue {
    void *elems;
    uint32_t elem_type;
    uint32_t front;
    uint32_t end;
    uint32_t capacity;
    uint32_t size;
} Queue;

Queue* queue_new(uint32_t capacity, uint32_t elem_type);
bool is_empty(Queue *queue);
bool is_full(Queue *queue);
void push(Queue *queue, void *elem);
void pop(Queue *queue);
void free_queue(Queue *queue);

#endif
