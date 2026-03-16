#include<stdio.h>
#include<stdlib.h>
/* Queue Node */
typedef struct Node {
    int data;
    struct Node* next;
}Node;

/* Queue structure*/
typedef struct Queue {
    Node* front;
    Node* reae;
} Queue;

/* Stack Node */
typedef struct stack {
    int data;
    struct stack* next;
} stack;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    node->data = x;
    node->next = NULL;
    if (q->rear == NULL){
        q->front = q->rear = node;
        return;
    }
    q->rear->next = node;
    q->rear = node;
}
int dequeue(Queue* q) {
    if (q->front == NULL)
        return -1;
    Node* temp = q->front;
    int val = temp->data;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return val;
}
void push(stack** top , int x){
    stack* node = (stack*)malloc(sizeof(stack));
    node->data = x;
    node->next = *top;
    *top = node;
}
int pop(Stack** top) {
    if (*top == NULL)
      return -1;
    stack* temp = *top;
    int val = temp->data;
    *top = temp->next;
    free(temp)
    return val;
}
void reverseQueue(Queue* q) {
    stack* stack = NULL;
    while (q->front != NULL) {
        push(&stack,dequeue(q));
    }
    while ( stack != NULL) {
        enqueue(q,pop(&stack));
    }
}
