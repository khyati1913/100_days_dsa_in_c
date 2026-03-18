#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *left , *right;
};

struct Node* createNode(int data) {
    struct Node* newNoe = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int height(struct Node* root) {
    if (root == NULL) 
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// Queue for building tree
struct Node* queue[1000];
int front = 0, rear = 0;

void enqueue(struct Node* node) {
    queue[rear++] = node;
}
struct Node* dequeue() {
    return queue[front++];
}

// Build tree from level order 
struct Node* buildTree(int arr[] , int n) {
    if (n == 0 || arr[0] == -1 ) return NULL;
    struct Node* root  = createNode(arr[0]);
    enqueue(root);
    int i = 1;
    while ( i < n) {
        struct Node* curr = dequeue();
        // Left child 
        if (arr[i] != -1) {
          curr->left = createNode(arr[i]);
          enqueue(curr->left);
        }
        i++;
        if (i >= n ) break;
        // Right child
        if (arr[i] != -1) {
          curr->right = createNode(arr[i]);
          enqueue(curr->right);
        }
        i++;
    }
    return root;
}
// Main funtion
int main() {
    int n;
    scanf("%d",&n);
    int arr[n];
    for (int i = 0 ; i < n ; i++) {
        scanf("%d",&arr[i]);
    }
    struct Node* root = buildTree(arr, n);
    printf("%d\n",height(root));
    return 0;
}

