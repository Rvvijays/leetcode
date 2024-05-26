class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {

        int n = tasks.size();

        vector<vector<int>> sortedTasks;

        for (int i = 0; i < n; i++) {
            int start_time = tasks[i][0];
            int processing_time = tasks[i][1];

            sortedTasks.push_back({start_time, processing_time, i});
        }

        sort(sortedTasks.begin(), sortedTasks.end());
        int current_time = 0;

        int index = 0;
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> tasksQueue;

        vector<int> ans;
        while (index < n) {

            if(index < n && tasksQueue.empty() && current_time < sortedTasks[index][0]) {
                cout<<"added task: "<<sortedTasks[index][2]<<endl;
                tasksQueue.push({sortedTasks[index][1],sortedTasks[index][2]});
                current_time = sortedTasks[index][0];
                index++;
            }

            while(index < n && current_time >= sortedTasks[index][0]) {
                cout<<"added task: "<<sortedTasks[index][2]<<endl;

                tasksQueue.push({sortedTasks[index][1],sortedTasks[index][2]});
                index++;
            }

            // if(tasksQueue.empty()) {
            //     break;
            // }

            auto task = tasksQueue.top();
            tasksQueue.pop();


            int processing_time = task.first;
            int task_index = task.second;
            cout<<"executed task: "<<task_index<<endl;

            ans.push_back(task_index);
            current_time += processing_time;
        }

        while(!tasksQueue.empty()) {
             auto task = tasksQueue.top();
            tasksQueue.pop();

            int processing_time = task.first;
            int task_index = task.second;

            ans.push_back(task_index);
        }

        return ans;
        
    }
};