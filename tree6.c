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
void kdis(struct node *root,int k)
{
	if(k==0){
		printf("%d ",root->info);
		return;
	}
	kdis(root->lchild,k-1);
	kdis(root->rchild,k-1);
}
struct node *del_leaf(struct node *root){
	if(root!=NULL)
	{
		if(root->lchild==NULL && root->rchild == NULL){
			free(root);
			return NULL;
		}	
		else{
			root->lchild=del_leaf(root->lchild);
			root->rchild=del_leaf(root->rchild);
		}
	}	
	return root;
}
void anc(struct node *root, int key){
	if(root==NULL)
		return;
	if(root->info==key || root->lchild->info==key || root->rchild->info==key){
		printf("no ancestor\n");
		return;
	}
	while(root->lchild->info!=key && root->rchild->info!=key){
		if(key<root->info){
			printf("%d ",root->info);
			root=root->lchild;
		}
		else if(key>root->info){
			printf("%d ",root->info);
			root=root->rchild;
		}
	}
}
int main()
{
	int n,i,k,item,key;
	struct node *root=NULL;
	scanf("%d",&n);
	for(i = 0; i < n; i++){
		scanf("%d",&item);
		root=insert(root,item);
	}
//	scanf("%d",&k);
//	kdis(root,k);
	scanf("%d",&key);
	anc(root,key);
//	root=del_leaf(root);
//	preorder(root);
//	printf("\n");
	return 0;
}
