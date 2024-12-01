#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        auto newCapacity = nums.size();
        vector<int> ans = vector<int>(newCapacity * 2);
        for(size_t i = 0; i < ans.size();)  
        {
            for (size_t j = 0; j < nums.size(); j++)
            {
                ans[i] = nums[j];
                ++i;
            }
            
        }
        return ans;
    }
};