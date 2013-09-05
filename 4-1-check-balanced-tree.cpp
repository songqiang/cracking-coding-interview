/*
 * Song Qiang <qiang.song@usc.edu> 
 *
 */

/*

Implement a function to check if a tree is balanced. For the purposes
of this question, a balanced tree is defined to be a tree such that no
two leaf nodes differ in distance from the root by more than one.

 */

bool
check_balanced_tree(TreeNode* root, size_t &height)
{
    if (root == NULL)
    {
        height = 0;
        return true;
    }

    size_t hl = 0, hr = 0;
    if (check_balanced_tree(root->left, hl)
        && check_balanced_tree(root->right, hr))
    {
        height = max(hl, hr) + 1;
        return true;
    }
    else
        return false;
}

bool
check_balanced_tree(TreeNode* root)
{
    int h;
    return check_balanced_tree(root, h);
}
