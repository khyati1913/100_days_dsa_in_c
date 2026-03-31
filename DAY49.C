#include<stdio.h>
#include<stdlib.h>
// BST node
struct Node{
    int data;
    struct Node *left,*right;
};
// create node
struct Node* createNode(int data) {
      struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
      newNode->data = data;
      newNode->left = NULL;
      newNode->right = NULL;
      return newNode;
}
// INSER INTO BST
struct Node* insertBST(struct Node* root,int data){
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
      root->left = insertBST(root->left, data);
    else 
      root->right = insertBST(root->right,data);
    return root;
}
// inorder traversal
void inorder(struct Node* root) {
    if (root != NULL) {
      inorder(root->left);
      printf("%d",root->data);
      inorder(root->right);
    }
}
int main() {
    int n, value;
    scanf("%d",&n);
    struct Node* root  = NULL;
    for (int i = 0; i < n ; i++){
        scanf("%d",&value);
        root = insertBST(root,value);
    }
    inorder(root);
    return 0;
}
