class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        // 4 optoins +x, -x, +y, -y

        queue<int> q;

        int options[4] = {x,-1*x,y,-1*y};
        int high = x + y;

        q.push(0);
        vector<int> visited(high+1,0);

        while(!q.empty()) {

            int curr = q.front();
            q.pop();

            if(curr == target) {
                return true;
            }

            for(int i=0; i<4; i++) {
                int ncurr = curr + options[i];

                cout<<"ncurr:"<<ncurr<<endl;

                if(ncurr < 0  || ncurr > high || visited[ncurr]==1) {
                    continue;
                }

                visited[ncurr] = 1;

                q.push(ncurr);
            }

        }

        return false;
        
    }
};