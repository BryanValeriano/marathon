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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 1e6 + 3;

//string ans;
string p,t;
int pi[T];

void pre() {
    p += '#';
    pi[0] = pi[1] = 0;
    for(int i = 2; i <= p.size(); i++) {
        pi[i] = pi[i-1];
        while(pi[i] > 0 and p[pi[i]] != p[i-1]) pi[i] = pi[pi[i]];
        if(p[pi[i]] == p[i-1]) pi[i]++;
    }
}

void kmp() {
    pre();
    p.pop_back();

    int k = 0;
    int m = p.size();

    for(int i = max(0, (int)t.size() - m); i < t.size(); i++) {
        while(k > 0 and p[k] != t[i]) k = pi[k];
        if(p[k] == t[i]) k++;
    }

    for(int i = k; i < p.size(); i++) t += p[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    cin >> t;

    for(int i = 1; i < n; i++) {
        cin >> p;
        kmp();
    }

    cout << t << endl;
    return 0;
}

