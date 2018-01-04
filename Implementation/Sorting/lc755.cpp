#include<iostream>
#include<vector>

using namespace std;

class Solution {

private:
    void drop(vector<int>& heights, int pos){
        bool flag = false;
        //left
        for(int i = pos - 1; heights[i] <= heights[pos]-1 && i>=0; --i){
            if(heights[i] < heights[pos] - 1){
                flag = true;
                heights[i]++;
                heights[pos]--;
            }
        }
        if(!flag){
            for(int i = pos+1; heights[i] <= heights[pos]-1 && i<heights.size(); ++i){
                if(heights[i] < heights[pos]-1){
                    heights[i]++;
                    heights[pos]--;
                }
            }
        }
    }
public:
    vector<int> pourWater(vector<int>& heights, int V, int K) {
        while(V--){
            heights[K]++;
            drop(heights, K);

        }


        return heights;
    }
};


int main(){
  Solution a;
  vector<int> heights = {2,1,1,2,1,2,2};
  vector<int> res = a.pourWater(heights, 4, 3);
  for(auto r: res){
    cout<<r<<" ";
  }
}
