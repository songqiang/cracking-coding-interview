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
    detect_circular_node(const ListNode* head)
    {
        std::unordered_set<ListNode*> visited;

        ListNode* p = head;
        while (p != NULL)
        {
            if (visited.find(p) != visited.end()) return p;
            visited.insert(p);
            p = p->next;
        }

        return NULL;
    }
};
