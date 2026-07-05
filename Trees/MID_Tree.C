#include <stdio.h>   // For input/output functions like printf
#include <conio.h>   // For clrscr() and getch() (Turbo C)
#include <stdlib.h>  // For malloc()

// Definition of tree node
struct node
{
    int data;               // Stores value of node
    struct node *left;      // Pointer to left child
    struct node *right;     // Pointer to right child
};

// Global root pointer
struct node *root;

// Function to create a new node
struct node *createnode(int data)
{
    struct node *newnode;

    // Allocate memory for new node
    newnode = (struct node *)malloc(sizeof(struct node));

    // Assign data to node
    newnode->data = data;

    // Initialize left and right child as NULL
    newnode->left = newnode->right = NULL;

    // Return the created node
    return newnode;
}

// Inorder Traversal (Left -> Root -> Right)
void inOrder(struct node *root)
{
    // Base condition: if tree is empty
    if (root == NULL)
        return;

    // Visit left subtree
    inOrder(root->left);

    // Print current node
    printf(" %d ", root->data);

    // Visit right subtree
    inOrder(root->right);
}

// Preorder Traversal (Root -> Left -> Right)
void preOrder(struct node *root)
{
    // Base condition
    if (root == NULL)
        return;

    // Print current node
    printf(" %d ", root->data);

    // Visit left subtree
    preOrder(root->left);

    // Visit right subtree
    preOrder(root->right);
}

// Postorder Traversal (Left -> Right -> Root)
void postOrder(struct node *root)
{
    // Base condition
    if (root == NULL)
        return;

    // Visit left subtree
    postOrder(root->left);

    // Visit right subtree
    postOrder(root->right);

    // Print current node
    printf(" %d ", root->data);
}

// Main function
int main()
{
    // Creating tree manually
    root = createnode(10);             // Root node
    root->left = createnode(20);       // Left child of root
    root->right = createnode(30);      // Right child of root
    root->left->left = createnode(40); // Left child of 20
    root->left->right = createnode(50);// Right child of 20

    // Clear screen (Turbo C)
    clrscr();

    // Display Inorder traversal
    printf("\nIn Order : ");
    inOrder(root);

    // Display Preorder traversal
    printf("\nPre Order : ");
    preOrder(root);

    // Display Postorder traversal
    printf("\nPost Order : ");
    postOrder(root);

    // Wait for key press
    getch();

    return 0;  // End of program
}