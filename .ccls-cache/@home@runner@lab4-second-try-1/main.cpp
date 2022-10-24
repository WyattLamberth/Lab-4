#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
using namespace std;

struct activity{
  int order;
  string act;
  float time;
};

void print_struct(activity a){
  cout << "Act: " << a.act << endl;
  cout << "Time: " << a.time << endl;
  cout << "Order: " << a.order << endl;
}

void print_vector(vector<activity> v){
  for (int i = 0; i < v.size(); i++){
    print_struct(v.at(i));
  }
}

bool compareByTime(const activity &a, const activity &b){
  return a.time < b.time;
}

//sort vector of structs based on flaot value time
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

int main(int argc, char *argv[]) {
  ifstream fin("input1.txt");
  ofstream fout("output1.txt");

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
    
}
