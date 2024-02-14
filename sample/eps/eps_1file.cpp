#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// 誤差込みのequal
const double EPS = 1e-6;
bool epsEqual(double a, double b) {
  // 絶対誤差
  if (fabs(a - b) < EPS) return true;
  // 0除算回避（多分上で回避できてるけど）
  if (a == 0) return fabs(b) < EPS;
  // 相対誤差
  return fabs((a - b) / a) < EPS;
};

int main() {
  double N;
  cin >> N;

  auto f = [](double x) -> double { return sqrt(1 - x * x); };

  // 円周率の近似を区分求積法で求めるやつ
  double S = 0;  // 四分円の面積
  rep(i, N) {
    double rect = f(i / N) * (1 / N);
    S += rect;
  }
  double ans = S * 4;

  cout << fixed << setprecision(10) << ans << endl;

  assert(epsEqual(ans, 3.14159265));

  // Nが1e5で3.1416126164、Nが1e6で3.1415946524。
  // EPS=1e-6だと前者がnot equal, 後者がequal

  return 0;
}