class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            int n = nums.size();
            vector<int> pos(2, -1);
            int low = 0, high = n - 1;
            while(low <= high){
                int mid = low + (high - low ) / 2;
                if(target == nums[mid]){
                    pos[1] = mid;
                    low = mid + 1;
                }else if(target > nums[mid])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
    
            low = 0, high = n - 1;
            while(low <= high){
                int mid = low + (high - low ) / 2;
                if(target == nums[mid]){
                    pos[0] = mid;
                    high = mid - 1;
                }else if(target > nums[mid])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
            return pos;
        }
    };