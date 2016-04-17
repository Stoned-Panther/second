#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *left,*right;
};
struct node *createnode(item){
	struct node *root=(struct node*)malloc(sizeof(struct node));
	root->info=item;
	root->left=NULL;
	root->right=NULL;
	return root;
}
struct node *insert(struct node *root,int item){
	if(root==NULL){
		root=createnode(item);
		return root;
	}
	else if(item<root->info)
		root->left=insert(root->left,item);
	else if(item>root->info)
		root->right=insert(root->right,item);
	else
		printf("duplicate keys\n");
	return root;
}
int search(struct node *root,int item){
	while(root!=NULL)
	{
		if(item<root->info)
			root=root->left;
		else if(item>root->info)
			root=root->right;
		else
			return 1;
	}
	return 0;
}
void printarr(int a[],int len){
	int i;
	for(i = 0; i < len; i++)
		printf("%d ",a[i]);
	printf("\n");
}
void printpath(struct node *root,int path[],int pathlen){
	if(root==NULL)
		return;
	path[pathlen]=root->info;
	pathlen++;
	if(root->left==NULL && root->right==NULL)
	{
		printarr(path,pathlen);
	}
	else{
		printpath(root->left,path,pathlen);
		printpath(root->right,path,pathlen);
	}
}
void printlen(struct node *root){
	int path[1000];
	printpath(root,path,0);
}
int countleafs(struct node *root,int count,int *sum){
	if(root==NULL)
		return count;
	if(root->left==NULL && root->right==NULL){
		count++;
		(*sum)+=root->info;
	}
	count=countleafs(root->left,count,&(*sum));
	count=countleafs(root->right,count,&(*sum));
	return count;
}
int main()
{
	int n,k,item,i;
	struct node *root=NULL;
	scanf("%d",&n);
	for(i = 0; i < n; i++){
		scanf("%d",&item);
		root=insert(root,item);
	}
	/*scanf("%d",&k);
	for(i = 0; i < k; i++){
		scanf("%d",&item);
		if(search(root,item)==1)
			printf("Y\n");
		else
			printf("N\n");
 	}*/
	//printlen(root);
	int count=0,sum=0;
	count=countleafs(root,count,&sum);
	printf("%d %d\n",count,sum);
	return 0;
}
