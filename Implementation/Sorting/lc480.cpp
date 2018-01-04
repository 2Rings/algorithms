#include<iostream>
#include<vector>

using namespace std;

class Solution {

private:
    int select(vector<int> vec, int k){
        int lo = 0;
        int hi = vec.size() - 1;
        while(lo < hi){
            int j = partition(vec, lo, hi);
            if(j<k) lo = j + 1;
            else if(j > k) hi = j - 1;
            else return vec[k];
        }
        return vec[k];
    }

    int partition(vector<int>& a, int lo, int hi){
        int i = lo, j = hi+1;
        while(true){
            while(a[++i]<a[lo]){
                if(i == hi) break;
            }
            while(a[lo]<a[--j]){
                if(j == lo) break;
            }

            if(i>=j) break;

            swap(a[i], a[j]);
        }
        swap(a[lo], a[j]);
        return j;
    }
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        int len = nums.size();
        int ov = k%2;
        for(int i = 0; i<= len - k; ++i){
            vector<int> vec(nums.begin()+i, nums.begin()+i+k);
            if(ov){
                int mid = (k-1)>>1;
                res.push_back((double)select(vec,mid));
            }
            else{
                int mid = (k-1)>>1;
                int a = select(vec, mid);
                int b = select(vec, mid+1);
                double c = ((double)a+(double)b)/2;
                cout<<a<<" "<<b<<" "<<c<<endl;
                res.push_back(c);
            }
        }
        return res;
    }
};

int main(){
  // vector<int> nums = {1,3,-1,-3,5,3,6,7};
  vector<int> nums = {1,4,2,3};

  Solution a;
  vector<double> res = a.medianSlidingWindow(nums,4);
  for(auto v:res){
    cout<<v<<",";
  }
  return 0;
}
