#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

class Solution {
public:

    inline void interlaceNodes(ListNode* &n0, ListNode* &n1) {
        ListNode *tmp = n0 -> next;
        n0 -> next = n1;
        n0 = tmp;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *first = list1;
        ListNode *second = list2;
        
        while(first && second) 
        {
            if((first -> val) < (second -> val))
            {
                interlaceNodes(first, second);
            } else {
                interlaceNodes(second, first);
            }
            cout << "First: "<< first <<"\tSecond: " << second << endl;
            
        }

        // need to understand what is pointing what
        // to figure out the first node
        if(!list1 && (list1 -> next == list2))
            return list1;
        else
            return list2;
    }

    void debug(ListNode* head) {
        ListNode *cur = head;

        while(cur != nullptr) 
        {
            cout << "Node:" << cur << "\tval: " << cur -> val << "\tnext:" << cur -> next << "\n";
            cur = cur -> next;   
        }
        cout << "\n\n";

        return;
    }
};



int main() {
    ListNode *e = new ListNode(5);
    ListNode *c = new ListNode(3, e);
    ListNode *a = new ListNode(1, c);

    ListNode *d = new ListNode(4);
    ListNode *b = new ListNode(2, d);

    Solution s = Solution();
    s.debug(a);
    s.debug(b);
    ListNode * res = s.mergeTwoLists(a, b);
    s.debug(res);

    return 0;
};