class Solution {
public:

    vector<int> getRightBOundary(vector<int>& nums){
        vector<int> ans(nums.size(),-1);
        stack<int> st;

        for(int i=nums.size()-1; i>=0; i--){


            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
        
            if(!st.empty()){
                ans[i] = st.top();

            }else{
                ans[i] = nums.size();
            }

            st.push(i);

        }
        return ans;
    }

     vector<int> getLeftBOundary(vector<int>& nums){
        vector<int> ans(nums.size(),-1);
        stack<int> st;

        for(int i=0; i<nums.size(); i++){


            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
        
            if(!st.empty()){
                ans[i] = st.top();
            }

            st.push(i);

        }
        return ans;
    }

    //  vector<int> getPreGreater(vector<int>& nums){

    // }

    int largestRectangleArea(vector<int>& heights) {
        // int n = heights.size();
        // int maxArea = 0;
        // for(int i=0; i<n; i++){
        //     int area = heights[i];
        //     int currIndex = i-1;
        //     while(currIndex>=0 && heights[i]<=heights[currIndex]){
        //         currIndex--;
        //         area += heights[i];
        //     }
        //     currIndex = i+1;
        //     while(currIndex<n && heights[i]<=heights[currIndex]){
        //         currIndex++;
        //         area += heights[i];
        //     }
        //     maxArea = max(area,maxArea);
        // }
        // return maxArea;

        vector<int> left = getLeftBOundary(heights);
        vector<int> right = getRightBOundary(heights);


        int maxArea = 0;
        for(int i=0; i<heights.size(); i++){

            // cout<<"left: "<<left[i]<<" curr:"<<heights[i]<<" right:"<<right[i]<<endl;

            maxArea = max(maxArea, heights[i] * (right[i] - left[i] - 1));
            
        }

        return maxArea;



    }



};