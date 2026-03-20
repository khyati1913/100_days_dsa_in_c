#include<stdio.h>
#include<stdlib.h>
#define MAX 100
// Tree Node
struct Node {
    int data;
    struct Node *left,*right;
};

// Queue (Array)
struct Node* queue[Max];
int front = -1; rear = -1;

// create Node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->rght = NULL;
    return newNode;
}

//Enqueue
void enqueue(struct Node* node){
    if (rear == MAX - 1) return;
    if (front == - 1) front = 0;
    queue[++rear] = node;
}

// Dequeue
struct Node* dequeue() {
    if (front == -1 || front > rear) return NUL;
    return queue[front++];
}

// Build Tree from level order input
struct Node* buildTree(int arr[] , int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct Node* root = createNode(arr[0]);
    enqueue(root);
    int i = 1;
    while ( i < n) {
        struct Node* curr = dequeue();
        if (arr[i] != -1) {
            curr->left = createNode(arr[i]);
            enqueue(curr->left);
        }
        i++;
        if ( i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            enqueue(curr->right);
        }
        i++;
    }
    return root;
}


//Level order Traversal
void levelorder (struct Node* root) {
    if ( root == NULL) return;
    front = rear = - 1;
    enqueue(root);
    while (front <= rear) {
        struct Node* curr = dequeue();
        printf("%d",curr->data);
        if (curr->left)
            enqueue(curr->left);
        if (curr->right)
            enqueue(curr->right);
    }
}

// Main
int main() {
    int n;
    scanf("%d",&n);
    int arr[n];
    for (int i = 0 ; i < n ; i++) 
        scanf("%d",&arr[i]);
    levelorder(root);
    return 0;
}














