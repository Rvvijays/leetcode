class Solution {
public:



    void generate(long currSum,int index,long prev, string curr, string num, int target, vector<string> &ans){

        // cout<<"sum:"<<curr<<" | index:"<<index<<" | numLength:"<<currSum<<endl;
        if(index == num.length()){
            if(target == currSum){
                ans.push_back(curr);
            }
            return;
        }

        int b = num[index] - '0';


        // if(b == 0){
        //     b = prev * 10;
        //     generate(currSum,index+1,b,curr,num,target,ans);
        // }

        int backup = currSum;

        // // +
        currSum += b;

        generate(currSum,index+1,b,curr+"+"+num[index],num,target,ans);

        currSum = backup;

        if(b == 0 && prev!=0){
            currSum *= 10;
            generate(currSum,index+1,b,curr+num[index],num,target,ans);
            currSum = backup;
        }

        // // - 
        currSum -= b;

        generate(currSum,index+1,-b,curr+"-"+num[index],num,target,ans);

         currSum = backup;


        // // *

        currSum = currSum - prev +( prev * b);
        // currSum *=  b;


        generate(currSum,index+1,prev * b,curr+"*"+num[index],num,target,ans);

        currSum = backup;




    }



    void recursion(int i, string sumPath, long sum,long prev,string num, int target, vector<string> &result) {

        if(i == num.size()){
            if(sum == target){
                result.push_back(sumPath);
            }

            return;
        }

        for(int j=i; j<num.size(); j++){
            if(j > i && num[i] == '0'){
                break;
            }

            long number = stol(num.substr(i,j-i+1));
            string tempPath = num.substr(i,j-i+1);

            if(i==0){
                recursion(j+1,tempPath,number,number,num,target,result);
            }else{
                recursion(j+1,sumPath+ '+' + tempPath,sum + number,number,num,target,result);
                recursion(j+1,sumPath+'-'+tempPath, sum - number,-number,num,target,result);
                recursion(j+1, sumPath+'*'+tempPath, sum - prev + (prev*number),prev*number,num,target,result);

            }
        }

    }
    vector<string> addOperators(string num, int target) {

        // vector<string> ans;

        // int a = num[0] - '0';

        // string curr;
        // curr += num[0];

        // generate(a,1,a,curr,num,target,ans);

        // return ans;

        vector<string> result;

        recursion(0,"",0,0,num,target,result);

        return result;



        
    }
};