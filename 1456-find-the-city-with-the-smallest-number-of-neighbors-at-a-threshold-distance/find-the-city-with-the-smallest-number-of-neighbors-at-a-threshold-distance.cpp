class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<vector<int>> list(n,vector<int>(n,1e5));

        for(auto it : edges){
            list[it[0]][it[1]] = it[2];
            list[it[1]][it[0]] = it[2];
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j){
                    list[i][j] = 0;
                }
            }
        }


        for(int via=0; via<n; via++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){

                    // if(list[i][via]!=1e5 && list[via][j]!=1e5){
                        // int dis = min(list[i][j], list[i][via]+list[via][j]);

                        // if(dis<=distanceThreshold) {
                            // cout<<"yha aaya dis:"<<dis<<endl;

                            list[i][j] = min(list[i][j], list[i][via]+list[via][j]);
                        // }else{
                        //     list[i][j] = 1e5;
                        // }
                    // }
                    
                }
            }
        }

        cout<<"matrix:"<<endl;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<list[i][j]<<" ";
            }
            cout<<endl;
        }

        int minn = n;
        int city = 0;

        for(int i=0; i<n; i++){
            int cnt = 0;
            for(int j=0; j<n; j++){

                if(list[i][j]!=1e5 && list[i][j]<= distanceThreshold){
                    cnt++;
                }
            }

            // cout<<"cnt:"<<cnt<<endl;

            // if(cnt!=0){
                if(minn >= cnt){
                    minn = cnt;
                    city = i;
                }
                // minn = min(minn,cnt);
            // }
        }

        return city;


        
    }
};