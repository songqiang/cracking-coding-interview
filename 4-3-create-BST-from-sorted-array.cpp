/*
 * Song Qiang <qiang.song@usc.edu> 
 *
 */

/*

Given a sorted (increasing order) array, write an algorithm to create
a binary tree with minimal height.

 */

void
build_BST_from_array(int[] a, int s, int t, BSTNode* &root)
{
    if (s == t) 
    {
        root = NULL;
        return;
    }

    const int n = t - s;
    const int first_half = (n - 1) / 2;
    const int second_half = n - 1 - first_half;
    
    root = new BSTNode;
    root->val = a[s + first_half];
    build_BST_from_array(a, s, s + first_half, root->left);
    build_BST_from_array(a, s + first_half + 1, t, root->right);
}
