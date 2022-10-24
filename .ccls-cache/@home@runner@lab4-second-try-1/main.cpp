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

void selectionSort(vector<activity> v)
{
    int i, j, min_idx;
 
    // One by one move boundary of
    // unsorted subarray
    for (i = 0; i < v.size() - 1; i++)
    {
       
        // Find the minimum element in
        // unsorted array
        min_idx = i;
        for (j = i+1; j < v.size(); j++)
        if (v.at(j).time < v.at(min_idx).time)
            min_idx = j;
 
        // Swap the found minimum element
        // with the first element
        if(min_idx!=i)
            swap(&v.at(min_idx), &v.at(i));
    }
}

void print_struct(activity a){
  cout << a.act << endl;
  cout << a.time << endl;
}

void print_vector(vector<activity> v){
  for (int i = 0; i < v.size(); i++){
    cout << "Act: " << v.at(i).act << endl;
    cout << "Time: " << v.at(i).time << endl;
    cout << "Order: " << v.at(i).order << endl;
  }
}

int main(int argc, char *argv[]) {
  ifstream fin("input1.txt");
  ofstream fout("output1.txt");

  priority_queue<activity> q;
  vector<activity> v;
  
  string line;
  int count = 0;
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

  print_vector(v);
    
}
