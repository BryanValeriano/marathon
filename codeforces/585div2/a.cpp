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
 
int main() {
    ios_base::sync_with_stdio(false);
    int k1,k2,a1,a2,n;
    cin >> a1 >> a2 >> k1 >> k2 >> n;

    priority_queue<int,vector<int>,greater<int>>pq;
    priority_queue<int,vector<int>>pq2;
    for(int i = 0; i < a1; i++) pq.push(k1), pq2.push(k1);
    for(int i = 0; i < a2; i++) pq.push(k2), pq2.push(k2);

    int mini = 0;
    int maxi = 0;
    int nn = n;

    while(!pq.empty() and nn) {
        int at = pq.top();
        pq.pop();
        at--;
        if(at) pq.push(at);
        else maxi++;
        nn--;
    }

    nn = n;
    
    while(!pq2.empty() and nn) {
        int at = pq2.top();
        pq2.pop();
        at--;
        if(at) pq2.push(at);
        else mini++;
        nn--;
    }

    cout << mini << " " << maxi << endl;

    return 0;
}

