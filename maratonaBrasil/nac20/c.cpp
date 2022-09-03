#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 1e5+5;

struct maxqueue {
  int n;
  int next;
  deque<ii> q;
  maxqueue(int n) : n(n), next(0) {}
  void push(ll x) {
    while (!q.empty() and q.back().first < x) q.pop_back();
    if (!q.empty() and next - q[0].second >= n) q.pop_front();
    q.emplace_back(x, next++);
  }
  ii getMax() {
    return q[0];
  }
};

int kadane(vector<ll> v) {
  int n = v.size();
  maxqueue mq(n);
  int l, m = 0;
  for (int i = 0;i < 2;i++) {
    for (int j = 0;j < n;j++) {
      mq.push(v[j]);
      auto [s, pos] = mq.getMax();
      if (m < s) {
        m = s;
        l = pos;
      }
    }
  }/*@*/
  //cerr << m << " " << l << endl;/*@*/
  return l%n;
}

ll solve(int inicio, vector<ll> v) {
    stack<ii> bag;

    int cont = v.size();
    ll tempo = 0;
    int i = inicio;

    ll ans = 0;

    //cerr << inicio << endl;
    //for(int i = 0; i < v.size(); i++)
    //    cerr << v[i] << " ";
    //cerr << endl;

    while(tempo < cont) {
        if(v[i] > 0) bag.emplace(v[i], tempo);
        while(v[i] < 0) {
            ii tmp = bag.top();
            bag.pop();
            if(tmp.fi+v[i] <= 0) {
                ans += (tempo-tmp.se)*tmp.fi;
                v[i] += tmp.fi;
            } else {
                ans += (tempo-tmp.se)*(-v[i]);
                tmp.fi += v[i];
                v[i] = 0;
                bag.push(tmp);
            }
        }

        tempo++;
        i++;
        i %= (int)v.size();
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    vector<ll> v(n);
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }

    ll need = sum/n;
    for(int i = 0; i < n; i++) v[i] = v[i]-need;

    int inicio = kadane(v);
    ll ans = solve(inicio, v);

    reverse(v.begin(), v.end());
    int inicio2 = kadane(v);
    ans = min(ans, solve(inicio2, v));


    cout << ans << endl;
    return 0;
}

