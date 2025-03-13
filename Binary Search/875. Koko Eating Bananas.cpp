class Solution {
    private:
        long long countHRS(vector<int>& arr, int speed){
            long long cnt = 0;
            for(int x : arr)
                cnt += ceil((double)x / (double)speed );
            return cnt;
        }
    public:
        int minEatingSpeed(vector<int>& piles, int h) {
            int n = piles.size();
            int max_ele = *max_element(piles.begin(), piles.end());
            int left = 1, right = max_ele;
            while(left <= right){
                int mid = left + ( right - left ) / 2;
                long long hrs = countHRS(piles, mid);
                if(hrs <= h){
                    right = mid - 1;
                }
                else
                    left = mid + 1;
            }
            return left;
        }
    };