#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        auto newCapacity = nums.capacity();
        vector<int> ans = vector<int>(newCapacity * 2);
        for(size_t i = 0; i < ans.capacity();)  
        {
            for (size_t j = 0; j < nums.capacity(); j++)
            {
                ans[i] = nums[j];
                ++i;
            }
            
        }
        return ans;
    }
};