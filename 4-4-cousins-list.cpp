/*
 * Song Qiang <qiang.song@usc.edu> 
 *
 */

/*

Given a binary search tree, design an algorithm which creates a linked
list of all the nodes at each depth (i.e., if you have a tree with
depth D, you’ll have D linked lists).

 */

void
build_list_of_level_nodes(BSTNode* root, vector<ListNode*> &lists)
{
    if (root == NULL) return;
    
    vector<BSTNode*> v1, v2;
    v1.push_back(root);

    while (!v1.empty())
    {
        ListNode* p = NULL;
        for (size_t i = 0; i < v1.size(); ++i)
        {
            if (p == NULL)
            {
                lists.push_back(new ListNode(v1[i]->val));
                p = lists.back();
                p->next = NULL;
            }
            else
            {
                p->next = new ListNode(v1[i]->val);
                p = p->next;
                p->next = NULL;
            }
            
            if (v1[i]->left != NULL)
                v2.push_back(v1[i]->left);
            if (v1[i]->right != NULL)
                v2.push_back(v1[i]->right);
        }
        swap(v1, v2);
        v2.clear();
    }
}
