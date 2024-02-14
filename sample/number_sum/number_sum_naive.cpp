#include <bits/stdc++.h>
using namespace std;

int main() {
  long N;
  cin >> N;

  long ans = 0;
  for (long i = 1; i <= N; i++) ans += i;

  cout << ans << endl;

  return 0;
}