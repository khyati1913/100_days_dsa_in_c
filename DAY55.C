#include<stdio.h>
#include<stdlib.h>
#define MAX 1000
struct Node {
    int data;
    struct Node *left,*right;
};
struct Node* createNode(int data) {
    if (data == -1) return NULL;
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}
// build Tree from level Order
struct Node* buildTree(int arr[],int n, int i) {
    if ( i >= n || arr[i] == -1)
        return NULL;
    struct Node* root = createNode(arr[i]);
    root->left = buildTree(arr,n,2*i+1);
    root->right = buildTree(arr,n,2*i+2);
    return root;
}
int main() {
    int N;
    scanf("%d",&N);
    int arr[N];
    for (int  i = 0; i < N ; i++)
      scanf("%d",&arr[i]);
    struct Node* root = buildTree(arr,N,0);
    if (root == NULL) return 0;
    struct Node* queue[MAX];
    int front = 0,rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        int levelsize = rear - front;
        for (int i = 0; i <levelsize ; i++){
            struct Node* curr = queue[front++];
        if (curr->left)
          queue[rear++] = curr->left;
        if (curr->right)
          queue[rear++] = curr->right;
        // last node in this level
        if ( i == levelsize - 1)
            printf("%d" , curr->data);
      }
    return 0;
}
