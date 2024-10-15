#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;

ll n;
vl dp;
vl A;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> n;
  dp = vl(n + 1, 1);

  A = vl(n + 1, 0);
  for (auto i = 1; i <= n; ++i) {
    cin >> A[i];
  }

  ll ans = 1;
  for (auto i = 1; i <= n; ++i) {
    for (auto j = 1; j < i; ++j) {
      if (A[j] < A[i]) {
        dp[i] = max(dp[i], dp[j] + 1);
        ans = max(ans, dp[i]);
      }
    }
  }

  cout << n - ans;

  return 0;
}