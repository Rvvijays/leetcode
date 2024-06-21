class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {

        int n = customers.size();

        int unsatisfied = 0;
        int totalSatified = 0;
        int i = 0;
        while (i < grumpy.size() && i < minutes) {
            // cout<<"grumpy : "<<grumpy[i]<<endl;

            // cout<<"customers : "<<customers[i]<<endl;

            if (grumpy[i] == 1) {
                unsatisfied += customers[i];
            }else{
                // cout<<"added:"<<endl;
                totalSatified += customers[i];
            }
            i++;
        }

        // cout<<"unsatisfied: "<<unsatisfied<<endl;
        // cout<<"totalSatified: "<<totalSatified<<endl;

       

        i = 1;
        int j = minutes;

        int maxUnsatisfied = unsatisfied;

        while (j < n) {

            // cout<<"checking i:"<<i<<" j:"<<j<<endl;
            

            // cout<<"grumpy : "<<grumpy[j]<<endl;
            // cout<<"customers : "<<customers[j]<<endl;

            if (grumpy[j] == 1) {
                unsatisfied += customers[j];
            }else{
                totalSatified += customers[j];
            }

            if (grumpy[i-1] == 1) {
                unsatisfied -= customers[i-1];
            }


            i++;
            j++;

            maxUnsatisfied = max(maxUnsatisfied, unsatisfied);
        }

        // cout<<"maxUnsatisfied: "<<maxUnsatisfied<<endl;
        // cout<<"totalSatified: "<<totalSatified<<endl;


        return totalSatified + maxUnsatisfied;
        
    }
};