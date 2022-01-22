// Max leaf to root path
/*

To understand the problem consider this tree

        5
       /  \
      8    28
     /  \ /  \
    4   9 2   1


Here are 4 path to its leaf nodes

5->8->4 = 17
5->8->9 = 22
5->28->2 = 35
5->28->1 = 34

So the max path is 5->28->2

*/

/*


On following Binary Tree;

                    15
               /          \
              2            3
            /   \          /   \
           4     5         6    7
          /  \   /   \    /  \   /  \
         80   9   10  11   12  13 14  1


*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} node;

typedef struct Queue
{
    int size;
    int f;
    int r;
    node *data; // array of structures, note that this array stores the structure and not pointer to a structure
} queue;

int isEmpty(queue *q)
{
    if (q->f == q->r)
    {
        return 1;
    }
    return 0;
}

void enqueue(queue *q, node *n) // this does the job in O(1)
{
    q->r++;
    q->data[q->r] = *n; // dereferencing the value at node n and then storing it
}

node dequeue(queue *q) // this will return node, and not node * cause our queue's data stores structure and not pointer to a structure
{
    q->f++;
    return q->data[q->f];
}

node *create_node(int data)
{
    node *n = (node *)malloc(sizeof(node)); // creating a node pointer and allocating the memory in heap
    n->data = data;                         // setting the data
    n->left = NULL;                         // setting left and right children to NULL
    n->right = NULL;

    return n;
}

// recursive solution
int max_path(node *root)
{

    if (root == NULL)
    {
        return INT_MIN;
    }

    if (root->left == NULL && root->right == NULL)
    {
        return root->data;
    }

    int m_path = (max_path(root->left) > max_path(root->right)) ? max_path(root->left) : max_path(root->right);

    return root->data + m_path;
}

int main()
{
    node *root = (node *)malloc(sizeof(node)); // its the root node it will store 1 in our case
    node *p2 = (node *)malloc(sizeof(node));   // total nodes are 15 including the root node
    node *p3 = (node *)malloc(sizeof(node));
    node *p4 = (node *)malloc(sizeof(node));
    node *p5 = (node *)malloc(sizeof(node));
    node *p6 = (node *)malloc(sizeof(node));
    node *p7 = (node *)malloc(sizeof(node));
    node *p8 = (node *)malloc(sizeof(node));
    node *p9 = (node *)malloc(sizeof(node));
    node *p10 = (node *)malloc(sizeof(node));
    node *p11 = (node *)malloc(sizeof(node));
    node *p12 = (node *)malloc(sizeof(node));
    node *p13 = (node *)malloc(sizeof(node));
    node *p14 = (node *)malloc(sizeof(node));
    node *p15 = (node *)malloc(sizeof(node));

    root->data = 15; // constructing the root node
    root->left = NULL;
    root->right = NULL;

    p2 = create_node(2);
    p3 = create_node(3);
    p4 = create_node(4);
    p5 = create_node(5);
    p6 = create_node(6);
    p7 = create_node(7);
    p8 = create_node(80);
    p9 = create_node(9);
    p10 = create_node(10);
    p11 = create_node(11);
    p12 = create_node(12);
    p13 = create_node(13);
    p14 = create_node(14);
    p15 = create_node(1);

    // making connections to all the nodes;

    root->left = p2;
    root->right = p3;

    p2->left = p4;
    p2->right = p5;

    p4->left = p8;
    p4->right = p9;

    p8->left = NULL;
    p8->right = NULL;

    p9->left = NULL;
    p9->right = NULL;

    p5->left = p10;
    p5->right = p11;

    p10->left = NULL;
    p10->right = NULL;

    p11->left = NULL;
    p11->right = NULL;

    p3->left = p6;
    p3->right = p7;

    p6->left = p12;
    p6->right = p13;

    p7->left = p14;
    p7->right = p15;

    p12->left = NULL;
    p12->right = NULL;

    p13->left = NULL;
    p13->right = NULL;

    p14->left = NULL;
    p14->right = NULL;

    p15->left = NULL;
    p15->right = NULL;

    printf("The Max Path is :\t%d\n", max_path(root));

    return 0;
}