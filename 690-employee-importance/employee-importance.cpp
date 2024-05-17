/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int dfs(int id, unordered_map<int,vector<int>> &list,unordered_map<int,int> &imp) {
        int total = imp[id];

        for(auto it : list[id]) {
            total += dfs(it,list,imp);
        }

        return total;
    }
    int getImportance(vector<Employee*> employees, int id) {


        unordered_map<int,vector<int>> list;
        unordered_map<int,int> imp;
        for(auto it: employees) {
            list[it->id] = it->subordinates;
            imp[it->id] = it->importance;
        }

        return dfs(id,list,imp);

        
    }
};