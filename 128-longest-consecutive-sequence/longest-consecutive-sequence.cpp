class Solution {
public:
    int longestConsecutive(vector<int>& nums) { 
        if(nums.size() == 0 || nums.size() == 1){
            return nums.size();
        }
        sort(nums.begin(), nums.end());
        int maxi = 1;
        int cnt = 1;
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] == nums[i+1]-1){
                cnt++;
                maxi = max(maxi,cnt);
            } else if(nums[i] == nums[i+1]){
                continue;
            } else if(nums[i] != nums[i+1]-1){
                maxi = max(maxi,cnt);
                cnt = 1;
            } 
        }
        return maxi;
    }
};