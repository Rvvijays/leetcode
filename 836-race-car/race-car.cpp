class Solution {
public:
    int racecar(int target) {
        queue<pair<int, pair<int,int>>> q;

        q.push({0, {1, 0}});


        while (!q.empty()) {

            
            auto it = q.front();
            int curr = it.first;
            int speed = it.second.first;
            int level = it.second.second;
            q.pop();

           




            if (curr == target) {
                return level;
            }

            if(curr >= 2*target && curr > 0 && speed > 0){
                continue;
            }

             if(curr <= 2*target && curr < 0 && speed < 0){
                continue;
            }
                q.push({curr + speed, {speed * 2,level+1}});

            if (curr + speed < target && speed < 0) {
                q.push({curr, {1,level+1}});
            } else if (curr + speed > target && speed > 0) {
                q.push({curr, {-1,level+1}});
            }

            level++;
        }

        return -1;
    }
};