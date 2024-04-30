class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
	queue<int> q;
	q.push(0);
	int n = rooms.size();
	
	vector<int> vis(n,-1);
	vis[0] = 1;
	
	while(!q.empty()){
		auto node = q.front();
		q.pop();
		
		for(auto it : rooms[node]){
			if(vis[it]==-1){
                vis[it] = 1;
				q.push(it);
			}
			
		}
	}
	
	for(int i=0; i<n; i++){
		if(vis[i] == -1){
			return false;
		}
	}
	
	return true;
    }
};