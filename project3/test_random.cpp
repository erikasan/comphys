#include <iostream>
#include <random>

using namespace std;

int main()
{
  int N = 100000;
    // Initialize the seed and call the Mersienne algo
  random_device rd;
  mt19937_64 gen(rd());
  // Set up the uniform distribution for x \in [[0, 1]
  uniform_real_distribution<double> RandomNumberGenerator(0.0,1.0);

  // Now use the RNG
  double x = 0;
  for (int i = 0; i != N; ++i) {
    x += RandomNumberGenerator(gen);
  }
  x /= N;

  cout << x << endl;
  return 0;
}
