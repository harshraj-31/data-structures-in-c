#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// Function to create a new tree node
struct node* createNode(int data)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Recursive function to find the Lowest Common Ancestor
struct node* lowestCommonAncestor(struct node* root, struct node* p, struct node* q)
{
    struct node *left, *right;

    // Base case: if we reach a NULL node, or find either p or q
    if (root == NULL || root == p || root == q)
    {
        return root;
    }

    // Search for p and q in left and right subtrees
    left = lowestCommonAncestor(root->left, p, q);
    right = lowestCommonAncestor(root->right, p, q);

    // If both left and right return a node, current root is the LCA
    if (left != NULL && right != NULL)
    {
        return root;
    }

    // Otherwise, return the non-NULL node (pass it up the chain)
    if (left != NULL)
    {
        return left;
    }
    else
    {
        return right;
    }
}

int main()
{
    struct node *root, *p, *q, *lca;

    /* 
     * Creating a sample binary tree:
     *         3
     *       /   \
     *      5     1
     *     / \   / \
     *    6   2 0   8
     */
    root = createNode(3);
    root->left = createNode(5);
    root->right = createNode(1);
    root->left->left = createNode(6);
    root->left->right = createNode(2);
    root->right->left = createNode(0);
    root->right->right = createNode(8);

    // Let's find LCA for node 5 and node 1
    p = root->left;  // Node 5
    q = root->right; // Node 1

    lca = lowestCommonAncestor(root, p, q);

    if (lca != NULL)
    {
        printf("Lowest Common Ancestor of %d and %d is: %d\n", p->data, q->data, lca->data);
    }
    else
    {
        printf("Lowest Common Ancestor not found.\n");
    }

    return 0;
}
