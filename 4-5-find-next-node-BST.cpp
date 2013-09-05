/*
 * Song Qiang <qiang.song@usc.edu> 
 *
 */

/*

Write an algorithm to find the ‘next’ node (i.e., in-order successor)
of a given node in a binary search tree where each node has a link to
its parent.

 */

BSTNode*
get_next_nodes(BSTNode* node)
{
    assert(node != NULL);
    if (node->right != NULL)
    {
        BSTNode* p = node->right;
        while (p->left != NULL) p = p->left;
        return p;
    }
    else
    {
        BSTNode* p = node;
        while (p->parent->left != p) p = p->parent;
        return p->parent;
    }
}

