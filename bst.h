int isBSTWrapper(struct node* root,int min,int max);
int isBST(struct node *root);
struct node* insert(struct node* root,int key);
void inorder(struct node*);
void postorder(struct node*);
struct node* createNode(int key);
void printLevelOrder(struct node *root);
int getHeight(struct node* root);
int treeSize(struct node* root);
void printLevelNodeValues(struct node* root,int level);
//struct node* LCA(struct node* root,int k1,int k2);
//struct node* LCABST(struct node* root,int k1,int k2);	
int findLevel(struct node* root,int k,int level);

struct node* findMinNode(struct node* root);
struct node* deleteNode(struct node *root,int key);

int findDistanceTwoNodes(struct node* root,int n1,int n2);
//struct node* findDistanceHelper(struct node* root,int n1,int n2,int d1,int d2,int &dist,int lvl);

 //for i in `cat /tmp/a`; do echo $i `grep -c $i /tmp/a`; done | sort -unrk2 | head -2

struct node
{
    int data;
    struct node* left;
    struct node* right;
}node;

int returnCloseMatch(struct node *root,int v){

	struct node *temp=NULL;
	while(root!=NULL){
	if ( root->data == v)
		return root->data;
	if ( root->data <= v){
		root=root->left;
	} else {
		root=root->right;
	}
	}
}

struct node* findMin(struct node *root){
	if ( root == NULL ) return NULL;
	while(root->left!=NULL){
		root=root->left;
	}
	return root;
}

struct node* deleteNode(struct node* root,int key){
	if ( root == NULL ){
		return NULL;
	}
	if ( key < root->data ){
		root->left=deleteNode(root->left,key);

	}
	if (key > root->data ){
		root->right=deleteNode(root->right,key);
	} else {

		if ( root->left == NULL && root->right == NULL ){
			delete root;
			root=NULL;
			return root;
		}else if ( root->left == NULL ){
			struct node *temp=root;
			root=root->right;
			delete temp;
			return root;
		} else if ( root->right == NULL ){
			struct node *temp=root;
			root=root->left;
			delete temp;
			return root;
		}else{
			// where there are two children;
			struct node *temp=findMinNode(root->right);
			root->data=temp->data;
			root->right=deleteNode(root->right,temp->data);
			return root;

		}
	}

}

// struct node* findDistanceHelper(struct node* root,int n1,int n2,int &d1,int &d2,int &dist,int lvl){
// 	if ( root == NULL ) return NULL;
// 	if ( root->data == n1 ) {
// 		d1=lvl;
// 		return root;
// 	}
// 	if ( root->data == n2 ) {
// 		d2=lvl;
// 		return root;
// 	}

// 	struct node *left_LCA=findDistanceHelper(root->left,n1,n2,d1,d2,dist,lvl+1);
// 	struct node *right_LCA=findDistanceHelper(root->right,n1,n2,d1,d2,dist,lvl+1);

// 	if (left_LCA && right_LCA) 
// 		dist=d1+d2-2*lvl;
// 		return root;


// }

int findDistanceTwoNodes(struct node* root,int n1,int n2){
	// find the distance from root to LCA of the two nodes 
	// find distance of each n1,n2 from root
	// return distance between nodes as 
	int dist;
	int d1=-1;
	int d2=-2;
	
//struct node *LCA = findDistanceHelper(root,n1,n2,d1,d2,dist,1);
	return 0;

}

int findLevel(struct node *root, int k, int level){
    // Base Case
    if (root == NULL)
        return -1;
 
    // If key is present at root, or in left subtree or right subtree,
    // return true;
    if (root->data == k)
        return level;
 
    int l = findLevel(root->left, k, level+1);
    return (l != -1)? l : findLevel(root->right, k, level+1);
}


int findDistance(struct node* root,int key){
	//cout << "rotodata " << endl << root->data << distance << endl;

	static int distance=0;
	printf("%p:%d\n",root,distance);
	if ( root == NULL) return distance-1;
	if ( root->data == key) 
		return distance-1;
	if ( root->data < key ){
		distance++;
		return findDistance(root->left,key);
	}else{
		distance++;
		return findDistance(root->right,key);
	}

}


// struct node* LCABST(struct node* root,int k1,int k2){
// 	while(root!=NULL) {
// 		if(root->data < k1 && root->data < k2 ){
// 			return(LCA(root->right,k1,k2));
// 		}else if(root->data > k1 && root->data > k2 ){
// 			return(LCA(root->left,k1,k2));
// 		}else{
// 			break;
// 		}
// 	}
// 	if ( root == NULL ) 
// 		return NULL;
// 	else
// 		return root;
// }
// // struct node* LCA(struct node* root,int k1,int k2){
// // bool foundK1=false;
// // bool foundK2=false;
// // node*
// }
	
	

void printLevelNodeValues(struct node* root,int level){
	if ( root == NULL ) return;
	if ( level == 1 ) printf("%d ",root->data);
	if ( level > 1) {
		printLevelNodeValues(root->left,level-1);
		printLevelNodeValues(root->right,level-1);
	}

}



int getHeight(struct node* root){
	if ( root == NULL ){
		return 0;
	}
	int lheight=getHeight(root->left);
	int rheight=getHeight(root->right);
	return ( (lheight > rheight) ? lheight+1 : rheight+1);
}
void printLevelOrder(struct node* root){
	int height=getHeight(root);
	for(int i=1;i<=height;i++){
		printLevelNodeValues(root,i);
		printf("\n");
	}
	// at each height, print the nodes,

}
int treeSize(strut node *head){

	if ( head == NULL ) return 0;
	int count=0;
	count++;
	return ( treeSize(head->left) + treeSize(head->right) + 1);
}

int isBSTWrapper(struct node* root,int min,int max){
	if ( root == NULL ){
		return 1;
	}
	if ( root->data < min || root->data > max) {
		return 0;
	}
	return(isBSTWrapper(root->left,min,root->data-1) && 
		isBSTWrapper(root->right,root->data+1,max));
}
int isBST(struct node *root){
	return isBSTWrapper(root,INT_MIN,INT_MAX);
}
struct node* createNode(int key){
	struct node *temp=(struct node*)(malloc(sizeof(struct node)));
	temp->data=key;
	temp->left=temp->right=NULL;
	return temp;
}
struct node* insert(struct node* root,int key){
	if ( root == NULL ){
		return createNode(key);
	}
	if(key<=root->data){
		root->left=insert(root->left,key);
	}else{
		root->right=insert(root->right,key);
	}
	return root;
}
void postorder(struct node* root){
	if (root == NULL){
		return;
	}
	inorder(root->left);
	inorder(root->right);
	printf("%d\n",root->data);
	return;
}
void inorder(struct node* root){
	if (root == NULL){
		return;
	}
	inorder(root->left);
	printf("%d\n",root->data);
	inorder(root->right);
	return;
}
