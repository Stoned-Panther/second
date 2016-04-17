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
int rdis(struct node *root,int key){
	if(root==NULL)
		return;
	int k=0;
	while(root->info!=key){
		k++;
		if(key<root->info)
			root=root->left;
		else
			root=root->right;
	}
	return k;
}
int mindis(struct node *root,int a,int b){
	if(root==NULL)
		return 0;
	if((root->info-a)*(root->info-b)<0)
		return (rdis(root,a)+rdis(root,b));
	if(a<root->info)
		return mindis(root->left,a,b);
	if(a>root->info)
		return mindis(root->right,a,b);
}
int main()
{
	struct node *root=NULL;
	int n,i,item;
	scanf("%d",&n);
	for(i = 0; i < n; i++){
		scanf("%d",&item);
		root=insert(root,item);
	}
	int item1,item2;
	scanf("%d%d",&item1,&item2);
	int j=mindis(root,item1,item2);
	printf("%d\n ",j);
	return 0;
}
 
