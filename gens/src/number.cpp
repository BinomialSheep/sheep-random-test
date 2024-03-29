#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  random_device seed_gen;
  mt19937_64 rnd(seed_gen());

  // 制約のminとmaxを閉区間でセットする
  // N：配列の長さ
  uniform_int_distribution<ll> dist_N(1, 10000);

  // 生成ロジック
  ll N = dist_N(rnd);

  // 出力
  cout << N << endl;
  return 0;
}