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
ll neve[T];
ll temp[T];
ll rest[T];
ll vezes[T];


int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> neve[i];
    for(int i = 1; i <= n; i++) cin >> temp[i];
    for(int i = 1; i <= n; i++) temp[i] += temp[i-1];
    
    for(int i = 1; i <= n; i++) {
        int ini = i;
        int fim = n;
        while(ini <= fim) {
            int meio = (ini+fim)>>1;
            if(temp[meio] - temp[i-1] > neve[i]) fim = meio - 1;
            else ini = meio + 1;
        }
        vezes[i]++; vezes[ini]--;
        rest[ini] += neve[i] - (temp[fim] - temp[i-1]);
    }
    for(int i = 1; i <= n; i++) vezes[i] += vezes[i-1];
    for(int i = 1; i <= n; i++) cout << vezes[i] * (temp[i] - temp[i-1]) + rest[i] << " "; 
    cout << endl;

    return 0;
}

