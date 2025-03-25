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
    ListNode *removeElements(ListNode *head, int val)
    {
        /*
        方法一：
        头节点存储数据，则分别处理删除头节点和删除非头节点的情况；
        */
        // 删除头节点
        while (head != nullptr && head->val == val) // 注意第二个判断相等的条件不能写在循环里面
        {
            ListNode *tmp = head;
            head = head->next;
            delete tmp;
        }

        ListNode *curr = head;
        // 删除非头节点, curr->next 是要删除的节点
        while (curr != nullptr && curr->next != nullptr) // 注意顺序
        {
            if (curr->next->val == val)
            {
                ListNode *delNode;
                delNode = curr->next; // 保存要删除的节点信息
                curr->next = delNode->next;
                delete delNode;
            }
            else
            {
                curr = curr->next;
            }
        }
        return head;

        /*
        方法二：BETTER!
        设置一个不存储数据的虚拟头节点，使得删除节点的操作统一；
        */
        ListNode *_head = new ListNode(0);  // 虚拟头节点
        _head->next = head;

        ListNode *temp = _head;
        while (temp->next != nullptr)
        {
            if (temp->next->val == val)
            {
                ListNode *delnode = temp->next;
                temp->next = delnode->next;
                delete delnode;
            }
            else
            {
                temp = temp->next;
            }
        }

        head = _head->next; // 记得返回的是实际的头节点
        delete _head;
        return head;
    }
};