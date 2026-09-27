class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int leftBar = 0;
        int rightBar = n-1; 
        int maxArea = 0; 
        while(rightBar>leftBar){
            int width = rightBar - leftBar;
            int height = min(heights[rightBar], heights[leftBar]);
            int currArea = width * height;
            maxArea = max(maxArea, currArea);
            if(heights[rightBar]<heights[leftBar]){
                rightBar--;
            }else{
                leftBar++;
            }
        }
        return maxArea;      
    }
};
