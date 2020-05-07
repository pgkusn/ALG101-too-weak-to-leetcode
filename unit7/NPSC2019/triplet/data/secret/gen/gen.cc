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
    const vector<int>& a,
		const vector<int>& b,
		const vector<int>& c) {
  const string& name_in = "./../" + tag + "-" + intToString(id) + ".in";
  const string& name_ans = "./../" + tag + "-" + intToString(id) + ".ans";
  FILE *fp = fopen(name_in.c_str(), "w");
  fprintf(fp, "%d\n", n);
  for (int i = 0; i < n; i++) {
    fprintf(fp, "%d%c", a[i], " \n"[i == n - 1]);
  }
  for (int i = 0; i < n; i++) {
    fprintf(fp, "%d%c", b[i], " \n"[i == n - 1]);
  }
  for (int i = 0; i < n; i++) {
    fprintf(fp, "%d%c", c[i], " \n"[i == n - 1]);
  }
  fclose(fp);

  char order[512];
  sprintf(order, "./../../../submissions/accepted/a.out < %s > %s", name_in.c_str(), name_ans.c_str());
  system(order);
}

void Build() {
  {
    int id = 0;
    const int n = 100000;
    vector<int> a;
    vector<int> b;
    vector<int> c;
    for (int i = 0; i < n; i++) {
      a.push_back(1000000000);
      b.push_back(1000000000);
      c.push_back(1000000000);
    }
    saveData("max_answer", ++id, n, a, b, c);
  }
  {
    int id = 0;
    const int n = 100000;
    for (int times = 0; times < 10; times++) {
      vector<int> a, b, c;
      for (int i = 0; i < n; i++) {
        a.push_back(RandInt(1, 1000000000));
        b.push_back(RandInt(1, 1000000000));
        c.push_back(RandInt(1, 1000000000));
      }
      saveData("random", ++id, n, a, b, c);
    }
  }
  {
    int id = 0;
    const int n = 100000;
    for (int times = 0; times < 10; times++) {
      vector<int> perm;
      vector<int> a, b, c;
      int now = 1000000000;
      while (perm.size() < 3 * n) {
        perm.push_back(now);
        now--;
      }
      shuffle(perm.begin(), perm.end());
      for (int i = 0; i < 3 * n; i++) {
        if (i < n) {
          a.push_back(perm[i]);
        } else if (i < 2 * n) {
          b.push_back(perm[i]);
        } else {
          c.push_back(perm[i]);
        }
      }
      saveData("permutation", ++id, n, a, b, c);
    }
  }
}

int main(int argc, char** argv) {
  registerGen(argc, argv, 1);
  Build();
  return 0;
}
