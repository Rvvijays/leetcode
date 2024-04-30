class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
	
	int left = 0;
	int right = nums.size()-1;
	int operations = 0;
	while(left < right){
		if(nums[left] + nums[right] == k){
			left++;
			right--;
			operations++;
		}else if(nums[left] + nums[right] > k){
			right--;
		}else{
			left++;
		}
	}
	
	return operations;
    }
};