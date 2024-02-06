class Solution {
public:

     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //  return brute(nums1,nums2);

        return better(nums1,nums2);


     }

     double optimal(vector<int>& nums1, vector<int>& nums2) {
         int low = 1;
         int high = (nums1.size()+nums2.size())/2;

         int left = high;

         int l1 = 0;
         int l2 = 0;
         int r1 = 0;
         int r2 = 0;

         while(low<=high) {
             int mid = (low+high)/2;

             l1 = nums1[mid-1];
             l2 = nums2[left-mid-1];
             r1 = nums1[mid];
             r2 = nums2[left=mid];

             if(l1<=r2 & l2 <= r1) {
                 break;
             }

             if (l1 > r2) {
                 high = mid - 1;
             }else{
                 low = mid + 1;
             }
         }

         int num1 = l1;
         if(num1 < l2) {
             num1 = l2;
         }

         int num2 = r1;
         if(num2>r2) {
             num2 = r2;
         }

         if((nums1.size() + nums2.size())%2 == 0){
             return (num1+num2)/2.0;
         }else{
             return num2;
         }
     }

     double better(vector<int>& nums1, vector<int>& nums2){

        int a = nums1.size();
        int b = nums2.size();

        vector<int> nums3(a+b);

        int count = 0;
        int ind1 = ((a+b)/2) - 1;
        int ind2 = (a+b)/2;

        //cout<<"index1:"<<ind1<<"index2:"<<ind2;
        int indElem1 = 0;
        int indElem2 = 0;

        while(a>0 && b>0){
            if(nums1[nums1.size() - a]>nums2[nums2.size()-b]){
               if(count == ind1){
                   indElem1 = nums2[nums2.size()-b];
               }

               if(count == ind2){
                   indElem2 = nums2[nums2.size()-b];
               }


                b--;
            }else{

                 if(count == ind2){
                   indElem2 = nums1[nums1.size()-a];
               }
                if(count == ind1){
                   indElem1 = nums1[nums1.size()-a];
               }
                a--;
            }
            count++;
        }

        while(a>0){
            if(count == ind1){
                indElem1 = nums1[nums1.size()-a];
            }

             if(count == ind2){
                indElem2 = nums1[nums1.size()-a];
            }

          
             a--;
             count++;
        }

        while(b>0){
             if(count == ind2){
                  indElem2 = nums2[nums2.size()-b];
               }
                 if(count == ind1){
                  indElem1 = nums2[nums2.size()-b];
               }
            b--;
            count++;
        }


    //cout<<"one:"<<ind1<<"two:"<<ind2<<"count"<<count;

   // cout<<"one:"<<indElem1<<"two:"<<indElem2;
      
        
        if((nums1.size()+nums2.size()) %2 == 0){
            return (indElem1+indElem2)/2.0;
        }else{
           
            return indElem2;
        }


     }
    double brute(vector<int>& nums1, vector<int>& nums2) {

        int a = nums1.size();
        int b = nums2.size();

        vector<int> nums3(a+b);

        int count = 0;

        while(a>0 && b>0){
            if(nums1[nums1.size() - a]>nums2[nums2.size()-b]){
                nums3[count++] = nums2[nums2.size()-b];
                b--;
            }else{
                nums3[count++] = nums1[nums1.size()-a];
                a--;
            }
        }

        while(a>0){
            nums3[count++] = nums1[nums1.size()-a];
             a--;
        }

        while(b>0){
             nums3[count++] = nums2[nums2.size()-b];
            b--;
        }

        if(nums3.size() % 2 == 0) {

            return (nums3[(nums3.size()/2) - 1] + nums3[(nums3.size()/2)])/2.0;

        }

        return nums3[nums3.size()/2];


        
    }
};