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
    nth_element(const ListNode* head, const size_t n)
    {
        p1 = head;
        for (size_t i = 0; i < n; ++i)
        {
            assert(p1 != NULL);
            p1 = p1->next;
        }

        p2 = head;
        while (p1 != NULL)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p2;
    }
};
