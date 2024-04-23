class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        int n = nums.size();
        vector<int> newArr(n);

        k = k % n;
        int index = 0;
        for(int i=n-k; i<n; i++){
            newArr[index] = nums[i];
            index++;
        }

        for(int i=0; i<n-k; i++){
            newArr[index] = nums[i];
            index++;
        }

        nums = newArr;
        
    }
};