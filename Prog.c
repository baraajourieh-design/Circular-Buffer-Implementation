#include <stdio.h>
#include <string.h>
#define SIZE 5
#define N 5

struct CircularBuffer {
    char buffer[SIZE];
    int head;
    int tail;
    int count;
};

void init(struct CircularBuffer *cb) {
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}

int isFull(struct CircularBuffer *cb) {
    return cb->count == SIZE;
}

int isEmpty(struct CircularBuffer *cb) {
    return cb->count == 0;
}

void write(struct CircularBuffer *cb, char data) {
    if (isFull(cb)) {
        printf("Buffer Overflow\n");
        return;
    }
    cb->buffer[cb->head] = data;
    cb->head = (cb->head + 1) % SIZE;
    cb->count++;
}

char read(struct CircularBuffer *cb) {
    if (isEmpty(cb)) {
        printf("Buffer Underflow\n");
        return 0;
    }
    char data = cb->buffer[cb->tail];
    cb->tail = (cb->tail + 1) % SIZE;
    cb->count--;
    return data;
}

int main() {
    struct CircularBuffer cb;
    char name[100];
    int i;
    
    init(&cb);
    
    printf("Enter your name: ");
    scanf("%s", name);
    
    strcat(name, "CE-ESY");
    
    for (i = 0; i < strlen(name); i++) {
        write(&cb, name[i]);
    }
    
    while (!isEmpty(&cb)) {
        char ch = read(&cb);
        printf("%c", ch);
    }
    printf("\n");
    
    return 0;
}
