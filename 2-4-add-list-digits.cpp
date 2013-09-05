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
    add(const ListNode* pa, const ListNode* pb)
    {
        int inc = 0;
        ListNode* head = new ListNode(0);

        ListNode* p = head;

        while (pa != NULL && pb != NULL)
        {
            int s = inc + pa->val + pb->val;
            inc = s / 10;
            s = s % 10;
            p->next = new ListNode(s);
            p = p->next;
        }

        while (pa != NULL)
        {
            int s = inc + pa->val;
            inc = s / 10;
            s = s % 10;
            p->next = new ListNode(s);
            p = p->next;
        }

        while (pb != NULL)
        {
            int s = inc + pb->val;
            inc = s / 10;
            s = s % 10;
            p->next = new ListNode(s);
            p = p->next;
        }

        p = head;
        head = head->next;
        delete p;

        return head;
    }
};
