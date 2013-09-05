/*
 * Song Qiang <qiang.song@usc.edu> 
 *
 */

/*

Design an algorithm and write code to find the first common ancestor
of two nodes in a binary tree. Avoid storing additional nodes in a
data structure. NOTE: This is not necessarily a binary search tree.

 */

TreeNode*
get_first_common_ancester(const TreeNode* root,
                          const TreeNode* p1,
                          const TreeNode* p2,
                          size_t &counts)
{
    if (root == NULL) return NULL;
    TreeNode* p = get_first_common_ancester(root->left, p1, p2, counts);
    if (p != NULL) return p;
    p = get_first_common_ancester(root->right, p1, p2, counts);
    if (p != NULL) return p;
    if (root == p1 || root == p2) ++counts;
    return counts == 2 && root != p1 && root != p2 ? root : NULL;
}

TreeNode*
get_first_common_ancester(const TreeNode* root,
                          const TreeNode* p1,
                          const TreeNode* p2)
{
    size_t c;
    return get_first_common_ancester(root, p1, p2, c);
}

