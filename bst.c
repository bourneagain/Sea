#include<stdio.h>
typedef struct bst{
int data;
struct bst *left;
struct bst *right;
}bst;

bst* addNode(int data){
	bst *tempNode=malloc(sizeof(bst));
	tempNode->data=data;
	tempNode->left=NULL;
	tempNode->right=NULL;
	return tempNode;
}



void in_order(bst *root){
	if (root==NULL){
		return;
	}
	in_order(root->left);
	printf("%d",root->data);
	in_order(root->right);
	return;
}

void main(){
bst *root=addNode(1);
root->left=addNode(2);
root->left->left=addNode(-1);
root->left->right=addNode(1);
root->right=addNode(30);
root->right->right=addNode(505);
root->right->left=addNode(25);
printf("%d",treeSize(root));
in_order(root);

}
