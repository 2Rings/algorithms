#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

class SPT{
private:
  int minDistance(vector<int>& distTo, vector<bool>& sptSet){
    int min = INT_MAX, min_index;

    for(int v = 0; v<distTo.size() ; ++v){
      if(!sptSet[v] && distTo[v] <= min)
        min = distTo[v], min_index = v;
    }

    return min_index;
  }

  void relax(vector<int>& distTo, unordered_map<int, unordered_map<int, int>>& w_G, int v, pair<int, int> w){
    if(distTo[w.first] > distTo[v] + w_G[v][w.first]){
      distTo[w.first] = distTo[v] + w_G[v][w.first];
    }
  }

  unordered_map<int, unordered_map<int, int>> Weighted_G(vector<vector<int>>& G){
    unordered_map<int, unordered_map<int, int>> m;
    for(auto vec: G){
      m[vec[0]].insert(make_pair(vec[1],vec[2]));
    }

    return m;
  }

public:
  vector<int> DijkstraSP(vector<vector<int>>& graph, int s, int vertex){
    unordered_map<int, unordered_map<int, int>> w_G = Weighted_G(graph);
    vector<int> distTo(vertex, INT_MAX);
    distTo[s] = 0;
    vector<bool> sptSet(vertex,false);

    for(int cnt = 0; cnt < vertex-1; ++cnt){
      int v = minDistance(distTo, sptSet);
      sptSet[v] = true;
      for(auto w:w_G[v]){
        relax(distTo, w_G, v, w);
      }
    }

    //PQ:
    // priority_queue<pair<int,double>, vector<pair>, mycmp> qp;
    // map<int, double, mycmp> mp;
    // qp.push(s, 0.0);
    // int cnt = 1;

    // while(cnt == vertex){
    //   pair<int, double> pa = qp.top();
    //   // pair<int, double> pa = mp.begin();
    //   int v = pa.first;
    //
    //   qp.pop();
    //
    //   for(auto w: w_G[v]){
    //     relax(distTo, w_G, w, pa);
    //     cnt++;
    //   }
    // }

    return distTo;
  }
};


int main(){
  vector<vector<int>> graph = {{0,1,5},{0,4,9},{0,7,8},{1,3,15},{1,7,4},{1,2,12},{7,2,7},
                              {7,5,6},{4,7,5},{4,5,4},{4,6,20},
                              {2,3,3},{2,6,11},{5,2,1},{5,6,13},{3,6,9}};


  SPT a;
  vector<int> res = a.DijkstraSP(graph, 0, 8);

  for(int i = 0; i<res.size(); ++i){
    cout<<i<<" "<<res[i]<<endl;
  }
  // int a = INT_MAX;
  // int b = INT_MIN;
  //
  // // int b = 0x7FFFFFFF ;
  // int d = 0x80000000;
  //
  // cout<<a<<endl;
  //
  // cout<<b<<endl;
  //
  //
  // cout<<d<<endl;

  return 0;
}
