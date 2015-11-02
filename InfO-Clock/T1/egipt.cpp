#include <fstream>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

const int MAX_N = 1e4 + 1;

int v[MAX_N],
    n;
int belong[MAX_N];

int cnt[5];

int st[5];

vector<int> bad[5][5];

vector< pair<int, int> > swaps;

void doSwap(int a, int b) {
  swaps.push_back(make_pair(a, b));
  swap(v[a], v[b]);
}

int getBack(int i, int j) {
  int ret = bad[i][j].back();
  bad[i][j].pop_back();
  return ret;
}

void swapPos(int i, int j, int k, int l) {
  doSwap(getBack(i, j), getBack(k, l));
}

void two(int i, int j, int k) {
  if(bad[i][j].empty() || bad[j][k].empty() || bad[k][i].empty())
    return;
  int a = getBack(i, j),
      b = getBack(j, k),
      c = getBack(k, i);

  doSwap(a, c);
  doSwap(a, b);

  return two(i, j, k);
}

void one(int i, int j) {
  if(bad[i][j].empty() || bad[j][i].empty())
    return;
  int a = getBack(i, j),
      b = getBack(j, i);
  doSwap(a, b);
  return one(i, j);
}


int main() {
  ifstream in("egipt.in");
  in >> n;
  for(int i = 1; i <= n; ++i) {
    in >> v[i];
    cnt[v[i]]++;
  }
  in.close();

  st[0] = 1;

  for(int i = 1; i <= 3; ++i) {
    st[i] = st[i - 1] + cnt[i - 1];
  }
  
  st[4] = n + 1;

  for(int j = 1; j <= 3; ++j) {
    for(int i = st[j]; i < st[j + 1]; ++i) {
      belong[i] = j;
    }
  }
  for(int i = 1; i <= n; ++i) {
    if(v[i] != belong[i]) {
      bad[v[i]][belong[i]].push_back(i);
    }
  }

  for(int i = 1; i <= 3; ++i) {
    for(int j = i + 1; j <= 3; ++j) {
      one(i, j);
    }
  }

  two(1, 2, 3);
  two(1, 3, 2);

  ofstream out("egipt.out");
  out << swaps.size() << "\n";
  for(const auto& i: swaps) {
    out << i.first << " " << i.second << "\n";
  }
  out.close();

  return 0;
}
