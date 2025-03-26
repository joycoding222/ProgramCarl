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

// **My Solution: hard copy**
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *newlist = new ListNode();
        while (head != nullptr)
        {
            // 注意这里是**hard copy**
            ListNode *curr = new ListNode();
            curr->val = head->val;
            curr->next = head->next;
            // 头插法
            curr->next = newlist->next;
            newlist->next = curr;

            head = head->next;
        }
        return newlist->next;
    }
};

// 双指针法
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while (curr != nullptr)
        {
            ListNode *temp = curr->next;
            curr->next = prev;

            prev = curr;
            curr = temp;
        }

        return prev;
    }
};