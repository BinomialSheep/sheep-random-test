#include <bits/stdc++.h>
using namespace std;

int main() {
  long N;
  cin >> N;

  long ans = N * (N + 1) / 2;

  // if (N % 2) ans = -1;  // WA

  cout << ans << endl;

  return 0;
}