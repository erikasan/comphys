#include <iostream>
#include <vector>

using namespace std;

int main()
{
  short int i;
  vector<short int> digs;
  cout << "Enter an integer: ";
  cin >> i;
  while (i > 0){
    digs.push_back(i%2);
    i = i/2;
  }
  for (short int e = digs.size() - 1; e >= 0; --e){
    cout << digs[e];
  }
}

// Random text for testing
// Another comment for testing GitHub
// Yet another comment
