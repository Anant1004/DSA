#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

// Structure to represent a queue
struct Queue {
    int items[MAX_SIZE];
    int front, rear;
};

// Function to initialize an empty queue
void initializeQueue(struct Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return queue->front == -1;
}

// Function to check if the queue is full
int isFull(struct Queue* queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}

// Function to add an element to the rear of the queue (enqueue)
void enqueue(struct Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue %d.\n", value);
    } else {
        if (isEmpty(queue)) {
            queue->front = 0;
        }
        queue->rear = (queue->rear + 1) % MAX_SIZE;
        queue->items[queue->rear] = value;
        printf("Enqueued: %d\n", value);
    }
}

// Function to remove an element from the front of the queue (dequeue)
int dequeue(struct Queue* queue) {
    int value = -1; // Default value if the queue is empty

    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
    } else {
        value = queue->items[queue->front];
        if (queue->front == queue->rear) {
            // Reset the queue to empty
            initializeQueue(queue);
        } else {
            queue->front = (queue->front + 1) % MAX_SIZE;
        }
        printf("Dequeued: %d\n", value);
    }

    return value;
}

// Function to display the elements in the queue
void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        int i = queue->front;
        do {
            printf("%d ", queue->items[i]);
            i = (i + 1) % MAX_SIZE;
        } while (i != (queue->rear + 1) % MAX_SIZE);
        printf("\n");
    }
}

int main() {
    struct Queue myQueue;
    initializeQueue(&myQueue);

    enqueue(&myQueue, 10);
    enqueue(&myQueue, 20);
    enqueue(&myQueue, 30);
    display(&myQueue);

    dequeue(&myQueue);
    display(&myQueue);

    enqueue(&myQueue, 40);
    display(&myQueue);

    return 0;
}
