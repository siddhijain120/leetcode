class Solution {
public:
    int minOperations(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        vector<int>spf(maxi+1);
        for(int i = 0; i <= maxi; i++) spf[i] = i;
        for(int i = 2; i*i <= maxi; i++){
            if(spf[i] == i){
                for(int j = i*i; j <= maxi; j+=i){
                    if(spf[j] == j){
                        spf[j] = i;
                    }
                }
            }
        }

        int ans = 0;
        for(int i = nums.size()-2; i >= 0; i--){
            if(nums[i] > nums[i+1]){
                nums[i] = spf[nums[i]];
                ans++;
                if(nums[i] > nums[i+1]){
                    return -1;
                }
            }
        }
        return ans;
    }
};