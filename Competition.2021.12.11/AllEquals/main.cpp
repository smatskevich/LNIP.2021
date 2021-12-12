#include <algorithm>
#include <iostream>
#include <vector>

int GCD(int a, int b) {
  int r = a % b;
  while (r != 0) {
    a = b;
    b = r;
    r = a % b;
  }
  return b;
}

int UpdateGCD(int d1, int d2) {
  if (d1 == 0) return d2;
  if (d2 == 0) return d1;
  return GCD(d1, d2);
}

int main() {
  int n = 0;
  std::cin >> n;
  std::vector<int> v(n);
  for (int i = 0; i < n; ++i) std::cin >> v[i];

  int x = *std::min_element(v.begin(), v.end());
  int best_gcd = 0;
  for (int i = 0; i < n; ++i) {
    best_gcd = UpdateGCD(v[i] - x, best_gcd);
  }
  std::cout << (best_gcd == 0 ? -1 : best_gcd) << std::endl;
  return 0;
}
