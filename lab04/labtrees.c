#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>
#include <assert.h>

/* The following lab was made to check three properties of a binary tree, 
them being: is it complete, what is its height and is it balanced */

/* Defines the node of the tree */
typedef struct Node {
    int data;
    struct Node *left, *right; 
} Node;

typedef Node * p_node; 

/* Creates tree */
p_node create_tree(int x) {
    p_node r = malloc(sizeof(Node)); 
    r->data = x;
    r->left = NULL;
    r->right = NULL;
    return r;
}

p_node free_tree(p_node tree) {
  free(tree->left);
  free(tree->right);
  return tree;
}

p_node search_node(p_node root, int x) {
    p_node left;
    if(root == NULL || root->data == x) {
        return root;
    }
    left = search_node(root->left, x);
    if(left != NULL) {
        return left;
    }
    return search_node(root->right, x);
}

void print_tree(p_node root,int level,FILE * outputFile){
    if(root != NULL){
        printf("%d -> %d \n",level,root-> data);
        fprintf(outputFile,"%d --> %d \n",level,root-> data);
        if(root -> left != NULL){
            print_tree(root->left, level +1,outputFile);
        }
        if(root -> right != NULL){
            print_tree(root->right, level +1,outputFile);
        }  
    }
}

int number_nodes(p_node root) {
    if(root == NULL) {
        return 0;
    }
    return number_nodes((root->left) + number_nodes(root->right) + 1); 
}

/* Finds the height of the tree using the definition of height: 
The height of a tree is defined as the vertex height of its root vertex,
where the vertex height of a vertex in a tree is the number of edges on 
the longest downward path between. and a tree leaf.*/
int find_height(p_node root) {
    int h_left, h_right;
    if(root == NULL) 
        return 0;
    h_left = find_height(root->left);
    h_right = find_height(root->right);
    return 1 + (h_left > h_right ? h_left : h_right);
}

/* Finds out if its balanced according to the following definition:
A binary tree in which the height of the left and right subtree of
 any node differ by not more than 1. */
bool height_balance(p_node root, int *height) {
    int leftHeight, rightHeight, h_left, h_right = 0;
    if (root == NULL) {
        *height = 0;
        return true;
    }
    h_left = height_balance(root->left, &leftHeight);
    h_right = height_balance(root->right, &rightHeight);

    *height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;

    if ((leftHeight - rightHeight >= 2) || (rightHeight - leftHeight >= 2))
        return false;
    else
        return h_left && h_right;
}

/* Check if tree is complete according to the following definition:  A binary tree in 
which every level (depth), except possibly the deepest, 
is completely filled. At depth n, the height of the tree, 
all nodes must be as far left as possible */
bool complete(p_node root){
    if (root == NULL)
        return true;
    if ((root->left) && (root->right))
        return (complete(root->left) && complete(root->right));
    if (root->left == NULL && root->right == NULL)
        return true;
    return false;
}

int main (int argc, char *argv[]) {
    p_node root = (p_node)malloc(sizeof(struct Node));
    root->data = -1; 
    int l, r;
    int height = 0;

    FILE *myFile;
    FILE *myOutput;

    char *tree = argv[1];
    char *outputFile = argv[2];
    myFile = fopen(tree,"r");
    myOutput = fopen(outputFile, "w");

    while (fscanf(myFile, "(%d,%d)\n",&l,&r) != EOF){
        p_node temp = (p_node)malloc(sizeof(struct Node));
        if(root -> data == -1){ 
            root = create_tree(l);
            temp = root;
        } else { 
            temp = search_node(root, l);  
            if(temp -> data == -1){
            }
        }
        if(temp -> data != -1){
            if(temp -> left == NULL){ 
                p_node temp2 = (p_node)malloc(sizeof(struct Node));
                temp2 = create_tree(r);
                temp -> left = temp2; 
            } else if (temp-> right == NULL){ 
                p_node temp2 = (p_node)malloc(sizeof(struct Node));
                temp2 = create_tree(r);
                temp -> right = temp2; 
            }
        }

    }
    fprintf(myOutput,"Parameters for the following tree:\n ");
    print_tree(root,0,myOutput);

    /* Is it balanced? */
    fprintf(myOutput,"Balanced:");
    if (height_balance(root, &height))
        fprintf(myOutput," Yes\n");
    else 
        fprintf(myOutput," No\n");
    
    /* What is the height? */
    int altura = 0;
    altura = find_height(root);
    fprintf(myOutput, "Tree's height:");
    fprintf(myOutput, " %d \n", altura);

    /* Is it complete? */
    fprintf(myOutput, "Complete:");
    if (complete(root)) 
        fprintf(myOutput,"Yes");
    else 
        fprintf(myOutput," No");
    
   fclose(myFile);
   fclose(myOutput);    
   free_tree(root);

    return 0;
}
