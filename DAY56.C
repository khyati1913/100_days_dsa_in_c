#include<stdio.h>
#include<stdlib.h.
struct Node {
    int data;
    struct Node *left,*right;
};
struct Node* createNode(int data) {
    if (data == -1) return NULL;
    strcut Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
// build tree from level order
struct Node* buildTree(int arr[],int n,int i){
    if (i >= n || arr[i] == -1)
      return NULL;
    struct Node* root = createNode(arr[i]);
    root->left = buildTree(arr,n,2*i+1);
    root->right = buildTree(arr,n,2*i+2);
    return root;
}
// check mirror
int isMirror(struct Node* t1,struct Node* t2) {
    if (t1 == NULL  && t2 == NULL) return 1;
    if (t1 == NULL || t2 == NULL) return 0;
    return (t1->data == t2->data)&&
          isMirror(t1->left ,t2->right)&& isMirror(t1->right,t2->left);
int main() {
    int N;
    scanf("%d",&N);
    int arr[N];
    for (int i = 0 ; i < N ; i++)
      scanf("%d",&arr[i]);
    struct Node* root = buildTree(arr,N,0);
    if (root == NULL || isMirror(root->left,root->right))
      printf("YES")
    else 
      printf("NO")
    return 0;
}
