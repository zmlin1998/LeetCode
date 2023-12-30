class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        if (n == 1) return s;
        
        n = n - 2;
        s += "1";
        vector<char> v;

        while(n--){
            v.clear();
            char pre = s[0];
            int cnt = 1;
            for(int i = 1; i < s.size(); i++){
                if (s[i] != pre){
                    v.push_back(cnt + '0');
                    v.push_back(pre);
                    cnt = 1;
                    pre = s[i];
                }
                else
                    cnt++;
            } 
            
            v.push_back(cnt + '0');
            v.push_back(pre); 
            
            s.clear();
            for(int i = 0; i < v.size(); i++){
                s += v[i];
            }
        }
        return s;
    }
};