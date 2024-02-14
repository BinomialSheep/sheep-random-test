#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  random_device seed_gen;
  mt19937_64 rnd(seed_gen());

  // 制約のminとmaxを閉区間でセットする
  // N：配列の長さ
  uniform_int_distribution<int> dist_N(4, 10);
  // 順列の開始値
  int startIndex = 1;

  // 生成ロジック
  int N = dist_N(rnd);

  vector<int> A(N);
  iota(A.begin(), A.end(), startIndex);
  shuffle(A.begin(), A.end(), rnd);

  // 出力
  cout << N << endl;
  rep(i, N) cout << A[i] << " \n"[i == N - 1];
  return 0;
}