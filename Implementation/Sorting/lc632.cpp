#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        typedef vector<int>::iterator vi;

        struct mycmp{
            bool operator()(pair<vi,vi> p1, pair<vi,vi> p2){
                return *p1.first > *p2.first;
            }
        };

        int lo = INT_MAX, hi = INT_MIN;
        priority_queue<pair<vi,vi>,vector<pair<vi,vi>>, mycmp> qp;


        for(auto &row:nums){
            lo = min(lo,row[0]);

            hi = max(hi, row[0]);
            qp.push({row.begin(), row.end()});
        }

        while(!qp.empty()){
          auto p = qp.top();
          qp.pop();
          cout<<*p.first<<endl;
        }

        vector<int> res ={lo,hi};

        while(true){
            auto p = qp.top();
            qp.pop();
            ++p.first;

            if(p.first == p.second)
                break;

            qp.push(p);

            lo = *qp.top().first;
            hi = max(hi,*p.first);

            if(hi-lo < res[1] - res[0])
                res = {lo,hi};
        }

        return res;
    }
};

int main(){
  vector<vector<int>> nums = {{4,10,15,24,26}, {0,9,12,20}, {5,18,22,30}};
  Solution a;
  vector<int> res = a.smallestRange(nums);
  for(auto r: res)
    cout<<r<<" ";
}
