/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *p1 = headA;
        ListNode *p2 = headB;

        int count1 = 0, count2 = 0;

        while (p1 != nullptr)
        {
            p1 = p1->next;
            ++count1;
        }
        while (p2 != nullptr)
        {
            p2 = p2->next;
            ++count2;
        }

        // 关键一步
        p1 = headA;
        p2 = headB;

        int delta = 0;

        if (count1 > count2)
        {
            delta = count1 - count2;
            while (delta--)
            {
                p1 = p1->next;
            }
        }
        else if (count1 < count2)
        {
            delta = count2 - count1;
            while (delta--)
            {
                p2 = p2->next;
            }
        }

        while (p1 != p2)
        {
            p1 = p1->next;
            p2 = p2->next;
        }

        return p1;
    }
};