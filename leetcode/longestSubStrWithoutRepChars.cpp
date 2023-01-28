#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int main() {
  ios_base::sync_with_stdio(false);
  string s; cin >> s;
  const int T = 200;

  int lastAppear[T];
  memset(lastAppear, -1, sizeof lastAppear);
  int initSubStr = -1;
  int maxSum = 0;

  for(int i = 0; i < s.length(); i++) {
    initSubStr = max(initSubStr, lastAppear[s[i]]);
    maxSum = max(maxSum,i-initSubStr);
    lastAppear[s[i]] = i;
  }

  cout << maxSum << endl;
  return 0;
}

