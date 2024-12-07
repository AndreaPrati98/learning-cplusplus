#include <iostream>

using namespace std;

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
        head = nullptr;
        tail = nullptr;
    }
    
    int get(int index) {
        MyList::ListNode *cur = head;
        int i = 0;
        while(cur)
        {
            if(i == index)
                return cur -> val;
            ++i;
            cur = cur -> next;
        }

        return -1;
    }
    
    void addAtHead(int val) {
        
        // checking if head or tail are null but not at the same time
        // if one is null and the other is not, then we have a problem...
        bool xorHeadTailNullCheck = (!head || !tail) && !(!head && !tail);
        if(xorHeadTailNullCheck){
            cerr << "Disastrous!!! We made a mess :q" << endl;
            return;
        }

        if(head == nullptr) {
            // if we are here we are sure also tail is null
            head = new MyList::ListNode(val, nullptr, head);
            tail = head;
            return;
        }

        head -> prev = new MyList::ListNode(val, nullptr, head);
        head = head -> prev;

    }
    
    void addAtTail(int val) {
        // checking if head or tail are null but not at the same time
        // if one is null and the other is not, then we have a problem...
        bool xorHeadTailNullCheck = (!head || !tail) && !(!head && !tail);
        if(xorHeadTailNullCheck){
            cerr << "Disastrous!!! We made a mess :q" << endl;
            return;
        }

        if(head == nullptr) {
            // if we are here we are sure also tail is null
            head = new MyList::ListNode(val, nullptr, head);
            tail = head;
            return;
        }

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
                } else {
                    // cur is the head, need to update
                    head = cur;
                }
                cur -> prev = newNode;
                return;
            }
            ++i;
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
                if(cur -> prev) {
                    cur -> prev -> next = cur -> next;
                } else {
                    // cur is the head, need to update
                    head = cur -> next;
                }
                if(cur -> next){
                    cur -> next -> prev = cur -> prev;
                } else {
                    // cur is the tail, need to update
                    tail = cur -> prev;
                }

                return;
            }
            ++i;
            cur = cur -> next; 
        }
    }

    void debug()
    {
        MyList::ListNode *cur = head;
        
        while(cur)
        {
            cout << "Val: " << cur -> val << endl;
            cur = cur -> next;
        }
        cout << endl << endl;
    }
};

void test1();
void test2();

int main() {
    
    cout << "_____Test1_____" << endl;
    test1();
    cout << "_____Test2_____" << endl;
    test2();

    return 0;
}

void test2() {
    MyLinkedList lnkList = MyLinkedList();

    lnkList.addAtHead(1);
    lnkList.debug();
    lnkList.addAtTail(3);
    lnkList.debug();
    lnkList.addAtIndex(1,2);
    lnkList.debug();
    lnkList.get(1);
    lnkList.debug();
    lnkList.deleteAtIndex(1);
    lnkList.debug();
    lnkList.get(1);
    lnkList.debug();
}
void test1() {
    MyLinkedList l = MyLinkedList();
    
    // ["MyLinkedList","addAtHead","addAtHead","addAtHead","addAtIndex","deleteAtIndex","addAtHead","addAtTail","get","addAtHead","addAtIndex","addAtHead"]
    // [[],[7],[2],[1],[3,0],[2],[6],[4],[4],[4],[5,0],[6]]
    l.addAtHead(7);
    l.addAtHead(2);
    l.addAtHead(1);
    l.debug();
    l.addAtIndex(3,0);
    l.debug();
    l.deleteAtIndex(2);
    l.debug();
    l.addAtHead(6);
    l.debug();
    l.addAtTail(4);
    l.get(4);
    l.addAtHead(4);
    l.addAtIndex(5,0);
    l.addAtHead(6);

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