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
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *p1 = head; // fast
        ListNode *p2 = head; // slow

        while (p1 != NULL && p1->next != NULL)
        {
            p1 = p1->next->next;
            p2 = p2->next;

            if (p1 == p2) // 快慢指针相遇说明链表存在环
            {
                ListNode *curr1 = p1;   // 快慢指针相遇的位置
                ListNode *curr2 = head; // 头指针位置

                // 从头指针到环入口的距离=curr1到环入口的距离+(n-1)*环的长度，因此curr1和curr2一定相遇
                while (curr1 != curr2)
                {
                    curr1 = curr1->next;
                    curr2 = curr2->next;
                }

                return curr1; // 环的入口
            }
        }
        return NULL; // 无环
    }
};