#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[]){
  int N = 0;
  int C = 0;
  int I = 0;
  int * items;
  bool found;
  //  ifstream myfile;
  //  myfile.open(argv[1]);
  cin >> N;
  for (int i=0;i<N;i++){
    // read in params
    cin >> C;
    cin >> I;
    items =  new int[I];

    for (int j=0;j<I;j++){
      cin >>items[j];
    }
    found = false;
    // find solution with double for loop?
    for (int a=0;a<I&&!found;a++){
      for (int b=0;b<I&&!found;b++){
	if (a!=b&&items[a]+items[b]==C){
	  found = true;
	  cout << "Case #"<<i+1<<": "<<a+1<<" "<<b+1<<endl; 
	}
      }
    }



    delete[] items;
  }

}
