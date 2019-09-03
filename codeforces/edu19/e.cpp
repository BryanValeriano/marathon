#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

const int T = 1e5 + 5;
const int N = sqrt(T);
int v[T][N+1];
int n;

template<class num> inline void rd(num &x) {
	char c;
	while(isspace(c = getchar()));
	bool neg = false;
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar()))
		x = (x << 3) + (x << 1) + c - '0';
	if(neg) x = -x;
}

int main() {

    rd(n);
    for(int i = 1; i <= n; i++) rd(v[i][0]);

    for(int i = N; i >= 1; i--) {
        for(int j = n; j >= 1; j--) {
            if(j + v[j][0] + i > n) v[j][i] = 1;
            else v[j][i] = v[j + v[j][0] + i][i] + 1;
        }
    }

    int q, a, b;
    rd(q);

    while(q--) {
        rd(a); rd(b);
        int ans = 0;
        if(b > N) while(a <= n) a += v[a][0] + b, ans++;
        else ans = v[a][b];
        printf("%d\n", ans);
    }

    return 0;
}

