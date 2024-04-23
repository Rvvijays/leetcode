class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        // sort(nums.begin(),nums.end());

        // return nums[nums.size()-k];


        priority_queue<int> pq;

        for(int i=0; i<nums.size(); i++){
            pq.push(nums[i]);
        }

        int maxi = 0;

        while(k--){
            maxi = pq.top();
            pq.pop();
            // cout<<"top: "<<maxi<<endl;
        }

        return maxi;

        
    }
};