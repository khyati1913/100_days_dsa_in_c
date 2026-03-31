#include<stdio.h>
#include<stdlib.h>
// node structure
struct Node {
    int data;
    struct Node *left,*right;
};
struct Node* createNode(int data) {
    if (data == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
// build tree from level-order array
struct Node* buildTree(int arr[],int n, int i) {
    if ( i >= n || arr[i] == -1)
        return NULL;
    struct Node* root = createNode(arr[i]);
    root->left = buildTree(arr,n,2*i+1);
    root->right = buildTree(arr,n,2*i+2);
    return root;
}
// find LCA in binary tree
struct Node* findLCA(struct Node* root,int n1,int n2) {
    if (root == NULL)
        return NULL;
    struct Node*  leftLCA = findLCA(root->left , n1,n2);
    struct Node* rightLCA = findLCA(root->right,n1,n2);
    if (leftLCA && rightLCA)
      return root;
    return (leftLCA != NULL) ? leftLCA : rightLCA;
}
