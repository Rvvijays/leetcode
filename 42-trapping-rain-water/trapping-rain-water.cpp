class Solution {
public:
    int trap(vector<int>& height) {

        int low = 0;
        int high = height.size()-1;

        int leftMax = 0;
        int rightMax = 0;
        int ans = 0;

        while(low <= high){

            if(height[low] <= height[high]){

                if(leftMax >= height[low]){
                    ans += leftMax - height[low];
                }else{
                    leftMax = height[low];
                }
                low++;

            }else{
                if(rightMax >= height[high]){
                    ans += rightMax - height[high];
                }else{
                    rightMax = height[high];
                }

                high--;
            }

        }

        return ans;
        
    }
};