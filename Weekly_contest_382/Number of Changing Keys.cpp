class Solution {
public:
    int countKeyChanges(string s) {
        int res = 0;
        char pre_c = s[0];
        
        for(int i = 1; i < s.size(); i++){
            if (toupper(s[i]) == toupper(pre_c))
                continue;
            else{
                pre_c = s[i];
                res++;
            }
        }
        return res;
    }
};