class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int j=0;
        vector<int> ans;
        for(int i=0; i<arr.size(); i++){
            if(i-j+1>k){
                int ith = abs(arr[i]-x);
                int jth = abs(arr[j]-x);

                 if (ith < jth)
                    j++;
            }
        }

        for(int l = j; l<j+k; l++)
            ans.push_back(arr[l]);


        return ans;
    }
};