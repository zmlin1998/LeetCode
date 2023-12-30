class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        """
        #   1. Find the first decreasing element from the end
        #   2. Find the first element greater than the element found in step 1 from the end
        #   3. Swap the elements found in step 1 and 2
        """

        int n = nums.size();
        int idx = -1;
        
        for (int i = n-2; i >= 0; i--){
            if (nums[i] < nums[i+1]){
                idx = i;
                break;
            }
        }

        if (idx == -1){
            reverse(nums.begin()+idx+1, nums.end());
            return;
        }

        for (int i = n-1; i >= idx; i--){
            if (nums[i] > nums[idx]){
                swap(nums[i], nums[idx]);
                break;
            }
        }

        reverse(nums.begin()+idx+1, nums.end());
        return;
    }
};