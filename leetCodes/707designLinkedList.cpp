namespace MyList {
    struct ListNode {
        int val;
        ListNode *next;
        ListNode *prev;

        ListNode() : ListNode(0, nullptr, nullptr) {}
        ListNode(int x, ListNode *prevNode, ListNode *nextNode)
            : val(x), prev(prevNode), next(nextNode) {}
    };
}

class MyLinkedList {
private:
    MyList::ListNode *head;
    MyList::ListNode *tail;

public:

    MyLinkedList() {
        // Init the list with a 'dummy' node which makes 
        // removing a node from the beginning of list easier.
        head = new MyList::ListNode();
        tail = head;
    }
    
    int get(int index) {
        MyList::ListNode *cur = head;
        int i = 0;
        while(cur)
        {
            if(i == index)
                return cur -> val;
            
            cur = cur -> next;
        }

        return -1;
    }
    
    void addAtHead(int val) {
        head -> prev = new MyList::ListNode(val, nullptr, head);
        head = head -> prev;
    }
    
    void addAtTail(int val) {
        tail -> next = new MyList::ListNode(val, tail, nullptr);
        tail = tail -> next;
    }
    
    void addAtIndex(int index, int val) {
        MyList::ListNode *cur = head;
        int i = 0;
        while(cur)
        {
            if(i == index)
            {
                MyList::ListNode *newNode = new MyList::ListNode(val, cur -> prev, cur);
                if(cur -> prev) 
                {
                    // remember to update the next pointer of the previous
                    // element of cur
                    cur -> prev -> next = newNode;
                }
                cur -> prev = newNode;
                return;
            }
            cur = cur -> next;
        }
    }
    
    void deleteAtIndex(int index) {
        MyList::ListNode *cur = head;
        int i = 0;
        while(cur)
        {
            if(i == index)
            {
                if(cur -> prev)
                    cur -> prev -> next = cur -> next;
                if(cur -> next)
                    cur -> next -> prev = cur -> prev;

                return;
            }
            cur = cur -> next; 
        }
    }
};

int main() {
    MyLinkedList lnkList = MyLinkedList();

    lnkList.addAtHead(1);
    lnkList.addAtTail(3);
    lnkList.addAtIndex(1,2);
    lnkList.get(1);
    lnkList.deleteAtIndex(1);
    lnkList.get(1);

    return 0;
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */