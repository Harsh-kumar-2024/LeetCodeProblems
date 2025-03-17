class Solution {
    public:
        bool isLess(vector<int>& nums, int threshold, int divi){
            int sum = 0;
    
            for(int x : nums){
                sum += ceil((float)x / divi);
            }
            return sum <= threshold;
        }
        int smallestDivisor(vector<int>& nums, int threshold) {
            int max_ele = *max_element(nums.begin(), nums.end());
            int ans = 0;
            int left = 1, right = max_ele;
            while(left <= right){
                int mid = left + (right - left) / 2;
                if(isLess(nums, threshold, mid)){
                    ans = mid;
                    right = mid - 1;
                }
                else{
                    left = mid + 1;
                }
            }
            return ans;
        }
    };