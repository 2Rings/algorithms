#include <iostream>
#include <bitset>
using namespace std;

// int getBit(int num, int i){
//   return (num & (1 << i) != 0);
// }
//
// int setBit(int num, int i){
//   return num | (1 << i);
// }
//
// int clearBit(int num, int i){
//   int mask = ~(1 << i);
//   return num & mask;
// }
//
// int clearMSBthroughI(int num, int i){
//   int mask = (1 << i) - 1;
//   return num & mask;
// }
//
// int clearMSBthrough0(int num, int i){
//   int mask = ( -1 << (i+1));
// }
//
// int updateBit(int num, int i, bool bitIs1){
//   int v = bitIs1 ? 1: 0;
//   int mask = ~(1 << i);
//   return (num & mask) | (v << i);
// }
//
// int32_t insertion(int32_t N, int32_t M, int i, int j){
//   int w = j - i;
//   if(W <= 0)
//     return N;
//
//   int32_t maskN = (-1 << (j+1) | (1<<i) - 1);
//   return N & maskN | (M << i);
// }
//
// int flipBitToWin(int bits){
//   int result = 1;
//   int lenLeft = 0;
//   int lenRight = 0;
//   while(bits != 0){
//     if(bits & 1){
//       ++lenLeft;
//     }
//     else{
//       lenRight = lenLeft;
//       lenLeft = 0;
//     }
//     bits >>= 1;
//     result = max(lenRight + lenLeft + 1, result);
//   }
// }

bool debugger(int n){
  return ((n & (n - 1)) == 0);
}

int conversion(int m, int n){
  int r = m^n;
  unsigned int c = 0;
  for(c=0; r ;c++){
    r &= (r - 1);
  }
  return c;
}

int main(){
  int m = 29;
  int n = 15;
  // cout<<bitset<numeric_limits<unsigned int>::digits>(n)<<endl;
  cout<<bitset<8>(n)<<endl;

  cout << bitset<100>(string("100010110")).to_ulong() << endl;
  if(debugger(n))
    cout<<"1"<<endl;
  else
    cout<<"0"<<endl;

  int res = conversion(m,n);
  cout<<"res: "<<res<<endl;
  return 0;
}
