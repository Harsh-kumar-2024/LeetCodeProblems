class Solution {
    public:
        int findKthPositive(vector<int>& arr, int k) {
            int n = arr.size();
            int left = 0, right = n - 1;
            while(left <= right){
                int mid = left + ( right - left ) / 2;
                int missNum = arr[mid] - (mid + 1);
                if(missNum < k)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            return left + k;
        }
    };