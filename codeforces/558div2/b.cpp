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

const int T = 1e5 + 3;
int qtd[T];
int track[T];
int n;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    int x; 
    int ans = 0;
    int dig = 0;
    int last = 0;
    int tracklast = 0;
    int qtdtracklast = 0;

    for(int i = 0; i < n; i++) {
        cin >> x;
        if(track[x]) qtd[track[x]]--;
        else dig++;

        track[x]++;
        qtd[track[x]]++;

        if((qtd[track[x]] == dig-1 and (qtd[1] == 1 or qtd[track[x]+1] == 1))
            or (track[x] == 1 and (qtdtracklast == dig-1))
            or (qtd[track[x]] == 1 and tracklast+1 == track[x] and qtdtracklast == dig)) {
            ans = i+1;
        }

        last = x;
        tracklast = track[x];
        qtdtracklast = qtd[track[x]];
    }

    cout << ans << endl;
    return 0;
}

