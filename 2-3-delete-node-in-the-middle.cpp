/*
 * Song Qiang <qiang.song@usc.edu> 
 *
 */

/*

Write code to remove duplicates from an unsorted linked list.

FOLLOW UP

How would you solve this problem if a temporary buffer is not allowed?

 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
public:
    ListNode*
    del_node(const ListNode* node)
    {
        assert(node->next != NULL);
        ListNode* p = node->next;
        std::iter_swap(node, p);
        delete p;
    }
};
