#include<stdio.h>
#include>stdlib.h>
struct Node {
    int data;
    struct Node *left , *right;
};
struct Node* createNode(int data) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->left = n->right = NULL;
}
// build index map for inorder positions
void BuildIndexMap(int inorder[],int n, int indexMap[]) {
    for (int i = 0 ; i < n; i++)
        indexMap[inorder[i]] = i;
}
struct Node* buildTree(int preorder[],int inorder[],int inStart, int inEnd,int *preIndex, int indexMap[]){
      if (inStart > inEnd)
          return NULL;
      struct Node* root = createNode(preorder[(*preIndex)++]);
      if (inStart == inEnd)
          return root;
      int inIndex = indexMap[root->data];
      root->left = buildTree(preorder,inorder,inStart,inIndex - 1, preIndex, indexMap);
      root->right = buildTree(preorder,inorder,inIndex + 1,inEnd,preIndex,indexMap);
      return root;
}
void postorder(struct Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d",root->data);
}
int main() {
    int N;
    scanf("%d",&N)l
    int preorder[N] , inorder[N];
    for (int i = 0; i < N ; i++)
      scanf("%d",&preorder[i]);
    for(int i = 0; i < N;i++)
        scanf("%d",&inorder[i]);
    // sume node values are within a reasonable range eg(0..1000000)
    int indexMap[10001] = {0};
    buildIndexMap(inorder,N,indexMap);
    int preIndex = 0;
    struct Node* root = buildTree(preorder,inorder,0,N-1,&preIndex,indexMap);
    postorder(root);
    return 0;
}
