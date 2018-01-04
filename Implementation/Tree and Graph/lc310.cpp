//this code(TLE)

class Solution {

private:
    void dfs(vector<unordered_set<int>>& graph, vector<bool>& visited, int v, int depth, int& maxDepth){
        visited[v] = true;
        maxDepth = max(depth, maxDepth);
        for(auto w:graph[v]){
            if(!visited[w]) dfs(graph, visited, w, depth+1, maxDepth);
        }

    }
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if(n == 0) return {};
        // if(edges.size() == 0){
        //     vector<int> vec;
        //     for(int i = 0; i<n; ++i)
        //         vec.push_back(i);
        //     return vec;
        // }

        vector<unordered_set<int>> graph(n);
        // set<int> vet;
        for(auto e:edges){
            graph[e.first].insert(e.second);
            graph[e.second].insert(e.first);
            // vet.insert(e.first);
            // vet.insert(e.second);
        }


        map<int, vector<int>> mp;
        vector<bool> visited(n);
        int maxDepth;
        int depth;
        int minDepth = INT_MAX;
        for(int v = 0; v < n; ++v){
            for(int i = 0; i< n; ++i)
                visited[i] = false;
            visited[v] = true;
            maxDepth = 0;
            dfs(graph, visited, v, depth, maxDepth);
            mp[maxDepth].push_back(v);
            minDepth = min(minDepth, maxDepth);
        }
        return mp[minDepth];
    }
};
