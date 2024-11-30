#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // starting from 1 and 2 because the first element of course we want it 
        // and starting from 0 and 1 we would lose it.
        int i = 1, j = 2, d = 0;

        for (; j < nums.size(); ++j)
        {
            if( nums[i+d] != nums[j] ) {
                nums[i] = nums[j];
                ++i;
                d = j - i;
            }
        }
        return i;
    }
};