#include <bits/stdc++.h>
using namespace std;

int main() {
  random_device seed_gen;
  mt19937_64 rnd(seed_gen());

  // 制約のminとmaxを閉区間でセットする
  // N：配列の長さ
  uniform_int_distribution<int> dist_N(1, 10000);

  // 生成ロジック
  int N = dist_N(rnd);

  // 出力
  cout << N << endl;
  return 0;
}