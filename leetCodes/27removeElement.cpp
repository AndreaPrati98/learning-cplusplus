#include <iostream>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(val > 50) {
            // while 0 <= nums[i] <= 50
            // 0 <= val <= 100
            return nums.size();
        }

        int k = 0, r = 0;
        while ( r < nums.size() ) 
        {
            if ( nums[r] != val ) {
                swap(nums[k], nums[r]);
                ++k;
            }
            ++r;
        }
        return k;
    }
};

