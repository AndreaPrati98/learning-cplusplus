#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
void test1(ListNode* &, ListNode* &);

class Solution {
public:

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode starting = ListNode();
        ListNode *cur = &starting;

        ListNode* i = list1;
        ListNode* j = list2;

        while(i && j)
        {
            if(i -> val < j -> val)
            {
                cur -> next = i;
                i = i -> next;
            } 
            else 
            {
                cur -> next = j;
                j = j -> next;
            }
            cur = cur -> next;
        }

        if(i)
            cur -> next = i;
        else 
            cur -> next = j;
        
        return starting.next;
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
    ListNode *list1;
    ListNode *list2;

    test1(list1, list2);

    Solution s = Solution();
    s.debug(list1);
    s.debug(list2);
    ListNode * res = s.mergeTwoLists(list1, list2);
    s.debug(res);

    return 0;
}

void test1(ListNode* &list1, ListNode* &list2) {
    ListNode *e = new ListNode(4);
    ListNode *c = new ListNode(2, e);
    list1 = new ListNode(1, c);
    

    ListNode *f = new ListNode(4);
    ListNode *d = new ListNode(3, f);
    list2 = new ListNode(1, d);
}