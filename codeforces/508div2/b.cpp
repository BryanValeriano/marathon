#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f;
 
int main()
{
    int n; cin >> n;
    ll sum = 0;
    for(int i = 1; i <= n; i++) 
        sum += i;
    int anterior = 0;
    ll s1 = INF+3;
    for(int i = 2; i <= n; i++) {
        sum -= i; 
        sum += anterior;
        if(sum % i == 0) {
            s1 = i;
            break;
        }
        anterior = i;
    }

    if(s1 < INF) {
        cout << "Yes" << endl;
        cout << 1 << " " << s1 << endl;
        cout << n - 1 << " ";
        for(int i = 1; i < s1; i++) 
            cout << i << " ";
        for(int i = s1 + 1; i <= n; i++) 
            cout << i << " ";
        cout << endl;
    }
    else cout << "No" << endl;
    
    return 0;
}

