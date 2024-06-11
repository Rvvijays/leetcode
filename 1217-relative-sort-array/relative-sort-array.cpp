class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {


        int n1 = arr1.size();
        int n2 = arr2.size();

        int left = 0;
        int right = 0;

        for (int i=0; i<n2; i++) {
            int num = arr2[i];

            // if(right < n1) {
                
                while(arr1[left] == num) {
                    left++;
                }
                right = left + 1;

                for(int j = right; j < n1; j++) {
                    if(arr1[j] == num) {
                        swap(arr1[j], arr1[left]);
                        left++;
                    }
                }

            // }
            
        }

        if(right < n1) {
            sort(arr1.begin()+right-1, arr1.end());
        }

        return arr1;
        
    }
};