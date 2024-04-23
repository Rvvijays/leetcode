class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {

        int index = 0;
        vector<int> ans;

        while(index<nums.size()){
            int curr = nums[index];

            if(ans.size()==0){
                ans.push_back(curr);
                index++;
                continue;
            }

            int prev = ans.back();

            if(curr>0 && prev>0 || curr<0 && prev<0){
                ans.push_back(curr);
                index++;
            }else{

                if(curr<0){

                    // cout<<"curr:"<<curr<<endl;
                    // cout<<"prev:"<<prev<<endl;
                    if(abs(curr)>abs(prev)){
                        ans.pop_back();
                        // ans.push_back(curr);

                    }else if(abs(curr)==abs(prev)){
                        ans.pop_back();
                    index++;

                    }else{
                    index++;

                    }
                }else{


                    // cout<<"curr:"<<curr<<endl;
                    // cout<<"prev:"<<prev<<endl;

                    // if(abs(curr) > abs(prev)){
                    //     ans.pop_back();
                        ans.push_back(curr);
                index++;

                    // }else if(abs(curr) > abs(prev)){
                    //     ans.pop_back();

                    // }
                }


                
            }
        }
        return ans;
        
    }
};