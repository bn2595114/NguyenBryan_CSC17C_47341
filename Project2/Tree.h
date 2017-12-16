
#include <cstdlib>
#ifndef TREE_H
#define TREE_H

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* newNode(int data)
{
    struct Node* node = new struct Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}


#endif /* TREE_H */

