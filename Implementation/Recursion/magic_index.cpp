#include <iostream>
#include <vector>

using namespace std;

int magic_index(vector<int> & array){
  int ri = array.size()-1;
  int le = 0;
  while(le <= ri){
    int mid = le + ((ri-le) >> 1);
    if(array[mid] > mid) ri = mid - 1;
    if(array[mid] < mid) le = mid + 1;
    else return mid;
  }
  return -1;
}

int main(){
  vector<int> array = {-2,-1,2,6,7};
  // vector<int> array = {0};
  int res = magic_index(array);
  cout<<"result: "<<res<<endl;
  return 0;
}
