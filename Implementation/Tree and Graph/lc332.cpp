#include<iostream>
#include<set>
#include<vector>
#include<unordered_map>
#include<utility>

using namespace std;

class Solution {

private:
    bool dfs(vector<string>& res, unordered_map<string, multiset<string>>& it, string s, int len){
        if(len == 0){
            return true;
        }

        if(it.find(s) == it.end()|| it[s].empty()) return false;

        for(auto i = it[s].begin(); i !=it[s].end() ; ++i){
            res.push_back(*i);
            it[s].erase(i);
            if(dfs(res, it, *i, len-1)) return true;
            else{
                for(auto test:it[s])
                  cout<<test<<" ";
                it[s].insert(*i);
                for(auto test:it[s])
                  cout<<test<<" ";
                res.pop_back();
            }
        }

        return false;


    }
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string, multiset<string>> it;
        for(auto ti: tickets){
            it[ti.first].insert(ti.second);
        }

        string s = "JFK";

        vector<string> res;
        res.push_back("JFK");
        int len = tickets.size();

        dfs(res,it,s,len);

        return res;

    }
};

int main(){
  Solution a;
  vector<pair<string, string>> tickets = {{"JFK","KUL"},{"JFK","NRT"},{"NRT","JFK"}};
  // vector<pair<string, string>> tickets = {{"EZE","TIA"},{"EZE","HBA"},{"AXA","TIA"},{"JFK","AXA"},{"ANU","JFK"},
  // {"ADL","ANU"},{"TIA","AUA"},{"ANU","AUA"},{"ADL","EZE"},{"ADL","EZE"},{"EZE","ADL"},{"AXA","EZE"},
  // {"AUA","AXA"},{"JFK","AXA"},{"AXA","AUA"},{"AUA","ADL"},{"ANU","EZE"},{"TIA","ADL"},{"EZE","ANU"},{"AUA","ANU"}};

  vector<string> res = a.findItinerary(tickets);

  for(auto r: res){
    // cout<<r<<" "<<endl;
  }
  return 0;

}
