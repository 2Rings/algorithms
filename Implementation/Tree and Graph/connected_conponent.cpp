#include<iostream>
#include<vector>

using namespace std;

class CC{

private:
  int count = 0;

  void dfs(vector<vector<int>>& G, int v, vector<bool>& marked, vector<int>& id){
    marked[v] = true;
    id[v] = count;
    for(int j = 0; j<G[v].size(); ++j){
      if(G[v][j] == 1&&!marked[j])
        dfs(G,j,marked, id);

    }
  }

  bool isConnected(vector<int>& id, int v, int u){
    return id[v]==id[u];
  }

  vector<vector<int>> make_adj(vector<pair<int,int>>& graph, int vertex){
    vector<vector<int>> G(vertex, vector<int>(vertex,0));
    for(int i = 0; i < vertex; ++i){
      G[i][i] = 1;
    }
    for(auto g:graph){
      G[g.first][g.second] = 1;
      G[g.second][g.first] = 1;
    }
    return G;
  }

public:
  int conponent(vector<pair<int,int>>& graph, int vertex){
    vector<vector<int>> G = make_adj(graph,vertex);
    vector<bool> marked(vertex,false);
    vector<int> id(G.size());
    for(int v = 0; v < G.size(); ++v){
      if(!marked[v]){
        dfs(G,v,marked,id);
        count++;
      }
    }
    return count;
  }
};




int main(){
  vector<pair<int,int>> graph = {{0,1},{0,2},{0,5},{0,6},{5,3},{5,4},{3,4},
                              {4,6},{7,8},{9,10},{9,11},{9,12}};
  cout<<"1"<<endl;
  CC a;
  int res = a.conponent(graph,13);
  cout<<res<<endl;
  return 0;
}
