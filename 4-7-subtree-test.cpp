/*
 * Song Qiang <qiang.song@usc.edu> 
 *
 */

/*
    
You have two very large binary trees: T1, with millions of nodes, and
T2, with hundreds of nodes. Create an algorithm to decide if T2 is a
subtree of T1.

 */

// logical subtree
// something like KMP string match method

bool
is_subtree_at(TreeNode* t1, TreeNode* t2)
{
    return (t2 == NULL)
        || (t1 != NULL
            && t1->val == t2->val
            && is_subtree_at(t1->left, t2->left)
            && is_subtree_at(t1->right, t2->right));
}

bool
is_subtree(TreeNode* t1, TreeNode* t2)
{
    return is_subtree_at(t1, t2)
        || (t1 != NULL && (is_subtree(t1->left, t2)
                           || is_subtree(t1->right, t2)));
}

