class Solution {

    int upperBound(vector<int> nums, int x){
        int low = 0;
        int high = nums.size() - 1;
        int ans = high;

        while(low <= high){
            int mid = (low+high)/2;

            if(nums[mid] > x){
                high = mid - 1;
                ans = mid;
            }else{
                low = mid + 1;
            }
        }

        if(ans == high){
            return INT_MAX;
        }

        return nums[ans];
    }
public:

    string merge(int h1,int h2, int m1, int m2){

        // cout<<"to merge"<<endl;
        // cout<<"m2:"<<m2<<endl;
        string s = to_string(h1) + to_string(h2) + ":" + to_string(m1) + to_string(m2);
        // s += h2 + '0' + ':' + m1 + '0' + m2 + '0';

        return s;
    }
    string nextClosestTime(string time) {

        int h1 = time[0] - '0';
        int h2 = time[1] - '0';
        int m1 = time[3] - '0';
        int m2 = time[4] - '0';

        vector<int> allowed = {h1,h2,m1,m2};

        sort(allowed.begin(), allowed.end());
        // cout<<"sort ho ga"<<endl;

        int newM2 = upperBound(allowed,m2);

        cout<<"m2:"<<newM2<<endl;

        if(newM2 >= 0 && newM2 <= 9){
            m2 = newM2;

            // cout<<"new m2 milana:"<<m2<<endl;
            return merge(h1,h2,m1,m2);
        }else{
            m2 = allowed[0];
        }

        int newM1 = upperBound(allowed,m1);
        cout<<"newM1:"<<newM1<<endl;

        if(newM1 >= 0 && newM1 <= 5){
            m1 = newM1;
            return merge(h1,h2,m1,m2);
        }else{
            m1 = allowed[0];
        }

        int newh2 = upperBound(allowed,h2);
        cout<<"newh2:"<<newh2<<endl;

        if((h1 < 2 && newh2 >= 0 && newh2 <= 9) || (h1 == 2 && newh2 >=0 && newh2 <= 3)){
            h2 = newh2;
            return merge(h1,h2,m1,m2);
        }else{
            h2 = allowed[0];
        }

        int newh1 = upperBound(allowed,h1);
        cout<<"newh1:"<<newh1<<endl;

        if(newh1 >= 0 && newh1 <= 2){
            h1 = newh1;
            return merge(h1,h2,m1,m2);
        }else{
            h1 = allowed[0];
        }

        return merge(h1,h2,m1,m2);


        
    }
};