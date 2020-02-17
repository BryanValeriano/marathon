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

const int T = 2e5 + 5;
int v1[T];
int v2[T];
int aux[T];
int n;
string s;

bool cmp(ii &a, ii &b) {
    if(a.fi != b.fi) return a.fi < b.fi;
    return a.se > b.se;
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n >> s;

        if(n == 1) {
            cout << 1 << endl << 1 << endl;
            continue;
        }


        priority_queue<ii,vii, greater<ii>> pq;
        priority_queue<ii,vii, greater<ii>> pq2;

        vector<ii> pqq;
        vector<ii> pqq2;

        aux[0] = (s[0] == '>');
        if(aux[0]) pq.emplace(aux[0],0), pqq.eb(aux[0],0);

        for(int i = 1; i < n-1; i++) {
            if(s[i] == '>' and s[i] == s[i-1]) aux[i] = aux[i-1]+1;
            else aux[i] = (s[i] == '>');
            if(aux[i]) pq.emplace(aux[i],i), pqq.eb(aux[i],i);
        }

        aux[n-2] = (s[n-2] == '<');
        if(aux[n-2]) pq2.emplace(aux[n-2],n-2), pqq2.eb(aux[n-2],n-2);

        for(int i = n-3; i >= 0; i--) {
            if(s[i] == '<' and s[i] == s[i+1]) aux[i] = aux[i+1]+1;
            else aux[i] = (s[i] == '<');
            if(aux[i]) pq2.emplace(aux[i],i), pqq2.eb(aux[i],i);
        }

        if(s[n-2] == '<') pq.emplace(1,n-1), pqq.eb(1,n-1);
        else pq2.emplace(1,n-1), pqq2.eb(1,n-1);


        int ini1 = n;
        int ini2 = n;

        sort(pqq.begin(), pqq.end(), cmp);
        sort(pqq2.begin(), pqq2.end(), cmp);

        for(int i = 0; i < pqq.size(); i++) v2[pqq[i].se] = ini2--;
        for(int i = 0; i < pqq2.size(); i++) v2[pqq2[i].se] = ini2--;

        while(pq.size()) {
            ii at = pq.top();
            pq.pop();
            v1[at.se] = ini1--;
        }

        while(pq2.size()) {
            ii at = pq2.top();
            pq2.pop();
            v1[at.se] = ini1--;
        }


        for(int i = 0; i < n; i++) cout << v2[i] << " ";
        cout << endl;
        for(int i = 0; i < n; i++) cout << v1[i] << " ";
        cout << endl;

    }

    return 0;
}

