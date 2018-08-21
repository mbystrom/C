#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#define GROW_CAPACITY(capacity) \
    ((capacity) < 8 ? 8 : (capacity) * 2)

#define GROW_ARRAY(previous, type, oldCount, count) \
    (type*)reallocate(previous, sizeof(type) * (oldCount), sizeof(type) * count)

void* reallocate (void* previous, size_t oldSize, size_t newSize);

typedef struct {
    int count;
    int capacity;
    int* list;
} IntList;

void initList (IntList* ls) {
    ls -> count = 0;
    ls -> capacity = 0;
    ls -> list = NULL;
}

void writeToList (IntList* ls, int num) {
    if (ls->capacity < ls->count + 1) {
        int oldCapacity = ls->capacity;
        ls->capacity = GROW_CAPACITY(oldCapacity);
        ls->list = GROW_ARRAY(ls->list, int, oldCapacity, ls->capacity);
    }

    ls->list[ls->count] = num;
    ls->count++;
}

void freeList (IntList* ls) {
    ls -> list = GROW_ARRAY(ls->list, int, ls->capacity, 0);
}

void* reallocate(void* previous, size_t oldSize, size_t newSize) {
    if (newSize == 0) {
        printf("freeing list\n");
        free(previous);
        return NULL;
    }

    return realloc(previous, newSize);
}

int main ()
{
    IntList ls;
    initList(&ls);
    writeToList(&ls, 1);
    printf("%d\n",ls.list[0]);
    freeList(&ls);
}
