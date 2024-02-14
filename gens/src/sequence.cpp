#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  random_device seed_gen;
  mt19937_64 rnd(seed_gen());

  // 制約のminとmaxを閉区間でセットする
  // N：配列の長さ
  uniform_int_distribution<int> dist_N(1, 10);
  // Ai：配列の要素の値
  uniform_int_distribution<ll> dist_A(1, 20);
  // オプション
  // 0：sortしない 1：昇順ソート -1：降順ソート
  int sorted = 0;
  // 要素の重複なし
  bool isUnique = 0;

  // 生成ロジック
  int N = dist_N(rnd);
  vector<ll> A;
  unordered_set<ll> st;
  while ((int)A.size() < N) {
    int v = dist_A(rnd);
    if (isUnique && st.count(v)) continue;
    if (isUnique) st.insert(v);
    A.push_back(v);
  }
  if (sorted == 1) sort(A.begin(), A.end());
  if (sorted == -1) sort(A.rbegin(), A.rend());

  // 出力
  cout << N << endl;
  rep(i, N) cout << A[i] << " \n"[i == N - 1];
  return 0;
}