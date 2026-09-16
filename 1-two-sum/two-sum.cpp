class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        unordered_map<int,int>mp;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int sum = target - nums[i];
            if(mp.find(sum) != mp.end()){
                ans.push_back(i);
                ans.push_back(mp[sum]);
                break;
            }
            mp[nums[i]] = i;
        }
        return ans;
    }
};