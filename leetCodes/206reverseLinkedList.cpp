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
        ListNode *prev = nullptr;
        ListNode *curr = head;

        while(curr) {
            ListNode* tmp = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = tmp; 
        }
        debug(prev);
        return prev;
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