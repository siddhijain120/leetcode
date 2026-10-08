class Solution {
public:
    string removeOuterParentheses(string s) {
        int o = 0, c = 0;
        int j = 0;
        string ans = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') o ++;
            else c++;
            if(o == c){
                ans += s.substr(j+1, i-j-1);
                cout << j << " " << i << endl;
                o = 0;
                c = 0;
                j = i+1;
            }
        }
        return ans;
    }
};