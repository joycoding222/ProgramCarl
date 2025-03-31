/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        // 虚拟头节点
        ListNode *dummyhead = new ListNode;
        dummyhead->next = head;

        ListNode *curr = dummyhead;
        while (curr->next != nullptr && curr->next->next != nullptr)
        {
            // curr->next == nullptr 链表结点偶数个时的终止条件
            // curr->next->next == nullptr 链表结点奇数个时的终止条件

            // 保存1，3号结点
            ListNode *temp = curr->next;
            ListNode *temp2 = curr->next->next->next;

            // 更改指向
            curr->next = curr->next->next;
            curr->next->next = temp;
            temp->next = temp2;

            // 移动curr指针
            curr = curr->next->next;
        }
        return dummyhead->next;
    }
};