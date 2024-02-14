#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  vector<ll> A(N);
  rep(i, N) cin >> A[i];

  // sort
  sort(A.begin(), A.end());

  // judge
  auto judge = [&]() {
    rep(i, N - 1) if (A[i] > A[i + 1]) return false;
    return true;
  };

  assert(judge());

  // 出力
  rep(i, N) cout << A[i] << " \n"[i == N - 1];
  return 0;
}