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
    
    void
    insert(ListNode* head, const ListNode* p)
    {
        if (p == NULL) return;

        ListNode* h = head;
        while (h->next != NULL && h->next->val < p->val) h = h->next;
        if (h->next == NULL)
        {
            h->next = p;
            p->next = NULL;
        }
        else if (h->next->val > p->val)
        {
            p->next = h->next;
            h->next = p;
        }
    }

    ListNode*
    remove_duplicates(ListNode* head)
    {
        ListNode* h = new ListNode(numeric_limits<int>::min());
        ListNode* p = head;
        while (p != NULL)
        {
            head = p->next;
            insert(h, p);
            p = head;
        }
    }
};
