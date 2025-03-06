class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int n = nums.size();
            int low = 0, high = n - 1;
            while(low <= high){
                int mid = low + (high - low) / 2;
                if(target == nums[mid])
                    return mid;
                
                //check which half is sorted
                
                if(nums[low] <= nums[mid]){
                    
                    //check target is it in left half or not
    
                    if(nums[low] <= target && target < nums[mid])
                        high = mid - 1;
                    else
                        low = mid + 1;
    
                }else{
    
                    //check target is it in right half or not
    
                    if(target > nums[mid] && target <= nums[high])
                        low = mid + 1;
                    else
                        high = mid - 1;
                }
            }
            return -1;
        }
    };