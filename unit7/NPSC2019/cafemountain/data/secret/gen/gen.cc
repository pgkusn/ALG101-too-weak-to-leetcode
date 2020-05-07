/// Author: Yen-Jen Wang
#include "testlib.h"

#include <bits/stdc++.h>

using namespace std;

int RandInt(int lower_bound, int upper_bound) {
  return rnd.next(lower_bound, upper_bound);
}

string intToString(int x) {
	string res = "";
  if (x == 0) {
    res = "0";
  } else {
    while (x) {
      res += (char)(x % 10 + '0');
      x /= 10;
    }
  }
  reverse(res.begin(), res.end());
  return res;
}

void saveData(const string& tag, 
    const int& id,
    const int& n,
    const int& k,
    const vector<int>& a) {
  const string& name_in = "./../" + tag + "-" + intToString(id) + ".in";
  const string& name_ans = "./../" + tag + "-" + intToString(id) + ".ans";
  FILE *fp = fopen(name_in.c_str(), "w");
  fprintf(fp, "%d\n", n);
  vector<int> cs;
  for (int i = 0; i < k; i++) {
    cs.push_back(0);
  }
  for (int i = 0; i < n - k; i++) {
    cs.push_back(1);
  }
  shuffle(cs.begin(), cs.end());
  for (int i = 0; i < n; i++) {
    fprintf(fp, "%d %d\n", cs[i], a[i]);
  }
  fclose(fp);

  char order[512];
  sprintf(order, "./../../../submissions/accepted/a.out < %s > %s", name_in.c_str(), name_ans.c_str());
  system(order);
}

void Build() {
  const int n = 200000;
  const vector<int> ks = {0, 1, 2, 10, 100, 1000, 10000, 20000, 50000, 99999};
  {
    int id = 0;
    for (int times = 0; times < 10; times++) {
      int k = ks[times];
      vector<int> a;
      for (int i = 0; i < n / 2; i++) {
        a.push_back(1000000000);
        a.push_back(-1000000000);
      }
      saveData("max_answer", ++id, n, k, a);
    }
  }
  {
    int id = 0;
    for (int times = 0; times < 30; times++) {
      vector<int> a;
      int k = ks[times % 10];
      for (int i = 0; i < n; i++) {
        a.push_back(RandInt(-1000000000, 1000000000));
      }
      saveData("random", ++id, n, k, a);
    }
  }
  {
    int id = 0;
    for (int times = 0; times < 30; times++) {
      int k = ks[times % 10];
      vector<int> a;
      vector<int> perm;
      int now = 1000000000;
      while (perm.size() < n) {
        perm.push_back(now);
        now--;
      }
      shuffle(perm.begin(), perm.end());
      for (int i = 0; i < n; i++) {
        a.push_back(perm[i]);
      }
      saveData("permutation", ++id, n, k, a);
    }
  }
}

int main(int argc, char** argv) {
  registerGen(argc, argv, 1);
  Build();
  return 0;
}
