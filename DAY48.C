#include<stdio.h>
#include<stdlib.h>
// Binary Tree Node
struct Node {
    int data;
    struct Node *left,*right;
};
// create a new node
struct Node* createNode(int data){
      struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
      newNode->data = data;
      newNode->left = NULL;
      newNode->right = NULL;
      return newNode;
}
// count leaf Node recursively
int countLeafNodes(struct Node* root){
    if (root == NULL)
        return 0;
    if (root->left ==  NULL && root->right == NULL)
        return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}
// build tree in level order
struct Node* buildTree(int arr[],int n, int i){
      if ( i >= n)
          return Null;
      struct Node* root = createNode(arr[i]);
      root->left = buildTree(arr,n,2*i+1);
      root->right = buildTree(arr,n,2*i+2);
      return root;
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for (int i = 0 ; i < n; i++){
        scanf("%d",&arr[i]);
    }
    struct Node* root = buildTree(arr,n,0);
    int leafCount = countLeafNodes(root);
    printf("%d\n",leafCount);
    return 0;
}
