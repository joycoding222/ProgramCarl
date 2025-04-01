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
class Solution {
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            // 虚拟头节点
            ListNode *dummyhead = new ListNode();
            dummyhead->next = head;
            
            // 快慢指针
            ListNode *fast = dummyhead;
            ListNode *slow = dummyhead;
    
            // 快指针先走n步
            while (n-- && fast != nullptr)
            {
                fast = fast->next;
            }
            
            // slow 指向要删除结点的前一个
            while (fast->next != nullptr)
            {
                fast = fast->next;
                slow = slow->next;
            }   // 此时slow下一个节点为要删除的节点
    
            // 删除结点并释放内存
            ListNode *del = slow->next;
            slow->next = del->next;
            delete del;
            
            // 返回真正的头节点
            ListNode *result = dummyhead->next;
            delete dummyhead;
            return result;
        }
    };