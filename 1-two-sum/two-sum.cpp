class Solution {
public:


    vector<int> twoSum(vector<int>& nums, int target) {

       unordered_map<int,int> mp;

       for(int i=0; i<nums.size(); i++){
            int x = target - nums[i];

            if(mp.count(x)){
                return {i,mp[x]};
            }else{
                // cout<<"added "<<x<<" in map at "<<i<<endl; 
                mp[nums[i]] = i; 
            }
       }

       return {};
        
    }
};