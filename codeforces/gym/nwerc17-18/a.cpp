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

const int T = 15;
int aux[T];
int qtd[T];
vector<int> v;
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> aux[i];
        if(!i) v.pb(aux[i]), qtd[aux[i]]++;
        else if(i) if(aux[i] != aux[i-1]) v.pb(aux[i]), qtd[aux[i]]++;
    }

    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v.size(); j++) {
            if(!qtd[i] or !qtd[j]) continue;
            if(qtd[i] == 1) dp[i] = max(dp[i],dp[j]+(j == p+1));
            else dp[i] = max(dp[i],dp[j]+




    return 0;
}

