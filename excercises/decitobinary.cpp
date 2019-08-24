#include <iostream>
#include <vector>

using namespace std;

int main()
{
  float i;
  vector<int> digs;
  cout << "Enter a number to convert to binary: ";
  cin >> i;
  while (i > 0){
    digs.push_back(((int) i%2));
    i = ((int) i)/2;
  }
  for (short int e = digs.size() - 1; e >= 0; --e){
    cout << digs[e];
  }
}
