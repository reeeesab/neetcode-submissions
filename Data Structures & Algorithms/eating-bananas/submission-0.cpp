class Solution {
public:
    bool canEat(vector<int> &piles, int h, int k){
        int hours = 0;
        for(auto bananas: piles){
            hours+=(bananas+k-1)/k;
        }

        return hours<=h?true:false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int right=0;
        int left=1;
        int ans = 0;
        for(auto p:piles) right = max(right, p);

        while(right>=left){
            int mid = left + (right - left) / 2;
            
            if(canEat(piles, h, mid)){
                ans = mid;
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return ans;
    }
};
