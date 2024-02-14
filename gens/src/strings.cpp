#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  random_device seed_gen;
  mt19937_64 rnd(seed_gen());

  // 制約のminとmaxを閉区間でセットする
  // N：配列の長さ
  uniform_int_distribution<int> dist_N(1, 20);
  // 使用文字（小文字：1、大文字：2、数字：4として1-7で指定
  // i.e. 1：小文字、2：大文字、3：小大、4：数字、5：小数、6：大数、7：小大数
  int charKind = 1;
  assert(1 <= charKind && charKind <= 7);

  // 生成ロジック
  int cmax = 0;
  if (charKind & 1) cmax += 25;
  if ((charKind >> 1) & 1) cmax += 25;
  if ((charKind >> 2) & 1) cmax += 9;
  uniform_int_distribution<int> dist_C(0, cmax);

  int N = dist_N(rnd);
  string S = "";
  rep(i, N) {
    char c;
    int num = dist_C(rnd);
    if ((charKind & 1) == 0) num += 26;
    if (25 < num && ((charKind >> 1) & 1) == 0) num += 26;
    if (num < 26) {
      c = 'a' + num;
    } else if (num < 52) {
      c = 'A' + num % 26;
    } else {
      c = '0' + num % 52;
    }
    S.push_back(c);
  }

  // 出力
  cout << N << '\n' << S << endl;
  return 0;
}