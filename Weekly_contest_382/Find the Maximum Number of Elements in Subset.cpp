class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int res = 1;
        
        sort(nums.begin(), nums.end());
        set<int> nums_key;
        map<int, int> m;
        
        for(int i = 0; i < nums.size(); i++){
            nums_key.insert(nums[i]);
            m[nums[i]] += 1;
        }
        
        int cnt;
        long long tmp;
        for(auto &i : nums_key){
            if (i == 1){
                if ((m[i] & 1) == 1){
                    if (m[i] > res) res = m[i];
                }
                else{
                    if (m[i]-1 > res) res = m[i]-1;
                }
                continue;
            }
            cnt = 1;
            tmp = i;
            
            while(1){
                if (tmp * tmp > INT_MAX) break;
                if(m[tmp] >= 2 && m[tmp * tmp] >= 1){
                    cnt = cnt + 2;
                    tmp = tmp * tmp;
                }
                else{
                    break;
                }
            }

            if (cnt > res) res = cnt;
        }
        
        return res;
    }
};