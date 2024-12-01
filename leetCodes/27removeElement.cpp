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

        int k = 0, r = nums.size() - 1;
        while (k < nums.size() && r != k) 
        {
            
            if(nums[k] == val) 
            {
                // swapping procedure
                while (nums[r] == val && r > k)
                {
                    // looking in the right pointer an elem
                    // different than val
                    --r;
                }
                    
                // found element different than val
                // and it is not already taken into
                // account by k
                
                int tmp = nums[r];
                nums[r] = nums[k];
                nums[k] = tmp;
                --r;

            }

            if(nums[k] != val) 
            {
                // it may be incremented if we find a nums[k] != val
                // or if we find that nums[r] != val and r != k;
                ++k;
            }   

        } 
        return k;
    }
};