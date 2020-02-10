#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
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
const int T = 4e3 + 100;
int wi[T];
int dj[T];
int m,n,w,h;

priority_queue<ii,vii> pq;
vector<int> ans[T];
vii volta[T];

void erro(int x) {
    cout << x << endl;
    exit(0);
}

bool confirm() {
    for(int i = n; i < T; i++)
        if(volta[i].size()) return 0;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> m >> n >> w >> h;

    for(int i = 0; i < m; i++) {
        cin >> wi[i];
        pq.emplace(wi[i]/w,i+1);
    }

    for(int i = 1; i <= n; i++) cin >> dj[i];

    for(int i = 1; i <= n; i++) {

        while(volta[i].size()) {
            ii at = volta[i].back();
            volta[i].pop_back();
            pq.emplace(at);
        }

        while(dj[i] > 0 and !pq.empty()) {
            ii at = pq.top();
            ans[at.se].pb(i);
            pq.pop();
            for(int j = i; j <= i+w-1; j++) {
                if(j > n) erro(-1);
                if(dj[j]) dj[j]--;
                else erro(-1);
            }
            at.fi--;
            if(at.fi) volta[i+w+h].eb(at);
        }

        if(dj[i]) erro(-1);
    }


    if(!confirm() or pq.size()) erro(-1);

    cout << 1 << endl;
    for(int i = 1; i <= m; i++) {
        for(int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }

    return 0;
}

