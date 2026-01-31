#include <algorithm>
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

class Solution {
public:
  string removeNegativeClose(string &s, char positive, char negative) {
    string t;
    int balance = 0;
    for (char c : s) {
      if (c == positive)
        balance++;
      else if (c == negative)
        balance--;
      if (balance < 0) {
        balance = 0;
        continue;
      }
      t += c;
    }
    return t;
  }

  string minRemoveToMakeValid(string s) {
    s = removeNegativeClose(s, '(', ')');
    reverse(s.begin(), s.end());
    s = removeNegativeClose(s, ')', '(');
    reverse(s.begin(), s.end());
    return s;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  Solution *solution = new Solution();
  string s = "lee(t(c)o)de)";
  cout << solution->minRemoveToMakeValid(s) << endl;
  return 0;
}
