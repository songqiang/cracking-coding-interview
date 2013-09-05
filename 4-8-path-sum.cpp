/*
 * Song Qiang <qiang.song@usc.edu> 
 *
 */

/*

You are given a binary tree in which each node contains a
value. Design an algorithm to print all paths which sum up to that
value. Note that it can be any path in the tree - it does not have to
start at the root.

 */

// assume all positive values
void
print_paths(const size_t s, const TreeNode* root, vector<size_t> &vals)
{
    if (s == root->val) 
    {
        std::copy(vals.begin(), vals.end(), ostream_iterator<size_t>(cout, "\t")); 
        cout << s << endl;
        return;
    }
    else if (s > root->val)
    {
        vals.push_back(root->val);
        if (root->left != NULL) print_paths(s - root->val, root->left, vals);
        if (root->right != NULL) print_paths(s - root->val, root->right, vals);
        vals.erase(vals.end() - 1);
    }
}

void 
print_all_paths(const TreeNode* root, const size_t s)
{
    if (root == NULL) return;
    vector<size_t> vals;
    print_paths(s, root, vals);
    if (root->left != NULL) print_all_paths(root->left, s);
    if (root->right != NULL) print_all_paths(root->right, s);
}



