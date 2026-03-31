#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node *left,*right;
};
struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
struct Node* insertBST(struct Node* root , int data) {
    if (root == NULL) return createNode(data);
    if (data < root->data)
        root->left = insertBST(root->left,data);
    else
      root->right = insertBST(root->right,data);
    return root;
}
struct Node* findLCA(struct Node* root,int n1,int n2) {
      if (root == NULL) return NULL;
      if (n1 < root->data && n2 < root->data)
        return findLCA(root->left ,n1,n2);
      if (n1 > root->data && n2 > root->data)
        return findLCA(root->right , n1 , n2);
      return root;
}
int main() {
    int N , x , n1,n2;
    scanf("%d",&N);
    struct Node* root = NULL;
    for ( int i = 0; i < N ; i++) {
        scanf("%d",&x);
        root = insertBST(root , x);
    }
}
