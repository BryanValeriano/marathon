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
const int T = 102;

int col[T][T];
int lin[T][T];
int mc[T], ml[T];

int main() {
    int tc; scanf("%d", &tc);
    int cont =0;

    while(tc--) {
        int n; scanf("%d", &n);

        int sum = 0, c = 0, l = 0;

        for(int i = 0; i < n; i++) {
            mc[i] = ml[i] = 0;
            for(int j = 0; j < n; j++)
                col[i][j] = lin[i][j] = 0;
        }

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++) {
                int x; scanf("%d", &x);

                if(i == j) sum += x;
                col[j][x-1]++;
                lin[i][x-1]++;
                if(mc[j] == 1 and col[j][x-1] == 2) c++;
                if(ml[i] == 1 and lin[i][x-1] == 2) l++;
                mc[j] = max(mc[j],col[j][x-1]);
                ml[i] = max(ml[i],lin[i][x-1]);
            }

        printf("Case #%d: %d %d %d\n", ++cont, sum, l, c);
    }
    return 0;
}

