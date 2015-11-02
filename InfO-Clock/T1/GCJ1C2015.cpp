#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int solve() {
  int c, d, v;
  cin >> c >> d >> v;
  vector<int> coin;
  for(int i = 0; i < d; ++i) {
    int x;
    cin >> x;
    coin.push_back(x);
  }
  reverse(coin.begin(), coin.end());
  int cnt = 0;
  long long S = 0;
  while(S < v) {
    if(coin.empty() || !(coin.back() <= S + 1)) {
      coin.push_back(S + 1);
      ++cnt;
    } else {
      S += (long long)(coin.back()) * c;
      coin.pop_back();
    }
  }
  return cnt;
}

int main() {
  int T;
  cin >> T;
  for(int i = 1; i <= T; ++i) {
    cout << "Case #" << i << ": " << solve() << "\n";
  }
  return 0;
}
