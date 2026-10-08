class Solution {
public:
    int threeDigitNo(int pos, vector<int>& used, vector<int>& digits) {

        // base case
        if(pos == 3){
            return 1;
        }
        vector<int>seen(10,0);
        int ans = 0;
        for(int i = 0; i < digits.size(); i++){
            if(used[i]){
                continue;
            }
            if(seen[digits[i]]){
                continue;
            }
            if(pos == 0 && digits[i] == 0){
                continue;
            } else if( pos == 2 && (digits[i] % 2 != 0)){
                continue;
            }
            used[i] = 1;
            seen[digits[i]] = 1;
            ans += threeDigitNo(pos+1,used,digits);
            used[i] = 0;
        }
        return ans;
    }
    int totalNumbers(vector<int>& digits) {
        vector<int>used(digits.size(),0);
        int ans = threeDigitNo(0,used,digits);
        return ans;
    }
};