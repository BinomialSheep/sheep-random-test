#include <bits/stdc++.h>
using namespace std;

int main() {
  long N;
  cin >> N;
  auto naive = [&](int n) {
    long ret = 0;
    for (long i = 1; i <= N; i++) ret += i;
    return ret;
  };

  long ans = N * (N + 1) / 2;
  assert(ans == naive(N));
  if (N % 2) assert(false);  // WA

  cout << ans << endl;

  return 0;
}