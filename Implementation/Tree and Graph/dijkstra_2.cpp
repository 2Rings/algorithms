#include<iostream>
#include<vector>
using namespace std;
#define V 9

// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree;
class DijkstraSP{

private:
  int minDistance(vector<int>& distTo, vector<bool>& sptSet){
    int min = INT_MAX, min_index;

    for(int v = 0; v<V ; ++v){
      if(!sptSet[v]&& distTo[v] <= min)
        min = distTo[v], min_index = v;
    }

    return min_index;
  }

  int printSolution(vector<int> distTo, int n){
    for(int i = 0; i < n; ++i)
      cout<<i<<" "<<distTo[i]<<endl;
    return 0;
  }

public:
  void Dijkstra(vector<vector<int>>& graph, int s){
    vector<int> distTo(V, INT_MAX);
    distTo[s] = 0;

    vector<bool> sptSet(V, false);

    for(int cnt = 0; cnt < V-1; ++cnt){
      int u = minDistance(distTo, sptSet);

      sptSet[u] = true;

      for(int v = 0; v < V; ++v){
        if(!sptSet[v]&& graph[u][v] && distTo[u] != INT_MAX && distTo[u] + graph[u][v] < distTo[v])
          distTo[v] = distTo[u] + graph[u][v];
      }
    }
    printSolution(distTo, V);
  }
};

int main()
{
  DijkstraSP a;
   vector<vector<int>> graph = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                              {4, 0, 8, 0, 0, 0, 0, 11, 0},
                              {0, 8, 0, 7, 0, 4, 0, 0, 2},
                              {0, 0, 7, 0, 9, 14, 0, 0, 0},
                              {0, 0, 0, 9, 0, 10, 0, 0, 0},
                              {0, 0, 4, 14, 10, 0, 2, 0, 0},
                              {0, 0, 0, 0, 0, 2, 0, 1, 6},
                              {8, 11, 0, 0, 0, 0, 1, 0, 7},
                              {0, 0, 2, 0, 0, 0, 6, 7, 0}
                             };

    a.Dijkstra(graph, 0);

    return 0;
}
