class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //so we use hashmap to solve this
        //we chech from a prefix sum whether we can get k if we subtract any
        //before prefix 
        //Ex: if curr prefix is 9 and k is 3, we have to check
        //rem = 9-3 = 6 -> if it exists then subtract the both indices and store in maxi
        // the above is for MAXIMUM SUBARRAY SIZE

        int cnt = 0, sum = 0;
        unordered_map<int,int>mp;
        mp[0] = 1;

        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            int rem = sum-k;
            if(mp.find(rem) != mp.end()){
                cnt += mp[rem];
            }
            mp[sum]++;
        }
        return cnt;
    }
};