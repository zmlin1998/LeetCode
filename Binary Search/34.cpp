class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0; 
        int r = nums.size() - 1;
        int n = nums.size();
        int m;
        
        int n1 = -1;
        int n2 = -1;
        int ans_in = 0;

        """
        #   1. Find the element using binary search
        #   2. If element is not found, return [-1, -1]
        #   3. If element is found, find the first and last occurence of the element using binary search
        """
        
        while(l <= r){
            m = (l + r) / 2;
            if (nums[m] == target){
                ans_in = 1;
                n1 = m;
                n2 = m;
                break;
            }
            else if (nums[m] > target)
                r = m - 1;
            else 
                l = m + 1;
        }

        vector<int> ans;
        if (ans_in == 0){
            ans.push_back(n1);
            ans.push_back(n2);
            return ans;
        }

        int tmp = m;
        int mid;

        while(l <= m){
            mid = (l + m) / 2;
            
            if (nums[mid] == target){
                if (mid == 0){
                    n1 = 0;
                    break;
                }
                else if (nums[mid-1] != target){
                    n1 = mid;
                    break;
                }
                m = mid - 1; 
            }
            else if (nums[mid] < target)
                l = mid + 1;
            else
                m = mid - 1;
        }

        m = tmp;

        while(m <= r){
            mid = (m + r) / 2;
            if (nums[mid] == target){
                if (mid == n-1){
                    n2 = n - 1;
                    break;
                }
                else if (nums[mid+1] != target){
                        n2 = mid;
                        break;
                    }
                m = mid + 1; 
            }
            else if (nums[mid] > target)
                r = mid - 1;
            else
                m = mid + 1;
        }

        ans.push_back(n1);
        ans.push_back(n2);
        return ans;
    }
};