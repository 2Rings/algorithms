#include<iostream>
#include<map>
#include<vector>

using namespace std;

class test{
  typedef pair<int, double> PAIR;
  struct mycmp{
    bool operator()(const PAIR& p1, const PAIR& p2){
      return p1.second > p2.second;
    }
  };
public:
  void te(vector<double>& vec){
    map<int, double, mycmp> mp;
    for(int i = 0; i<vec.size(); ++i){
      mp[i] = vec[i];
    }
    for(auto m: mp){
      cout<<"round1"<<endl;

      cout<<m.first<<m.second<<endl;
    }

    mp[2] = 0.7;
    mp[1] = 0.8;

    for(auto m: mp){
      cout<<"round2"<<endl;
      cout<<m.first<<m.second<<endl;
    }
  }
};
int main(){
  test a;
  vector<double> vec = {0.1,0.2,0.3,0.4,0.5};
  a.te(vec);
  return 0;
}
