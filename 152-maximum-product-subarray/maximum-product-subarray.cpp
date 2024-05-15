class Solution {
public:
    int brute(vector<int>& nums) {
        int n = nums.size();

        int maxProd = nums[0];
        for (int i = 0; i < n; i++) {
            int prod = 1;
            for (int j = i; j < n; j++) {
                prod *= nums[j];

                maxProd = max(maxProd, prod);

                // cout<<"prod: "<<prod<<endl;
            }
        }

        return maxProd;
    }



    int maxProduct(vector<int>& nums) {

        int n = nums.size();

        

        // int suffix = 1;
        // int prefix = 1;

        // int maxProd = nums[0];
        // for(int i=0; i<n; i++) {

        //     if(prefix == 0) {
        //         prefix =1;
        //     }

        //     if(suffix == 0){
        //         suffix = 1;
        //     }
        //     prefix *= nums[i];
        //     suffix *= nums[n-i-1];

          

        //     maxProd = max(maxProd ,max(prefix, suffix));

        // }

        // return maxProd;

        int maxi = nums[0];
        int mini = nums[0];
        int ans = maxi;

        for(int i=1; i<n; i++) {
            int curr = nums[i];

            int tempMax = max(curr, max(maxi*curr,mini*curr));
            mini = min(curr,min(maxi*curr, mini*curr));

            maxi = tempMax;
            ans = max(maxi,ans);

           
        }

        return ans;
    }
};