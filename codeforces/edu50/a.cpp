#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

const int INF = 0x3f3f3f3f;
 
int main()
{
    long long int n, k;
    scanf("%lld %lld", &n, &k);
    //cin >> n >> k;
    long long int aux = 0;
    if(k%n) aux = 1;
    long long int tmp = (k/n) + aux;
    printf("%lld\n", tmp);
    //cout << tmp << endl;
    
    return 0;
}

