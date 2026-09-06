#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define cc(x) cout << #x << " = " << x << endl
#define ok cout << "ok" << endl
#define endl '\n'

typedef long long ll;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

bool isSubstr(string substr, string text, vector<bool> &check) {
  int a = 0;
  int b = 0;
  for (int i = 0; i < text.length(); i++) {
    if (text[i] == substr[a]) {
      a++;
      check[i] = true;
    }
    if (a == substr.length())
      return true;
  }
  return false;
}

void buildBag(string text, vector<int> &bag) {
  for (int i = 0; i < text.length(); i++) {
    bag[text[i] - 'a']++;
  }
}

bool hasInBag(string text, vector<bool> &check, vector<int> &bag) {
  for (int i = 0; i < text.length(); i++) {
    if (check[i])
      continue;
    bag[text[i] - 'a']--;
    if (bag[text[i] - 'a'] < 0) {
      return false;
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  int tc;
  cin >> tc;
  while (tc--) {
    string s, t, p;
    cin >> s >> t >> p;
    vector<bool> check(t.size(), false);
    vector<int> bag(28, 0);

    if (!isSubstr(s, t, check)) {
      cout << "NO" << endl;
      continue;
    }

    buildBag(p, bag);
    if (!hasInBag(t, check, bag)) {
      cout << "NO" << endl;
      continue;
    }
    cout << "YES" << endl;
  }

  return 0;
}
