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
    ios::sync_with_stdio(false);
    priority_queue<int, vector<int> > par;
    priority_queue<int, vector<int> > impar;
    int sumP = 0;
    int sumI = 0;
    int n,x;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x;
        if(x&1) { sumI += x; impar.push(x); }
        else { sumP += x; par.push(x); }
    }

    bool flag;
    if(par.size() >= impar.size()) flag = true;
    else flag = false;

    while((flag and !par.empty()) or (!flag and !impar.empty())) {
        int at;
        if(flag) { 
            at = par.top();
            par.pop();
            sumP -= at;
        } else {
            at = impar.top();
            impar.pop();
            sumI -= at;
        }
        flag = !flag;
    }
    cout << sumI + sumP << endl;

    return 0;
}

