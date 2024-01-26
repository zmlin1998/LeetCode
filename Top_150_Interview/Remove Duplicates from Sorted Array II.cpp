class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 0;
        int r = 0;
        int past_num = nums[0];
        int curr_num = nums[0];
        int cnt = 0;

        while(r < nums.size()){
            curr_num = nums[r];
            r++;
            if (past_num == curr_num){
                cnt++;
                if (cnt > 2){
                    continue;
                }
                else{
                    nums[l++] = past_num;
                }
            }
            else{
                cnt = 1;
                nums[l++] = curr_num;
                past_num = curr_num;
            }
        }
        return l;
    }
};