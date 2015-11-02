#include <stdio.h>
#include <vector>

struct kid {
  int off,
      hall,
      hp;
  int id;
};

const int MAX_N = 4000 + 1;

kid v[MAX_N];
int n;

void remove(int poz) {
  for(int i = poz; i < n; ++i)
    v[i] = v[i + 1];
  --n;
}

void leave(int poz) {
  for(int i = poz; i <= n; ++i) {
    if(v[i].hp >= 0)
      v[i].hp -= v[poz].hall;
  }
  remove(poz);
}

void checkLeavers() {
  int i = 1;
  while(i <= n) {
    if(v[i].hp < 0) {
      leave(i);
    } else {
      ++i;
    }
  }
}

std::vector<int> sol;

void process() {
  if(n < 1)
    return;

  int sub = v[1].off;
  sol.push_back(v[1].id);
  remove(1);
  int i = 1;
  while(i <= n && sub > 0) {
    if(v[i].hp >= 0)
      v[i].hp -= sub;

    ++i;
    --sub;
  }
  checkLeavers();
  process();
}

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i) {
    scanf("%d%d%d", &v[i].off, &v[i].hall, &v[i].hp);
    v[i].id = i;
  }

  process();

  printf("%d\n",(int)sol.size());
  for(int i = 0; i < (int)sol.size(); ++i)
    printf("%d ", sol[i]);
  printf("\n");

  return 0;
}
