class Solution {
public:
    vector<int> brute(vector<int>& nums){
        int n = nums.size();
        vector<int> ans(n);
        for(int i=0; i<n; i++){
            int count = 0;
            for(int j=i+1; j<n; j++){
                if(nums[i] > nums[j]){
                    count++;
                }
            }
            ans[i] = count;
        }
        return ans;
    }

    void merge(int low, int mid, int high, vector<int> &ans, vector<pair<int,int>> &nums){

        int left = low;
        int right = mid+1;
        vector<pair<int,int>> temp;

        while (left <= mid && right <= high) {

            if (nums[left].first <= nums[right].first) {
                temp.push_back(nums[right]);
                right++;
            } else {
                ans[nums[left].second] += high - right + 1;
                temp.push_back(nums[left]);
                left++;
            }

        }


        while(left <= mid) {
            temp.push_back(nums[left]);
            left++;
        }

        while(right <= high){
            temp.push_back(nums[right]);
            right++;
        }

        // cout<<"merged:"<<endl;
        for(int i=low; i<=high; i++){
            // cout<<temp[i-low].first<<" ";
            nums[i] = temp[i-low];
        }
    }

    void mergeSort(int low, int high, vector<int> &ans, vector<pair<int,int>> &mp){

        if(low < high){
            int mid = (low + high)/2;
            mergeSort(low,mid,ans,mp);
            mergeSort(mid+1,high,ans,mp);
            merge(low,mid,high,ans,mp);
        }

    }

 
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> mp(n);
        for(int i=0; i<n; i++){
            mp[i] = {nums[i],i};
        }


        // cout<<"seeee:"<<endl;
        // for(int i=0; i<n; i++){
        //     cout<<mp[i].second<<" ";
        // }

        vector<int> ans(n,0);
        mergeSort(0,n-1,ans,mp);

        return ans;
         
    }
};