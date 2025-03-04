class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            int maxPre = INT_MIN, maxSuf = INT_MIN, currPre = 1, currSuf = 1;
            int n = nums.size();
            for (int i = 0; i < n; i ++){
                currPre *= nums[i];
                currSuf *= nums[n - i - 1];
                maxPre = max(maxPre, currPre);
                maxSuf = max(maxSuf, currSuf);
                if(currPre == 0)
                    currPre = 1;
                if(currSuf == 0)
                    currSuf = 1;
            }
            return max(maxPre, maxSuf);
        }
    };