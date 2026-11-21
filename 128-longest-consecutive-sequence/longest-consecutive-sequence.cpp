class Solution {
public:
    int longestConsecutive(vector<int>& nums) { 
        if(nums.size() == 0 || nums.size() == 1){
            return nums.size();
        }
        int maxi = 0;
        unordered_set<int>st(nums.begin(), nums.end());
        for(int num : st){
            if(st.find(num-1) == st.end()){
                int cnt = 1;
                int curr = num;

                while(st.find(curr+1) != st.end()){
                    cnt++;
                    curr++;
                }
                maxi = max(maxi, cnt);
            }
        }
        return maxi;
    }
};