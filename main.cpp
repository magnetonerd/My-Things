#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>
#include "common.hpp"
using namespace std;

int main()
{
  ifstream infile;
  SampleSpace outcomes[5]; 
  infile.open("nums.dat");
  int num;
  for(int i(0); i < 5 ; ++i){
    infile >> num;
    outcomes[i].sample_size = num;
  }
  infile.close();
  for(int i(0); i < 5; ++i){
    cout << outcomes[i].sample_size << "\n";
  }
}

/*
EXAMPLE OF CREATING AND OPENNING A FILE
int main(){
  ofstream myfile;
  myfile.open("Test.txt");
  myfile << "42\n";
  myfile.close();
}
*/
