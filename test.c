#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

#define N 10

void test();

struct Person {
    int age;
    char name[64];
};

int main() {
    Queue *queue = queue_new(N + 1, sizeof(int32_t));
    printf("capacity: %d\n", queue->capacity);

    int32_t num;
    for (uint32_t i = 0; i < N; i++) {
        num = i + 10;
        push(queue, &num);
    }

    void *p = queue->elems;
    for (uint32_t i = 0; i < N; i++) {
        printf("%d ", *(uint32_t *)p);
        p = p + queue->elem_type;
    }
    putchar(10);
    putchar(10);

    free_queue(queue);

    test();

    return 0;
}

void test() {
    printf("size of struct person = %ld\n", sizeof(struct Person));

    struct Person p1 = {21, "hello"};
    struct Person p2 = {22, "world"};
    struct Person p3 = {23, "rust"};

    Queue *queue = queue_new(4, sizeof(struct Person));
    push(queue, &p1);
    push(queue, &p2);
    push(queue, &p3);

    void *p = queue->elems;
    for (uint32_t i = 0; i < queue->size; i++) {
        struct Person pp = *(struct Person *)p;
        printf("%d %s ", pp.age, pp.name);
        p = p + queue->elem_type;
    }
    putchar(10);

    free(queue);
}
