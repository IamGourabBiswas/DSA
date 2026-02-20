class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;

        for(int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            // check if complement exists
            if(mp.find(complement) != mp.end()) {
                return {mp[complement], i};
            }

            // store current number and index
            mp[nums[i]] = i;
        }

        return {}; // never reached (given exactly one solution)
    }
};