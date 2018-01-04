#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

#define M 6
#define N 6

//A DFS based recursive function that returns true
//if a matching for vertex u is possible

bool bpm(vector<vector<int>>& bpGraph, int u, vector<bool>& visited, vector<int>& matchR){
  //Try every job one by one
  for(int v = 0; v< N; ++v){
    //If applicant u is interested in job v and v is not visited
    if(bpGraph[u][v] == 1 && !visited[v]){
      visited[v] = true;

      //If job 'v' is not assigned to an applicant OR
      // previously assigned applicant for job v has an
      //alternate job available.
      //Since v is marked as visited in the above line, matchR[v]
      //int the following recursive call will not get job 'v' augmentaing
      if (matchR[v] < 0 || bpm(bpGraph, matchR[v], visited, matchR))
      {
        matchR[v] = u;
        return true;
      }
    }
  }
  return false;
}

int maxBPM(vector<vector<int>>& bpGraph){
  vector<int> matchR(N, -1);

  int res = 0;

  for(int u = 0; u < M; ++u){
    vector<bool> visited(N);

    if(bpm(bpGraph, u, visited, matchR))
      ++res;
  }
  return res;
}

// Driver program to test above functions
int main()
{
    // Let us create a bpGraph shown in the above example
    vector<vector<int>> bpGraph = {  {0, 1, 1, 0, 0, 0},
                        {1, 0, 0, 1, 0, 0},
                        {0, 0, 1, 0, 0, 0},
                        {0, 0, 1, 1, 0, 0},
                        {0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 1}
                      };

    cout << "Maximum number of applicants that can get job is "
         << maxBPM(bpGraph);

    return 0;
}
