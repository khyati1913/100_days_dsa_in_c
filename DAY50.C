#include<stdio.h>
#include<stdlib.h>
// BST node
struct Node {
    int data;
    struct Node *left,*right;
};
// create Node
struct Node* newNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
// insert into BST
struct Node* insertBST(struct Node* root,int data){
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insertBST(root->left,data);
    else if (data > root->data)
        root->right = insertBST(root->right,data);
    return root;
}
// search in BST
int searchBST(struct Node* root,int key) {
    if (root == NULL)
      return 0;
    if (root->data == key)
        return 1;
    else if (key < root->data)
        return searchBST(root->left,key);
    else 
      return searchBST(root->right,key);
}
int main() {
    int n,value,key;
    scanf("%d",&n);
    struct Node* root = NULL;
    for (int i = 0; i < n ; i++){
        scanf("%d",&value)
        root = insertBST(root,value);
    }
    scanf("%d",&key);
    if (searchBST(root,key))
        printf("Found");
    else
      printf("Not Found");
