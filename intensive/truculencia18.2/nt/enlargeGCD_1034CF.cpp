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

const int T = 5e3 + 100;
const int N = 1e7 + 5e6 + 10;
bitset<T> crivo;
int cont[N];
vector<int> primes;

void gen() {
    for(int i = 2; i < T; i++) {
        if(crivo[i] == false) {
            primes.pb(i);
            for(int j = i+i; j < T; j += i) crivo[j] = true;
        }
    }
}

void decop(int x) {
    int i = 0;
    cont[x]++;
    while(i < primes.size() and primes[i] * primes[i] <= x) {
        if(x % primes[i] == 0 and x != primes[i])  cont[primes[i]]++;
        while(x % primes[i] == 0) { 
            x /= primes[i];
            if(x != primes[i]) cont[x]++;
        }
        i++;
    }
}

int main() {
    int n; scanf("%d", &n);
    int x;
    gen();

    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        decop(x);
    }

    int maxi = 0;
    int best = 0;

    //for(int i = 0; i < N; i++) if(cont[i] == n and i > best) best = i; 

    for(int i = 0; i < N; i++) 
        if(cont[i] < n and cont[i] > maxi and i > best) maxi = cont[i];

    printf("%d\n", maxi != 0? n-maxi : -1); 
    return 0;
}

