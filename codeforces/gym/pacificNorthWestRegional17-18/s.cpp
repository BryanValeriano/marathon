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

const int T = 1e5 + 3;
int v[T];
string s;
int n;


int main() {
    ios_base::sync_with_stdio(false);
    cin >> s;
    n = s.size();
    for(int i = 0; i < n; i++) v[i] = (s[i] == 'B'? 1 : -1);

    int ini = 0;
    int fim = 0;
    int maxi = 1;

    int at = 0;
    int l = 0;

    for(int i = 0; i < n; i++) {
        at += v[i];
        if(at < 0) at = 0, l = i+1;
        if(at > maxi) {
            maxi = at;
            ini = l;
            fim = i;
        }
        v[i] *= -1;
    }

    at = 0;
    l = 0;

    for(int i = 0; i < n; i++) {
        at += v[i];
        if(at < 0) at = 0, l = i+1;
        if(at > maxi) {
            maxi = at;
            ini = l;
            fim = i;
        }
    }

    cout << ini+1 << " " << fim+1 << endl;

    return 0;
}

