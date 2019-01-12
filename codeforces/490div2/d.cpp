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
const int T = 2e5 + 10;
bool probs[T];
int n, m;

vii nums;


bool cmp(ii &a, ii &b) {
    if(a.se != b.se) return a.se < b.se;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int cada = n / (n/m);
    int x;
    for(int i = 0; i < n; i++) {
        cin >> x;
        nums.eb(x, x%m);
    sort(nums.begin(), nums.end(), cmp);


    int rest = 0;
    while(rest <= n/m) {
        for(int iter = 1; iter <= cada; iter++) {
            
    
    

    return 0;
}

