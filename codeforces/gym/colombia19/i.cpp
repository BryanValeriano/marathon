#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define endl '\n'
#define cc(x) cout <<#x <<" = " <<x <<endl

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main() {

    string s;
    cin >>s;

    string ans = "";
    for(auto at:s) {
        if(at >= '0' and at <= '9') ans += at;
        else break;
    }

    if(ans.size() > 0) cout <<ans <<endl;
    else cout <<-1 <<endl;

    return 0;
}

