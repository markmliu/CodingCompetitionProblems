#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
  int T, N,S,p;
  int low,high;
  int count; //answer for current test case
  int score;  //storing 
  cin >> T;
  for (int i =1;i<=T;i++){
    count = 0;
    cin >> N >> S >> p;
    low = 3*p-4;
    high = 3*p-2;
    for (int j = 0;j<N;j++){
      cin >> score;
      if (score <p) {}
      else if (score >=high) count++;
      else if (score >=low && S>0){
	count++;
	S--;
      } 
    }
    cout << "Case #"<<i<<": "<<count<<endl;
  }
  return 0;
}
