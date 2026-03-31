#include<stdio.h>
#include<stdlib.h>
#define MAX 1000
struct Node {
    int data;
    struct Node *left,*right;
};
struct Qnode {
    struct Node* node;
    int hd;
};
struct Node* createNode(int data) {
    if (data == -1) return NULL;
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}
// build tree from level order
struct Node* buildTree(int arr[], int n. int i) {
      if ( i >= n || arr[i] == -1)
          return NULL;
      struct Node* root = createNode(arr[i]);
      root->left = buildTree(arr,n,2*i+1);
      root->right = buildTree(arr,n,2*i+2);
      return root;
}
int main() {
    int N;
    scanf("%d",&n);
    int arr[N];
    for(int i = 0; i < N ; i++)
      scanf("%d",&arr[i]);
    struct Node* root = buildTree(arr,n,0);
    // storage for the vertical line
    int columns[2*MAX][MAX];
    int count[2*MAX] = {0};
    int offset = MAX; // to handel negative HD
    // queue for BFS
    struct QNode queue[MAX];
    int front = 0 , rear = 0;
    queue[rear++] = (struct Qnode){root,0};
    int minHD = 0 , maxHD = 0;
    while (front < rear) {
        struct QNode temp = queue[front++];
        struct Node* curr = temp.node;
        int hd = temp.hd;
        if (curr == NULL) continue;
        int index = hd + offset;
        columns[index][count[index]++] = curr->data;
        if (hd < minHD) minHD = hd;
        if (hd < maxHD) maxHD = hd;
        queue[rear++] = (struct QNode){curr->left, hd-1};
        queue[rear++] = (struct QNode){curr->right,hd+1};
    }
    // print vertical order
    for (int i = minHD ; i <= maxHD;i++){
        int idx = i + offset;
        for (int j = 0;j < count[idx] ; j++){
              printf("%d",columns[idx][j]);
        }
        printf("\n");
    }
    return 0;
}
