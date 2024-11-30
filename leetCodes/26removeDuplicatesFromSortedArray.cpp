#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 1, j = 1;

        while(j < nums.size()) {
            if( nums[j - 1] != nums[j] ) {
                nums[i] = nums[j];
                ++i;
            }
            ++j;
        }
        
        return i;
    }
};