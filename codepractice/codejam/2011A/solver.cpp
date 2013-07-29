#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <utility>
using namespace std;

class ordersList {
  queue <pair <pair<char,int>, int> > list;
  int pos; //position of robot
  string color;
  pair <char,int> curButton;
  pair <pair <char,int>, int> curOrder;
public:
  ordersList(string color);
  void print();
  void push(pair <pair<char,int>, int>);
  bool move(const int &curOrderNum); //returns true if button is pushed
  bool empty();
  void clear();
};

int main(){
  bool flag = false; //set to true if curOrderNum needs to be incremented
  int T; //num of test cases
  int time = 0; //time that has elapsed
  int numOrders; //number of orders in given test
  int curOrderNum = 0; //number of order currently being satisfied
  vector <pair<char,int> > allOrders;
  //Augment blue/orangeOrders with index of order in original list
  ordersList blueOrders = ordersList("blue");
  ordersList orangeOrders = ordersList("orange");
  pair <char,int> curPair;
  pair <pair<char, int>, int> curTriple;
  cin >> T;
  for (int i =0;i<T; i++){
    //Read in the data
    cin >>numOrders;
    for (int j =0;j<numOrders; j++){
      cin >> curPair.first >> curPair.second;
      allOrders.push_back(curPair);
    }
    //Build blue/orange orders
    for (unsigned int j =0;j<allOrders.size();j++){
      curPair = allOrders[j];
      curTriple.first = curPair;
      curTriple.second = j;
      if (curPair.first == 'O'){	
	orangeOrders.push(curTriple);
      }
      else
	blueOrders.push(curTriple);
    }
    //orangeOrders.print();
    //blueOrders.print();
    while (!orangeOrders.empty() || !blueOrders.empty()){
      time++;
      //cout << "time "<<time<<" curOrderNum: "<<curOrderNum<<endl;
      flag = orangeOrders.move(curOrderNum);
      if (blueOrders.move(curOrderNum)){
	flag = true;
      }
      if (flag) curOrderNum++;
      flag = false;
    }
    cout <<"Case #"<<(i+1)<< ": "<<time<<endl;
    //clear stuff
    time = 0;
    curOrderNum=0;
    allOrders.clear();
    orangeOrders.clear();
    blueOrders.clear();
  }
}
void ordersList::push(pair <pair<char,int>, int> triple){
  list.push(triple);
}
bool ordersList::empty(){
  return list.empty();
}
bool ordersList::move(const int &curOrderNum){
  if (list.empty())
    return false;
  curOrder = list.front();
  curButton = curOrder.first;
  if (pos>curButton.second)
    pos--;
  else if (pos<curButton.second)
    pos++;
  else if (pos==curButton.second && curOrder.second ==curOrderNum){
    list.pop();
    return true;
    //cout << color<<" pushed button " << curButton.second <<endl;
  }
  return false;
  
}

void ordersList::print(){
  int size = list.size();
  pair<pair<char,int>, int>curTriple;
  for (unsigned int i=0;i<size;i++){
    curTriple = list.front();
    list.pop();
    cout << curTriple.first.first<< " " << curTriple.first.second<<" "<< curTriple.second<<endl;
    list.push(curTriple);
  }
} 
ordersList::ordersList(string col){
  pos =1;
  color = col;
}
void ordersList::clear(){
  while (!list.empty())
    list.pop();
  pos =1;
}
