#include <stdio.h>
#include <stdlib.h>
#include "binary_tree_data_structureEx.h"
#include "hello.h" // For printLine

// Define the space count for 2D tree printing
#define COUNT 10

// 1. Define the structure for a tree node.
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Function to create a new tree node
TreeNode* createTreeNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into a Binary Search Tree (BST)
TreeNode* insertNode(TreeNode* root, int data) {
    // If the tree is empty, return a new node
    if (root == NULL) {
        return createTreeNode(data);
    }

    // Otherwise, recur down the tree
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    // Return the (unchanged) node pointer
    return root;
}

// Function to perform in-order traversal (Left, Root, Right)
void inOrderTraversal(TreeNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// --- Enhanced Tree Printing ---

/**
 * @brief Utility function to print a 2D representation of the tree.
 * This function performs a reverse in-order traversal.
 * @param root The current node.
 * @param space The amount of space to print for indentation.
 */
void printTree2DUtil(TreeNode* root, int space) {
    // Base case
    if (root == NULL) {
        return;
    }

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    printTree2DUtil(root->right, space);

    // Print current node after appropriate spacing
    printf("\n");
    for (int i = COUNT; i < space; i++) printf(" ");
    printf("%d\n", root->data);

    // Process left child
    printTree2DUtil(root->left, space);
}

// Function to free the entire tree (post-order traversal)
void freeTree(TreeNode* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

void binary_tree_data_structureEx(void) {
    printLine("Demonstrating Binary Search Tree (BST)");

    TreeNode* root = NULL; // Start with an empty tree

    // Insert nodes into the BST
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    printf("In-order traversal of the BST (should be sorted): ");
    inOrderTraversal(root);
    printf("\n");

    printf("\nVisual 2D representation of the BST (rotated 90 degrees):\n");
    printf("--------------------------------------------------------\n");
    printTree2DUtil(root, 0);

    freeTree(root);
    printf("Binary tree memory has been freed.\n");
}