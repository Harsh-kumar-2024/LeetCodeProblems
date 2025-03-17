class Solution {
    private:
        bool isPoss(vector<int>& wei, int days, int currW){
            int shipW = 0;
            int needDay = 0;
            int n = wei.size();
            for(int i = 0; i < n; i ++){
                if(shipW + wei[i] <= currW){
                    shipW += wei[i];
                }else{
                    needDay ++;
                    shipW = 0;
                    shipW += wei[i];
                }
            }
            needDay ++;
            return needDay <= days;
        }
    public:
        int shipWithinDays(vector<int>& weights, int days) {
            int sum = 0;
            int ans = 0;
            for(int x : weights)
                sum += x;
            int max_ele = *max_element(weights.begin(), weights.end());
            int left = max_ele, right = sum;
            while(left <= right){
                int mid = left + (right - left) / 2;
                if(isPoss(weights, days, mid)){
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