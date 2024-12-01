#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        auto oldSize = nums.size();
        vector<int> ans = vector<int>(oldSize * 2);
        size_t j = oldSize; // starting j in the middle
        for (size_t i = 0; i < nums.size(); ++i) {
            ans[i] = nums[i];
            ans[j] = nums[i];
            ++j;
        }
        return ans;
    }
};