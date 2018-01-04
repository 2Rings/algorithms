/*
Ford-Fulkerson Algorithm:
The following is simple idea of Ford-Fulkerson Algorithm:
1)Start with initial flow as 0.
2) While there is a augmentaing path from source to sink.
3)Return flow.
*/

#include <iostream>
#include <limits.h>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;

bool bfs(vector<vector<int>>& rGraph, int s, int t, vector<int> & parent){
  //Create a visited array and mark all vertices as not visited

  int V = rGraph.size();

  vector<bool> visited(V);

  //Create a queue, enqueue source vertex and mark source vertex as visited

  queue<int> q;
  q.push(s);
  visited[s] = true;
  parent[s] = -1;

  //Standard BFS Loop
  while(!q.empty()){
    int u = q.front();
    q.pop();

    for(int v = 0; v < V; ++v){
      if(!visited[v]&&rGraph[u][v] > 0){
        q.push(v);
        parent[v] = u;
        visited[v] = true;
      }
    }
  }

  //If we reached sink in BFS starting from source, then return true, else false

  return visited[t];
}


//Return the maximum flow from s to t in the given graph

int fordFulkerson(vector<vector<int>>& graph, int s, int t){
  int u, v;

  int V = graph.size();
  //Create a residual graph and fill the residual graph with given capacities
  // in the original graph as residual capacities in residual graph
  vector<vector<int>> rGraph(graph);

  // for(u = 0; u < V; ++u){
  //   for(v = 0; v < V; ++v){
  //     rGraph[u][v] = graph[u][v];
  //   }
  // }

  vector<int> parent(V);

  int max_flow = 0;

  while(bfs(rGraph, s, t, parent)){
    //Find minimum residual capacity of the edges along the path filled by
    //BFS. Or we can say find the maximum flow through the path found.
    int path_flow = INT_MAX;

    for(v = t; v != s; v = parent[v]){
      u = parent[v];
      path_flow = min(path_flow, rGraph[u][v]);
    }

    //update residual capacities of the edges and reverse edges
    //along the path_

    for(v = t; v != s; v= parent[v]){
      u = parent[v];
      rGraph[u][v] -= path_flow;
      rGraph[v][u] += path_flow;
    }

    max_flow += path_flow;
  }

  return max_flow;
}

int main()
{
    // Let us create a graph shown in the above example
    vector<vector<int>> graph = { {0, 16, 13, 0, 0, 0},
                        {0, 0, 10, 12, 0, 0},
                        {0, 4, 0, 0, 14, 0},
                        {0, 0, 9, 0, 0, 20},
                        {0, 0, 0, 7, 0, 4},
                        {0, 0, 0, 0, 0, 0}
                      };

    vector<int> test(graph[0].begin(), graph[0].begin()+1);
    cout << "The maximum possible flow is " << fordFulkerson(graph, 0, 5)<<endl;
    for(auto v: test){
      cout<<v<<",";
    }
    return 0;
}
