/*******************************************
** Name: Andy James
** Email: jameandy@oregonstate.edu
** ID 933338855
********************************************/
#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
 
void traverse(struct Node* n);
struct Node* new_node(int);
int max_height(struct Node* n);
void delete(struct Node* n);

int main(int argc, char* argv[]) {
    int i;

    // save command line arguments (keys) in an array
    int* A = malloc(argc * sizeof(int));
    for (i=1; i<argc; i++) {
        A[i] = atoi(argv[i]);
    }

    // create BST
    struct BST* b = createBST();

    // insert keys
    for (i=1; i<argc; i++) {

        insert(b, A[i]);
    }

    // do inorder traversal of BST
    inorderTraversal(b);

    // print BST height
    printf("BST height: %d\n\n", height(b));

    // print the depth of all BST nodes
    for (i=1; i<argc; i++) {
        printf("Depth of %4d: %4d\n", A[i], depth(b, A[i]));
    }

    //remove slashes to find number not in list
    //printf("Depth of %4d: %4d\n", 20, depth(b, 20)); 

    printf("\n");
    
    // cleanup BST nodes and BST
    deleteBST(b);

    free(A);
    
    return 0;
    
}

struct BST* createBST() {
    struct BST* b = malloc(sizeof(struct BST));
    b->root = NULL;
    return b;
}

void insert(struct BST* b,int num) {
    struct Node* n = new_node(num);
    if(b->root == NULL) { // if tree is empty
        b->root = n;
    }
    else {
        struct Node* curr = b->root;
        struct Node* parent = NULL;
        while(curr != NULL) { // traverses based on BST propertys         
            parent = curr;
            if(num < curr->key) {
                curr = curr->left;
            }
            else {
                curr = curr->right;
            }
        }
        if(num < parent->key) {
            parent->left = n;
        }
        else {
            parent->right = n;  
        }
    }
}
struct Node* new_node(int num) {
    struct Node* n = malloc(sizeof(struct Node));
    n->right = NULL;
    n->left = NULL;
    n->key = num;
    return n;
}

void inorderTraversal(struct BST* b) {
    printf("In-order Traversal\n");
    traverse(b->root);
    printf("\n");
}

void traverse(struct Node* n) {
    // traverses recursively until node path does not have a child
    if(n == NULL) {
        return;
    }
    traverse(n->left);
    printf("%i ",n->key);
    traverse(n->right);
    
}

int height(struct BST* b) {
    return max_height(b->root);
}

int max_height(struct Node* n) {
    if(n == NULL) {
        return -1;
    }
    else {
        int left_height = max_height(n->left);
        int right_height = max_height(n->right);
        //returns the highest of the right or left subtree to continue on
        if(left_height > right_height) {
            return left_height + 1;
        }
        else {
            return right_height + 1;
        }
    }
}

int depth(struct BST* b, int num) {
    struct Node* n = b->root;
    int d = 0;
    while(1) {
        if(n == NULL) { // if key does no exist
            return -1;
        }       
        if(num > n->key) {
            n = n->right;
        }
        else if(num < n->key) {
            n = n->left;
        }
        else {
            return d;
        }
        d++;
    }
}

void deleteBST(struct BST* b) {
    delete(b->root);
    free(b);
    printf("Congrats your tree has been yeeted from memory\n");
}

void delete(struct Node* n) {
    if(n == NULL) {
        return;
    }
    delete(n->left);
    delete(n->right);
    printf("free: %4d\n", n->key);
    free(n);
}
