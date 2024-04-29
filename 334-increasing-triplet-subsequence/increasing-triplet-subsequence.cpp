class Solution {
public:
    bool increasingTriplet(vector<int>& arr) {
    	int first_small = INT_MAX;
	int second_small = INT_MAX;
	
	int n = arr.size();
	
	for(int i=0; i<n; i++){
		if(arr[i] <= first_small){
			first_small = arr[i];
		}else if(arr[i] <= second_small){
			second_small = arr[i];
		}else{
			return true;
		}
	}
	
	return false;
    }
};