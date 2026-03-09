#include<stdio.h>
#include<stdlib.h>
typedef struct {
    int *arr;
    int front;
    int rear;
    int size;
    int count;
} circularQueue;

circularQueue* createQueue(int n){
    circularQueue* q = (circularQueue*)malloc(sizeof(circularQueue));
    q->size = n;
    q->arr = (int*)malloc(sizeof(int)*n);
    q->front = 0;
    q->rear = -1;
    q->count = 0;
    return q;
}
void enqueue(circularQueue* q , int value){
    if ( q->count == q->size) return;
    q->rear = (q->rear + 1) % q->size;
    q->arr[q->rear] = value;
    q->count++;
}
void dequeue(circularQueue* q ,){
    if (q->count == 0) return;
    q->front = (q->front + 1) % q->size;
    q->count--;
}
    
