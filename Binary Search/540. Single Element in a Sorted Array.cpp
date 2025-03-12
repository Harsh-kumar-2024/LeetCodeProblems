class Solution {
    public:
        int singleNonDuplicate(vector<int>& nums) {
            int n = nums.size();
            if(n == 1)
                return nums[0];
            if(nums[0] != nums[1])
                return nums[0];
            if(nums[n - 2] != nums[n - 1])
                return nums[n - 1];
            int low = 0, high = n - 1;
            int ans = -1;
            while(low <= high){
                int mid = low + ( high - low ) / 2;
                if(nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]){
                    ans = nums[mid];
                    break;
                }
                else if(mid % 2 == 0){
                    if(nums[mid - 1] == nums[mid]){
                        high = mid - 1;
                    }
                    else {
                        low = mid + 1;
                    }
                }
                else {
                    if(nums[mid - 1] == nums[mid]){
                        low = mid + 1;
                        
                    }
                    else {
                        high = mid - 1;
                    }
                }
            }
            return ans;
        }
    };