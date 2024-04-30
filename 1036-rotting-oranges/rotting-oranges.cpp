class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {
        
	int n = grid.size();
	int m = grid[0].size();
	queue<pair<int,pair<int,int>>> q;

    int totalOranges = 0;
    int orangeRot = 0;

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(grid[i][j] == 2){
				q.push({i,{j,0}});
                totalOranges++;
                orangeRot++;
			}

            if(grid[i][j] == 1){
                totalOranges++;
            }


		}
	}

    if(totalOranges==0){
        return 0;
    }

    if(orangeRot == 0){
        return -1;
    }
	
	int dx[4] = {0,0,1,-1};
	int dy[4] = {1,-1,0,0};
	
	int ans = 0;

	
	while(!q.empty()){
		auto it = q.front();
        q.pop();

        int i = it.first;
        int j = it.second.first;
        int minute = it.second.second;
		
		ans = minute;
		
		for(int k=0; k<4; k++){
			int x = i + dx[k];
			int y = j + dy[k];
			
			if(x<0 || y <0 || x >= n || y>=m || grid[x][y]!=1){
				continue;
			}
            grid[x][y] = 2;
            orangeRot++;
			
			q.push({x,{y,minute+1}});
		}
		
	}
	
	return totalOranges == orangeRot ? ans:-1;

        
    }
};