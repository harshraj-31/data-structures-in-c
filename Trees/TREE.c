#include<stdio.h>   // For printf() function (input/output)
#include<stdlib.h>  // For malloc() (dynamic memory allocation)

// Structure of a tree node
struct node 
{
    struct node *left;   // Pointer to left child node
    int data;            // Data stored in node
    struct node *right;  // Pointer to right child node
};

// Global root pointer (starting point of tree)
struct node *root;

// Function to create a new node
struct node *createNode(int data)
{
    struct node *newnode;   // Declare pointer for new node

    // Allocate memory for one node
    newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = data;   // Assign given data to node

    // Initially both children are NULL (no child)
    newnode->left = NULL;
    newnode->right = NULL;
    
    return newnode;  // Return address of created node
}

// Inorder Traversal (Left → Root → Right)
void inOrder(struct node *root)
{
    // Base condition: if node is NULL, stop recursion
    if(root == NULL)
    {
        return;
    }

    // Step 1: Go to left subtree
    inOrder(root->left);

    // Step 2: Print current node data
    printf(" %d ", root->data);

    // Step 3: Go to right subtree
    inOrder(root->right);
}

// Preorder Traversal (Root → Left → Right)
void preOrder(struct node *root)
{
    // Base condition
    if(root == NULL)
    {
        return;
    }

    // Step 1: Print current node first
    printf(" %d ", root->data);

    // Step 2: Traverse left subtree
    preOrder(root->left);

    // Step 3: Traverse right subtree
    preOrder(root->right);
}

// Postorder Traversal (Left → Right → Root)
void postOrder(struct node *root)
{
    // Base condition
    if(root == NULL)
    {
        return;
    }

    // Step 1: Traverse left subtree
    postOrder(root->left);

    // Step 2: Traverse right subtree
    postOrder(root->right);

    // Step 3: Print node at the end
    printf(" %d ", root->data);
}

int main()
{
    // ----------- Tree Creation -----------

    // Create root node with value 10
    root = createNode(10);

    // Create left and right child of root
    root->left = createNode(20);
    root->right = createNode(30);

    // Create children of node 20
    root->left->left = createNode(40);
    root->left->right = createNode(50);

    /*
        Tree formed:
        
              10
             /  \
           20    30
          /  \
        40    50
    */

    // ----------- Traversals -----------

    printf("\nIn Order : ");
    inOrder(root);   // Calls inorder traversal

    printf("\nPre Order : ");
    preOrder(root);  // Calls preorder traversal

    printf("\nPost Order : ");
    postOrder(root); // Calls postorder traversal

    return 0;  // End of program
}