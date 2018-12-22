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
const int T = 1e7 + 10;
int n;
bitset<T> check2;
int v[T];
int aux[T];

void construct(int ini, int ele, bool flag) {
    if(ini == n) return;
    int i;

    for(i = ele; i < T; i++) 
        if(check2[i] == false) break;
    aux[ini] = i;

    for(int j = i; j < T; j += i)
        check2.set(j,true);

    int j;
    for(j = (flag? 2 : i) ; j < T; j++)
        if(check2[j] == false) {
            ele = j;
            break;
        }
    construct(ini + 1, ele, false);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        aux[i] = v[i];
    }
    int maxi = 0;
    for(int i = 0; i < n; i++) {
        if(check2[v[i]] == true) {
            construct(i, v[i], true);
            break;
        } else { 
            for(int j = v[i]; j < T; j += v[i]) {
                check2.set(j, true);
            }
        }
    }
    for(int i = 0; i < n; i++) cout << aux[i] << " ";
    cout << endl;
    return 0;
}

