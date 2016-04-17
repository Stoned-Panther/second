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
void inorder(struct node *root){
	if(root==NULL)
		return;
	inorder(root->lchild);
	printf("%d ",root->info);
	inorder(root->rchild);
}
void preorder(struct node *root){
	if(root==NULL)
		return;
	printf("%d ",root->info);
	preorder(root->lchild);
	preorder(root->rchild);
}
struct node *minval(struct node *root){
	struct node *current=root;
	while(current->lchild!=NULL)
		current=current->lchild;
	return current;
}
struct node *del(struct node *root,int item){
	if(root==NULL)
		return root;
	if(item<root->info)
		root->lchild=del(root->lchild,item);
	else if(item>root->info)
		root->rchild=del(root->rchild,item);
	else{
		if(root->lchild==NULL){
			struct node *temp=root->rchild;
			free(root);
			return temp;
		}
		else if(root->rchild==NULL){
			struct node *temp=root->lchild;
			free(root);
			return temp;
		}
		else{
			struct node *temp = minval(root->rchild);
			root->info=temp->info;
			root->rchild=del(root->rchild,temp->info);	
		}
	}
	return root;
}
void mirror(struct node *root){
	if(root==NULL)
		return;
	else
	{
		struct node *tmp;
		mirror(root->lchild);
		mirror(root->rchild);
		tmp=root->lchild;
		root->lchild=root->rchild;
		root->rchild=tmp;
	}
}
int inarr(struct node *root,int a[],int i){
	if(root==NULL)
		return i;
	i=inarr(root->lchild,a,i);
	a[i]=root->info;
	i++;
	i=inarr(root->rchild,a,i);
	return i;
}
void del1(struct node *root){
	if(root==NULL)
		return;
	del1(root->lchild);
	del1(root->rchild);
	printf("deleted node-%d\n",root->info);
	free(root);
}
int main()
{
	int n,item,i;
	struct node *root=NULL;
	scanf("%d",&n);
	for(i = 0; i < n; i++){
		scanf("%d",&item);
		root=insert(root,item);
	}
/*	int a[n];
	int k=inarr(root,a,0);
	int item8;
	scanf("%d",&item8);
	int j = 0;
	while(a[j]!=item8){
		printf("%d ",a[j]);
		j++;
	}*/
//	preorder(root);
//	printf("\n");
//	scanf("%d",&item);
//	root=del(root,item);
//	preorder(root);
	del1(root);
//	mirror(root);
//	preorder(root);
//	printf("\n");
//	while(root!=NULL){
//		root=del(root,root->info);
//		preorder(root);
//		printf("\n");
//	}
	return 0;
}
