#include<iostream>
#include<vector>
#include<stack>
#include<unordered_set>
#include<utility>
#include<string>

using namespace std;

class SCC{
private:

  stack<int> reversePost;
  int count = 0;

  void dfs(vector<unordered_set<int>>& G,vector<bool>& marked, int v){
    marked[v] = true;
    for(auto w: G[v]){
      if(!marked[w]) dfs(G,marked, w);
    }
    reversePost.push(v);
  }

  void dfs_scc(vector<unordered_set<int>>& G, vector<bool>& visited, vector<int>& id, int v){
    visited[v] = true;
    id[v] = count;
    for(int w: G[v]){
      if(!visited[w]) dfs_scc(G,visited, id, w);
    }
  }

  vector<unordered_set<int>> DAG(vector<pair<int,int>>& graph, int vertex, bool reverse){
    vector<unordered_set<int>> G(vertex);
    if(!reverse){
      for(auto g:graph){
        G[g.first].insert(g.second);
      }
    }
    else{
      for(auto g:graph){
        G[g.second].insert(g.first);
      }
    }
    return G;
  }

public:
  stack<int> topology_sort(vector<pair<int,int>>& graph, int vertex){
    vector<unordered_set<int>> G = DAG(graph, vertex,false);
    vector<bool> marked(vertex,false);
    for(int v = 0; v < vertex; ++v){
      if(!marked[v]) dfs(G,marked,v);
    }
    return reversePost;
  }

  int strong_conponent(vector<pair<int,int>>& graph, int vertex){
    vector<unordered_set<int>> G_rev = DAG(graph,vertex,true);
    vector<unordered_set<int>> G = DAG(graph,vertex,false);

    vector<bool> visited(vertex,false);
    vector<int> id(vertex,0);
    vector<bool> marked(vertex,false);

    for(int v = 0; v< vertex; ++v)
      if(!marked[v]) dfs(G_rev,marked,v);
    vector<int> revP;
    while(!reversePost.empty()){
      revP.push_back(reversePost.top());
      reversePost.pop();
    }
    for(auto ele:revP){
      if(!visited[ele]){
        dfs_scc(G, visited, id, ele);
        count++;
      }
    }
    return count;
  }

  bool isStrongConnencted(vector<int>& id, int v, int u){
    return id[v] == id[u];
  }


};

int main(){
  vector<pair<int,int>> graph1 = {{0,1},{0,2},{0,5},{1,4},{5,2},{3,2},{3,4},{3,5},{3,6},{6,4},{6,0}};
  // vector<pair<int,int>> graph = {{0,1},{0,5},{2,3},{2,0},{3,2},{3,5},{4,2},{4,3},{5,4},{6,0},
                                // {6,4},{6,9},{6,8},{7,6},{7,9},{8,6},{9,10},{9,11},{10,12},{11,4},{11,12},{12,9}};
  SCC a;
  stack<int> res = a.topology_sort(graph1, 7);
  // int res = a.strong_conponent(graph, 13);
  while(!res.empty()){
    int b = res.top();
    res.pop();
    cout<<b<<" ";
  }
  // cout<<res<<endl;
  return 0;
}
