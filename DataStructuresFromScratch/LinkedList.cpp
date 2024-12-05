#include <iostream>

using namespace std;

class ListNode {
    public:
        int value;
        ListNode* next;
        
        ListNode(int value, ListNode* next) : value(value), next(next) {};
        ListNode(int value) : ListNode(value, nullptr) {};
        
};

class LinkedList {
public:
    ListNode *head;
    ListNode *tail;

    LinkedList() {
        
        head = nullptr;
        tail = nullptr;
    }

    int get(int index) {
        int i = 0;
        ListNode *node = head;

        while(node != nullptr) {
            if( i == index ) {
                return node -> value;
            }
            node = node -> next;
            ++i;
        } 

        return -1;
    }

    void insertHead(int val) {
        
        ListNode *newHead = new ListNode(val);
        if (tail == nullptr && head == nullptr) {
            tail = newHead;
        }
        newHead -> next = head;
        head = newHead;
    }
    
    void insertTail(int val) {
        
        ListNode *newTail = new ListNode(val);
        if(tail != nullptr) {
            tail -> next = newTail;
            if(head == nullptr) {
                head = tail;
            }
        } else {
            tail = newTail;
        }
    }

    bool remove(int index) {
        
        if( index < 0 ) {
            return false;
        }

        int i = 0;
        ListNode *cur = head;
        ListNode *oldCur = nullptr;
        while(cur != nullptr) 
        {
            if(i == index) 
            {
                if(oldCur != nullptr)
                {
                    oldCur -> next = cur -> next;
                } else {
                    head = cur -> next;
                }
                return true;
            }
            oldCur = cur;
            cur = cur -> next;
            ++i;
        }
        return false;
    }

    vector<int> getValues() {
        
        vector<int> *vec = new vector<int>;

        ListNode *cur = head;
        while(cur != nullptr) {
            vec -> push_back(cur -> value);
            cur = cur -> next;
        }
        return *vec;
    }
};
