class Solution {
    public:
        bool makeBouquets(vector<int>& bloomD, int m, int k, int currD){
            int bouquets = 0;
            int n = bloomD.size();
            int adjC = 0;
            for(int i = 0; i < n; i ++){
                // flower bloom
                if(bloomD[i] <= currD){
                    adjC ++;
                }
                // flower not bloom
                else{
                    adjC = 0;
                }
                // k adjacent fount bouquet ++
                if(adjC == k){
                    bouquets ++;
                    adjC = 0;
                }
            }
            if(bouquets >= m)
                return 1;
            else
                return 0;
        }
        int minDays(vector<int>& bloomDay, int m, int k) {
            int n = bloomDay.size();
            if(n < (long) m * k)
                return -1;
    
            int maxEle = *max_element(bloomDay.begin(), bloomDay.end());
            int minEle = *min_element(bloomDay.begin(), bloomDay.end());
            int left = minEle, right = maxEle;
            while(left <= right){
                int mid = left + ( right - left ) / 2;
                if(makeBouquets(bloomDay, m , k, mid))
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            return left;
        }
    };