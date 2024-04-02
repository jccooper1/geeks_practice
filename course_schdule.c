/*There are a total of n tasks you have to pick, labelled from 0 to n-1. Some tasks may have prerequisite tasks, for example to pick task 0 you have to first finish tasks 1, which is expressed as a pair: [0, 1]
Given the total number of n tasks and a list of prerequisite pairs of size m. Find a ordering of tasks you should pick to finish all tasks.
Note: There may be multiple correct orders, you just need to return any one of them. If it is impossible to finish all tasks, return an empty array. Driver code will print "No Ordering Possible", on returning an empty array. Returning any correct order will give the output as 1, whereas any invalid order will give the output 0.*/

class Solution
{
  public:
vector<int> findOrder(int numTasks, vector<pair<int, int>>& prerequisites) {
    vector<vector<int>> adj(numTasks);
    vector<int> degree(numTasks, 0);
    for (auto &prereq : prerequisites) {
        adj[prereq.second].push_back(prereq.first);
        degree[prereq.first]++;
    }
    queue<int> q;
    for (int i = 0; i < numTasks; i++)
        if (degree[i] == 0) q.push(i);
    vector<int> order;
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        order.push_back(curr);
        for (auto &next : adj[curr])
            if (--degree[next] == 0) q.push(next);
    }
    if (order.size() != numTasks) order.clear();
    return order;
}
};