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
    ListNode* reverseList(ListNode* head) {
        ListNode *old = nullptr;
        ListNode *n0 = head;
        ListNode *n1 = nullptr;
        ListNode *backup = nullptr;
        
        while(n0 != nullptr) 
        {
            if(n1 != nullptr) {
                n1 = backup;
            } else {
                n1 = n0 -> next;
            }
            
            if(n1 != nullptr) {
                backup = n1 -> next;
                n1 -> next = n0;
                n0 -> next = old;
            } else {
                // we store in n2 the new head
                cout << "Found the end" << endl;
                backup = n0;
            }
            old = n0;
            n0 = n1;
        }
        
        return backup;
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
    ListNode *d = new ListNode(4, e);
    ListNode *c = new ListNode(3, d);
    ListNode *b = new ListNode(2, c);
    ListNode *a = new ListNode(1, b);

    Solution s = Solution();
    s.debug(a);
    s.reverseList(a);

    return 0;
};