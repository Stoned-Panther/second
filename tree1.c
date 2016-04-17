#include<stdio.h>
#include<stdlib.h>
struct node {
	int info;
	struct node *lchild;
	struct node *rchild;
};
struct node *createnode(int item)
{
	struct node *tmp=(struct node*)malloc(sizeof(struct node));
	tmp->info=item;
	tmp->lchild=NULL;
	tmp->rchild=NULL;
	return tmp;
}
struct node *insert(struct node *root,int item){
	if(root==NULL){
		root=createnode(item);
		return root;
	}
	else if(item < root->info)
		root->lchild=insert(root->lchild,item);
	else if(item > root->info)
		root->rchild=insert(root->rchild,item);
	else
		printf("duplicate keys\n");
	return root;
}
void preorder(struct node *root){
	if(root==NULL)
		return;
	printf("%d ",root->info);
	preorder(root->lchild);
	preorder(root->rchild);
}
void inorder(struct node *root,int a[],int i){
	if(root==NULL)
		return;
	inorder(root->lchild,a,i+1);
	a[i]=root->info;
	printf("%d ",root->info);
	inorder(root->rchild,a,i+1);
}
void postorder(struct node *root){
	if(root==NULL)
		return;
	postorder(root->lchild);
	postorder(root->rchild);
	printf("%d ",root->info);
}
int height(struct node *root){
	if(root==NULL)
		return 0;
	else{
		int lh=height(root->lchild);
		int rh=height(root->rchild);
		if(lh<rh)
			return (rh+1);
		else
			return (lh+1);
	}
}
void printlevel(struct node *root,int level){
	if(root==NULL)
		return;
	if(level==1){
		printf("%d ",root->info);
	}
	else if(level>1){
		printlevel(root->lchild,level-1);
		printlevel(root->rchild,level-1);
	}
} 
void levelorder(struct node *root){
	int h=height(root);
	int i;
	for(i=1;i<=h;i++){
		printlevel(root,i);
	}
}
int main()
{
	struct node *root=NULL;
	int i=8,item;
	while(i>0){
		scanf("%d",&item);
		root=insert(root,item);
		i--;
	}
	int a[8];
	int j = 0;
	preorder(root);
	printf("\n");
	inorder(root,a,j);
	printf("\n");
	postorder(root);
	printf("\n");
	levelorder(root);
	printf("\n");
	return 0;
}
