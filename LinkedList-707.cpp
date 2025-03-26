/*
注意在本题目中，设置了一个**不存储数据**的头节点，后续节点的下标从0开始；
*/
class MyLinkedList {
    public:
        struct LinkedNode{
            int val;
            LinkedNode *next;
            LinkedNode(){};
            LinkedNode(int val):val(val), next(nullptr){};
        };
    
        LinkedNode *head;
        int size;
    
        MyLinkedList() {
            head = new LinkedNode(0);
            size = 0;
        }
        
        int get(int index) {
            if (index < 0 || index > (size - 1))
                return -1;
            // 注意该函数实现的是获取下标为index的元素，因此查找节点从存储了数据的第一个节点开始（下标0）
            LinkedNode *curr = head->next;
            while (index--)
            {
                curr = curr->next;
            }
            return curr->val;
        }
        
        void addAtHead(int val) {
            LinkedNode *newnode = new LinkedNode();
            newnode->next = head->next;
            newnode->val = val;
            head->next = newnode;
            ++size;
        }
        
        void addAtTail(int val) {
            LinkedNode *tail = head;
            while (tail->next != nullptr)   // 找到尾节点
            {
                tail = tail->next;
            }
            LinkedNode *newnode = new LinkedNode();
            tail->next = newnode;
            newnode->next = nullptr;
            newnode->val = val;
            ++size;
        }
        
        void addAtIndex(int index, int val) {
            if (index > size) return;   // 插入的位置大于单链表长度
            if (index < 0) index = 0;   // 插入的位置为链表第一个元素（下标0）
            // LinkedNode *p = head->next;
            // for (int i = 0; i < index - 1; ++i)
            // {
            //     p = p->next;
            // }
            /*
            该函数在指定位置index插入新的节点，因此需要找到插入位置的前置节点(index-1)，
            所以查找结点从头节点开始
            */
            LinkedNode *p = head;
            while (index--)
            {
                p = p->next;
            }
            LinkedNode *newnode = new LinkedNode();
            newnode->val = val;
            newnode->next = p->next;
            p->next = newnode;
            ++size;
        }
        
        void deleteAtIndex(int index) {
            if (index >= size || index < 0) return; // 下标不存在直接返回
            // LinkedNode *p = head->next;
            // for (int i = 0; i < index - 1; ++i)
            // {
            //     p = p->next;
            // }
            LinkedNode *p = head;
            while (index--)
            {
                p = p->next;
            }
            LinkedNode *temp = p->next;
            p->next = temp->next;
            delete temp;
            // 安全起见
            temp = nullptr;
            --size;
        }
    };
    
    /**
     * Your MyLinkedList object will be instantiated and called as such:
     * MyLinkedList* obj = new MyLinkedList();
     * int param_1 = obj->get(index);
     * obj->addAtHead(val);
     * obj->addAtTail(val);
     * obj->addAtIndex(index,val);
     * obj->deleteAtIndex(index);
     */