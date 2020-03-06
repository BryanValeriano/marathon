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
const int lim = 50000;

int v[T];
int n,a,b;

bool Bfirst() {
    v[0] = 1;
    int sum = 1;

    for(int i = 1; i <= b; i++) {
        v[i] = sum+1, sum += v[i];
        if(v[i] > lim or i == n) return 0;
    }
    for(int i = b+1; i <= a+b; i++) {
        v[i] = v[i-1]+1;
        if(v[i] > lim or v[i] > sum or i == n) return 0;
        sum += v[i];
    }

    for(int i = a+b+1; i < n; i++) v[i] = 1;
    return 1;
}

bool Afirst() {
    v[0] = 2;
    v[1] = 2;
    int sum = 4;

    for(int i = 2; i <= a+1; i++) {
        v[i] = v[i-1]+1;
        if(v[i] > lim or v[i] > sum or i == n) return 0;
        sum += v[i];
    }
    for(int i = a+2; i <= a+b+1; i++) {
        v[i] = sum+1, sum += v[i];
        if(v[i] > lim or i == n) return 0;
    }

    for(int i = a+b+2; i < n; i++) v[i] = 1;
    return 1;
}

void print() {
    for(int i = 0; i < n; i++) cout << v[i] << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> a >> b;
    if(n == 1 and (a or b)) { cout << -1 << endl; return 0; }
    if(!Bfirst()) {
        if(!Afirst()) cout << -1 << endl;
        else print();
    } else print();

    return 0;
}

