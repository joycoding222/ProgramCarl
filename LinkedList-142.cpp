/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    public:
        ListNode *detectCycle(ListNode *head) {
            ListNode *p1 = head;    // fast
            ListNode *p2 = head;    // slow
    
            while (p1 != NULL && p1->next != NULL && p1->next->next != NULL)
            {
                p1 = p1->next->next;
                p2 = p2->next;
    
                if (p1 == p2)
                {
                    ListNode *curr1 = p1;
                    ListNode *curr2 = head;
    
                    while (curr1 != curr2)
                    {
                        curr1 = curr1->next;
                        curr2 = curr2->next;
                    }
    
                    return curr1;
                }
            }
            return NULL;
        }
    };