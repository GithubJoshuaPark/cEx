#include <stdio.h>
#include <stdlib.h>
#include "binary_tree_data_structureEx.h"
#include "hello.h" // For printLine

// Define the space count for 2D tree printing
#define COUNT 10

// --- Helper Function for input ---
void clearBstInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

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

// Function to perform pre-order traversal (Root, Left, Right)
void preOrderTraversal(TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// Function to perform post-order traversal (Left, Right, Root)
void postOrderTraversal(TreeNode* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

/**
 * @brief Finds the node with the minimum value in a given tree.
 * In a BST, this is the leftmost node.
 * @param node The root of the tree/subtree to search.
 * @return A pointer to the node with the minimum value.
 */
TreeNode* findMinValueNode(TreeNode* node) {
    TreeNode* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

/**
 * @brief Deletes a node with the given data from the BST.
 * @param root The root of the tree.
 * @param data The data of the node to delete.
 * @return The root of the modified tree.
 */
TreeNode* deleteNode(TreeNode* root, int data) {
    // Base case: If the tree is empty
    if (root == NULL) return root;

    // Recur down the tree
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    }
    // If data is same as root's data, then this is the node to be deleted
    else {
        // Case 1 & 2: Node with only one child or no child
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Node with two children
        // Get the inorder successor (smallest in the right subtree)
        TreeNode* temp = findMinValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
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

void show_bst_menu(void) {
    printf("\n--- Binary Search Tree Menu ---\n");
    printf("1. In-order Traversal\n");
    printf("2. Pre-order Traversal\n");
    printf("3. Post-order Traversal\n");
    printf("4. Insert Node\n");
    printf("5. Delete Node\n");
    printf("6. Print 2D Tree\n");
    printf("7. Back to Main Menu\n");
    printf("-------------------------------\n");
    printf("Enter your choice: ");
}

void binary_tree_data_structureEx(void) {
    printLine("Interactive Binary Search Tree (BST)");

    TreeNode* root = NULL;
    int choice = 0;

    // Insert some initial nodes for demonstration
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);
    
    while (choice != 7) {
        show_bst_menu();
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input. Please enter a number.\n");
            clearBstInputBuffer();
            continue;
        }
        clearBstInputBuffer();

        switch (choice) {
            case 1:
                printf("\nIn-order traversal: ");
                inOrderTraversal(root);
                printf("\n");
                break;
            case 2:
                printf("\nPre-order traversal: ");
                preOrderTraversal(root);
                printf("\n");
                break;
            case 3:
                printf("\nPost-order traversal: ");
                postOrderTraversal(root);
                printf("\n");
                break;
            case 4: {
                int value;
                printf("Enter value to insert: ");
                scanf("%d", &value);
                clearBstInputBuffer();
                root = insertNode(root, value);
                printf("Value %d inserted.\n", value);
                break;
            }
            case 5: {
                int value;
                printf("Enter value to delete: ");
                scanf("%d", &value);
                clearBstInputBuffer();
                root = deleteNode(root, value);
                printf("Value %d deleted (if it existed).\n", value);
                break;
            }
            case 6:
                printf("\n--- 2D Tree Representation ---\n");
                printTree2DUtil(root, 0);
                printf("------------------------------\n");
                break;
            case 7:
                printf("\nReturning to main menu...\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    }

    freeTree(root);
    printf("Binary tree memory has been freed.\n");
}