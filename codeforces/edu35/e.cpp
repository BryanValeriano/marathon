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

const int T = 2e5 + 5;
int stk[T];
int a[T];
int b[T];
int onde[T];
int n, k;

void reverse(int l, int r) {
    for(int i = l; i <= r; i++) 
        onde[i] = a[r-(i-l)];

    for(int i = l; i <= r; i++)
        a[i] = onde[i];
}

int main (void){
    ios::sync_with_stdio(false);
    cin >> n >> k;

    for(int i = 0; i < k; i++) {
        cin >> a[i];
        onde[a[i]] = 1;
    }

    int bus = 1;
    int pt = 0;
    int sz = 0;

    while(pt < k) {
        if(onde[bus] <= 1) {
            if(a[pt] == bus) { bus++; pt++; continue; }
            onde[a[pt]] = 2;
            stk[++sz] = a[pt++];
        } else {
            if(sz and stk[sz] == bus) { bus++; sz--; }
            else { cout << -1 << endl; return 0; }
        }
    }


    while(bus <= n) {
        if(onde[bus] == 0) { a[pt++] = bus++; continue; }
        else {
            if(sz and stk[sz] == bus) { bus++; sz--; }
            else { cout << -1 << endl; return 0; }
        }
    }

    int l = k;

    for(int j = k+1; j < n; j++) 
        if(a[j] != a[j-1]+1) reverse(l,j-1), l = j; 
    reverse(l,n-1);

    for(int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;


    return 0;
}

