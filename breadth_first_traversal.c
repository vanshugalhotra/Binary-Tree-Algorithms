/*

Note that: Depth First Traversal is , PreOrder, PostOrder, InOrder

-------------------------------Breadth First Traversal
Lets say we have a binary tree like this.....\


        5
       /  \
      8    28
     /  \ /  \
    4   9 2   1

Here the problem says that we need to traverse in our Binary Tree in following way

    5    8   28   4    9      2      1

Solution 1:  Time Complexity  O(n)     Space Complexity    O(n)

    (   Note: we must ensure that insertion and deletion from queue occurs in O(1)  )

    So to do this we can use "Queue" Data Structure

    So we will start from root, i.e 5 and we will enqueue(push) it to queue

    After each iteration we will check

        isOur Queue Empty;
            Yes: Then fill it
            No: Then dequeue(remove) the element from it and print it

    so after 1st iteration "5" will be printed
    on 2nd iteration queue is empty so we will enqueue(push) 5->left & 5->right i.e, 8 & 28 respectively
    so now our queue is not empty so lets dequeue our elements and print them...
    on next iteration queue is again empty so lets push, (8->left & 8->right) & (28->left & 28->right)
    and do the same untill we reaches NULL

    Hence, we got 5  8  28  4  9  2  1


*/

#include <stdio.h>
#include <stdlib.h>

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

node *createNode(int data)
{
    node *n = (node *)malloc(sizeof(node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n;
}

/*

DRY running the following function for our Tree.

So first our queue looks like this

  | 5 |  |   |  .....

So we enters the while loop , cuz our queue is not empty.
    now we dequeue from queue, and
    now our current = 5;
    we print it

    and now we pushes 5->left and 5->right to the queue.

    So our queue looks like this (in memory our 5 still exists but as we have moved our "f" we cant access it)

    |..|  8  |  28 |

    and now we dequeue,
    and our current = 8;

    once again we pushes 8->left and 8->right into queue

    So our queue looks like this

    | .. | .. | 28 | 4  | 9  |

    now we again dequeue from queue
    this time, current = 28;
    print it;

    lets push, 28->left and 28->right

    so our queue is...

    | .. | .. | .. | 4 | 9 | 2 | 1 |

    so lets dequeue from queue
    current = 4;
    print 4;

    now, 4->left == NULL so it won't be enqueued, also 4->right

    so our queue is ......

    | .. | .. | .. | .. | 9 | 2 | 1 |

    It will keep going unitll our queue is empty....means when 1 is queued and printed

    So our final output will be....

    5  8  28  4  9  2  1


*/

void Breadth_first_Traversal(node *root)
{
    queue *q = (queue *)malloc(sizeof(queue));
    q->size = 20; // well it will be equal to number of nodes (n), taking it constant to make things simple
    q->f = q->r = -1;
    q->data = (node *)malloc(q->size * sizeof(node));

    enqueue(q, root); // inserting our root node to the queue

    while (!isEmpty(q))
    {
        node current = dequeue(q); // storing the currently deleted node;
        printf("%d  ", current.data);
        if (current.left != NULL) // if our current node, i.e recently deleted from our queue, has its child nodes then we push that in our queue
        {
            enqueue(q, current.left); // also we are using current.left and not current->left , cuz our current is not a pointer to a structure, it is a structure
        }
        if (current.right != NULL)
        {
            enqueue(q, current.right);
        }
    }
}

int main()
{
    node *root, *p1, *p2, *p3, *p4, *p5, *p6;

    root = createNode(5); // we could have done this using an insert function
    p1 = createNode(8);
    p2 = createNode(28);
    p3 = createNode(4);
    p4 = createNode(9);
    p5 = createNode(2);
    p6 = createNode(1);

    // making connections
    root->left = p1;
    root->right = p2;

    p1->left = p3;
    p1->right = p4;

    p2->left = p5;
    p2->right = p6;

    Breadth_first_Traversal(root);

    return 0;
}