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

const int T = 4e4 + 10;
int v[T];
int aux[T];
int n;

bool can(int x) {
    int ligadoAte = -1;
    for(int i = 0; i < T; i++) {
        if(aux[i] >= 1) ligadoAte = i+x-1;
        if(v[i] and i > ligadoAte) return false;
    }
    return true;
}


int main() {
    ios::sync_with_stdio(false);
    cin >> n; 
    int x, y;

    for(int i = 0; i < n; i++) {
        cin >> x >> y; 
        aux[x]++;
        v[x]++, v[y]--;
    }

    for(int i = 1; i < T; i++) v[i] += v[i-1];

    int l = 0;
    int r = T;

    while(r >= l) {
        int mid = (l+r) >> 1;
        if(can(mid)) r = mid-1;
        else l = mid+1;
    }
    
    cout << l << endl;
    return 0;
}

