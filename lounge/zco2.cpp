#include <bits/stdc++.h>

using namespace std ;

#define all(x) x.begin(),x.end()
#define pb push_back
#define DEBUG(x) cout << '>' << #x << ':' << x << endl
#define mp make_pair
#define PI acos(-1)
#define MAXN 66000

const int INF = 1<<29;
typedef long long ll;
typedef pair < int , int > pii;
 
ll a[MAXN] , k;
 
int main()
{
    int n  ,l , r , m, count = 0;

    scanf("%d %lld" , &n , &k);

    for(int i = 0 ;i<n ;i++) 
        scanf("%lld" , a+i);

    sort(a , a+n);

    for(int i = 0; i < n; i++) {
        l = i , r = n;
        while(r - l > 1) {
            m = (r+l) >> 1;

            if(a[m] - a[i] >= k) r = m;
            else l = m ;
        }
        count += (n-r);
    }
    
    printf("%d\n" , count) ;
    
    return 0 ;

}
