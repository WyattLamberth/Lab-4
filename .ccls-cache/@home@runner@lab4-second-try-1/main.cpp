#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include "ArgumentManager.h"
using namespace std;

struct activity{
  int order;
  string act;
  float time;
};

void print_struct(activity a){
  cout << a.act << " " << a.time << endl;
}

void print_vector(vector<activity> v){
  for (int i = 0; i < v.size(); i++){
    print_struct(v.at(i));
  }
}

bool compareByTime(const activity &a, const activity &b){
  return a.time < b.time;
}

//sort vector of structs based on float value time
void sort_activities(vector<activity> &v){
  cout << "UNSORTED:" << endl;
  print_vector(v);
  cout << "END UNSORTED" << endl;

  cout << endl;

  std::sort(v.begin(), v.end(), compareByTime);

  cout << "SORTED:" << endl;
  print_vector(v);
  cout << "END SORTED" << endl;
}

void printToFile(vector<activity> v, ofstream &fout){
  for (int i = 0; i < v.size(); i++){
    fout << v.at(i).act << endl;
  }
}

int main(int argc, char *argv[]) {

  ArgumentManager am;
  
  ifstream fin(am.get("input"));
  ofstream fout(am.get("output"));

  priority_queue<activity> q;
  vector<activity> v;
  
  string line;
  int count = 0;
  //grab input
  while (getline(fin, line)){
    activity current;
    
    int numindex;
    for (int i = 0; i < line.length(); i++){
      if (isdigit(line[i])){
        numindex = i;
        break;
      }
    }

    string temp;
    for (int i = 0; i < numindex; i++)
      temp += line[i];

    current.act = temp;

    float t;
    temp = "";
    for (int i = numindex; i < line.length(); i++)
      temp += line[i];

    t = stof(temp);

    current.time = t;
    current.order = count;
    count++;

    //print_struct(current);
    v.push_back(current);
  }

  sort_activities(v);

  printToFile(v, fout);
    
}
