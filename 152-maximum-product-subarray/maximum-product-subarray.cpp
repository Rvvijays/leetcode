class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int n = nums.size();

        int maxProd = nums[0];
        for(int i =0; i<n; i++) {
                int prod = 1;
            for(int j = i; j<n; j++) {
                prod *= nums[j];

                maxProd = max(maxProd,prod);

                // cout<<"prod: "<<prod<<endl;
            }
        }

        return maxProd;
        
        
    }
};