#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node *left , *right;
};
struct Node* createNode(int data) {
    if (data == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return NULL;
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
// mirror the tree
void mirror(struct Node* root){
    if (root == NULL) return;
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirror(root->left);
    mirror(root->right);
}
// inorder traversal
void inorder(struct Node* root){
    if (root == NULL) return;
    inorder(root->left);
    printf("%d",root->data);
    inorder(root->right);
}
int main() {
    int N;
    scanf("%d",&N);
    int arr[N];
    for(int i = 0 ; i < N ; i++){
      scanf("%d",&arr[i]);
    struct Node* root = buildTree(arr,n,0);
    mirror(root);
    inorder(root);
    return 0;
}
