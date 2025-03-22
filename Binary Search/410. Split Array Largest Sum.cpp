class Solution {
    public:
            int isPoss(vector<int>& arr, int subarr){
                int subsum = 0, subcnt = 1;
                for(int i : arr){
                    if(i + subsum <= subarr){
                        subsum += i;
                    }else{
                        subcnt ++;
                        subsum = i;
                    }
                }
                return subcnt;
            }
        int splitArray(vector<int>& nums, int k) {
            int n = nums.size();
            int maxx = *max_element(nums.begin(), nums.end());
            int summ = accumulate(nums.begin(), nums.end(), 0);
            int low = maxx, high = summ;
            while(low <= high){
                int mid = low + ( high - low ) / 2;
                if(isPoss(nums, mid) > k){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }     
            return low;
        }
    };