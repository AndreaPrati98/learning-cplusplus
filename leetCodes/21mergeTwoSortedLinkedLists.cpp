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
            cout << "First: "<< first << " val: " << first -> val <<"\tSecond: " << second << " val: " << second -> val << endl;
            if((first -> val) < (second -> val))
            {
                interlaceNodes(first, second);
            } 
            else 
            {
                bool equalValues = first -> val == second -> val;
                bool noNullptrs = first -> next != nullptr && second -> next != nullptr;

                if (equalValues && noNullptrs)
                {
                    cout << "here" << endl;
                    if((first -> next -> val) <= (second -> next -> val)) {
                        interlaceNodes(first, second);
                    } else {
                        interlaceNodes(second, first);
                    }
                } else {
                    cout << "Now here" << endl;
                    interlaceNodes(second, first);
                }
            }   
        }

        // need to understand what is pointing what
        // to figure out the first node
        if((list1 != nullptr) && (list1 -> next == list2))
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