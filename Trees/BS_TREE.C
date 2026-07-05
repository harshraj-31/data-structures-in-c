#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};
struct node *root = NULL;
struct node* findMin(struct node*);


struct node* findMin(struct node *root)
{
while (root->left!=NULL)
root=root->left;
return root;
}

struct node* createnode(int data)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}

struct node *insert(struct node *root,int data)
{
    if(root==NULL)
	return createnode(data);

    if(data < root->data)
	root->left = insert(root->left, data);

    else if(data > root->data)
	root->right = insert(root->right, data);

    return root;
}

struct node* search(struct node *root, int key)
{
    if(root == NULL || root->data == key)
	return root;

    if(key < root->data)
	return search(root->left, key);

    return search(root->right, key);
}

struct node* deletenode(struct node *root, int key) // DELETE
{
   struct node* temp;
   if(root==NULL)
	return root;
   if(key<root->data)
	root->left=deletenode(root->left,key);
   else if(key > root->data)
	root->right=deletenode(root->right,key);
   else
   {
	 if (root->left==NULL)
		return root->right;
	 else if(root->right==NULL)
		return root->left;
	 temp=findMin(root->right);
	 root->data=temp->data;
	 root->right=deletenode(root->right,temp->data);
   }
    return root;
}
void inorder(struct node *root)
{
    if(root == NULL)
	return;
    inorder(root->left);
    printf(" %d ", root->data);
    inorder(root->right);
}

void preorder(struct node *root)
{
    if(root == NULL)
	return;

    printf(" %d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node *root)
{
    if(root == NULL)
	return;

    postorder(root->left);
    postorder(root->right);
    printf(" %d ", root->data);
}

int main()
{
    int ch,val;
    clrscr();

    do{
	printf("\n1.insert\n");
	printf("2.preorder\n");
	printf("3.postorder\n");
	printf("4.inorder\n");
	printf("5.search\n");
	printf("6.delete\n");
	printf("0.exit\n");
	printf("ENTER THE CHOICE: ");
	scanf("%d",&ch);

	switch(ch)
	{
	    case 1:
		printf("ENTER THE VALUE");
		scanf("%d",&val);
		root = insert(root,val);
		break;

	    case 2:
		preorder(root);
		break;

	    case 3:
		postorder(root);
		break;

	    case 4:
		inorder(root);
		break;

	    case 5:
		printf("ENTER THE VALUE TO SEARCH");
		scanf("%d",&val);

		if(search(root,val) != NULL)
		    printf("ELMENTS FOUND\n");
		else
		    printf("ELEMENTS NOT FOUND\n");
		break;

	  case 6:
		 printf("ENTER THE NUMBER TO DELETE=>");
		 flushall();
		 scanf("%d",&val);
		 root=deletenode(root,val);
		 break;

	    case 0:
                exit(0);
        }

    }while(ch!=0);

    getch();
    return 0;
}