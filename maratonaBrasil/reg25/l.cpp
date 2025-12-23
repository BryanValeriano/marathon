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
typedef pair<ll, ll> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
map<string, ii> dic;
vector<pair<string, ii>> dicOrd;

vector<string> getCandidates(vector<string> &test, vector<string> &text,
                             int k) {
  vector<string> candidates;
  string newText;
  for (auto s : text)
    newText += s + " ";

  newText += "# ";

  for (auto s : test) {
    newText += s + " ";
  }

  newText.pop_back();

  return candidates;
}

string solve(vector<string> &candidates) {
  ll maxi = -INF;
  string ans = "*";
  for (auto keyDict : dicOrd) {
    ll dicAns = 0;
    for (auto candidate : candidates) {
      dicAns += dic[keyDict.fi].fi * dic[candidate].fi;
      dicAns += dic[keyDict.fi].se * dic[candidate].se;
    }
    if (dicAns > maxi) {
      maxi = dicAns;
      ans = keyDict.fi;
    }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int x, y;
    cin >> x >> y;
    dic[s] = mk(x, y);
    dicOrd.pb(make_pair(s, make_pair(x, y)));
  }
  int m;
  cin >> m;
  vector<string> text;
  for (int i = 0; i < m; i++) {
    string s;
    cin >> s;
    text.pb(s);
  }
  int q, k;
  cin >> q >> k;
  for (int i = 0; i < q; i++) {
    int z;
    cin >> z;
    vector<string> test;
    vector<string> lastKTest;
    for (int j = 0; j < z; j++) {
      string s;
      cin >> s;
      test.pb(s);
    }
    for (int j = max(0, test.size() - k); j < test.size(); j++) {
      lastKTest.pb(test[j])
    }
    vector<string> candidates;
    while (candidates.size() == 0 && test.size() > 0) {
      candidates = getCandidates(lastKTest, text, k);
    }
    cout << solve(candidates) << endl;
  }

  return 0;
}
