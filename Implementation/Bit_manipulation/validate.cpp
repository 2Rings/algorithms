#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool leap_year(int year){
  return (year%4==0 && year%100 != 0)||(year%400)==0;
  //2015<= year <= 2017
  // return year%4==0;
}

int getDate(int year, int month){
  if(month>12||month<1)
    return -1;
  //method 1:
  // int date = 0;
  // switch (month) {
  //   case 1: case 3:case 5:case 7:case 8:case 10:case 12: date = 31;break;
  //   case 2: {
  //     date = leap_year(year) ? 29 : 28;
  //     break;}
  //   case 4:case 6:case 9:case 11: date = 30;break;
  // }
  // return date;
  //method 2:
  int dayOfMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  return dayOfMonth[month] + (month==2&&leap_year(year));
}

bool valid_date(string s){
  vector<string> m_d_y(3,"");\
  int j = 0;
  for(int i = 0; i<s.length();++i){
    if(s[i] == '/'){
      if(m_d_y[j] == "")
        return false;
      j++;
    }
    else if((s[i]-'0')>=0&&(s[i]-'0')<=9){
      m_d_y[j] += s[i];
    }
    else{
      return false;
    }
    if(j>=3)
      return false;
  }

  if(m_d_y[0].size()>2||m_d_y[1].size()>2)
    return false;

  int month = stoi(m_d_y[0]);
  int date = stoi(m_d_y[1]);
  int year = stoi(m_d_y[2]);
  if(year<2000)
    year += 2000;
  if(year<2015 || year > 2017)
     return false;
  int d = getDate(year, month);
  return (d != -1)&&(date<=d)&&(date>=1);
}

// bool val(int year, int month, int date){
//    if(year<2015 || year > 2017)
//       return false;
//    int d = getDate(year, month);
//    return (d != -1)&&(date<=d)&&(date>=1);
// }

int main(){
  string test_1 = "02/01/16";
  bool test_res = valid_date(test_1);
  if(test_res)
    cout<<"true"<<endl;
  else
    cout<<"false"<<endl;
  return 0;
}
