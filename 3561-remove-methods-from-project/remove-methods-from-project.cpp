class Solution {
public:

    void dfs(int node,
             vector<vector<int>>& graph,
             vector<bool>& suspicious)
    {
        suspicious[node] = true;

        for (int child : graph[node])
        {
            if (!suspicious[child])
            {
                dfs(child, graph, suspicious);
            }
        }
    }

    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations)
    {
   
        vector<vector<int>> graph(n);

        for (auto edge : invocations)
        {
            graph[edge[0]].push_back(edge[1]);
        }

        vector<bool> suspicious(n, false);
        dfs(k, graph, suspicious);

        for (auto edge : invocations)
        {
            int u = edge[0];
            int v = edge[1];

            if (!suspicious[u] && suspicious[v])
            {
                vector<int> ans;
                for (int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (!suspicious[i])
                ans.push_back(i);
        }

        return ans;
    }
};