#include <climits>
#include <iostream>
#include <vector>

int CalcDP(bool is_clear, const std::vector<int>& near) {
  if (!is_clear) return INT_MAX;
  int result = INT_MAX;
  for (int x : near) {
    if (x != INT_MAX) result = std::min(result, x + 1);
  }
  return result;
}

int main() {
  int t = 0;
  std::cin >> t;
  std::vector<std::vector<bool>> matrix(3, std::vector<bool>(t));
  for (int row = 0; row < 3; ++row) {
    for (int i = 0; i < t; ++i) {
      char x = 0;
      std::cin >> x;
      matrix[row][i] = x == '0';
    }
  }
  std::vector<int> dp(3);
  dp[0] = 0;
  dp[1] = CalcDP(matrix[1][0], {0});
  dp[2] = CalcDP(matrix[2][0], {dp[1]});

  for (int i = 1; i < t; ++i) {
    std::vector<int> dpnew(3);
    dpnew[1] = CalcDP(matrix[1][i], {dp[0], dp[1], dp[2]});
    dpnew[0] = CalcDP(matrix[0][i], {dp[0], dp[1], dpnew[1]});
    dpnew[2] = CalcDP(matrix[2][i], {dp[1], dp[2], dpnew[1]});
    dp = std::move(dpnew);
  }

  std::cout << (dp[2] == INT_MAX ? -1 : dp[2]) << std::endl;
  return 0;
}
