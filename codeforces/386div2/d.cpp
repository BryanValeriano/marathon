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
    int n,k,a,b;
    vector<char> ans;
    cin >> n >> k >> a >> b;

    int i = 0;
    int last = -1;
    char l = 'X';
    while(i < n and i != last) {
        int rep = 0;
        bool flag = true;
        last = i;


        while(l != 'B' and b > a and rep < k and i < n) ans.pb('B'), b--, rep++, i++, flag = false;
        while(l != 'G' and a > b and rep < k and i < n) ans.pb('G'), a--, rep++, i++, flag = false;

        if(ans.size()) l = *ans.rbegin();
        
        if(a == b) {
            flag = false;
            if(l == 'B')
                while(b) ans.pb('G'), ans.pb('B'), b--, i += 2;
            else
                while(a) ans.pb('B'), ans.pb('G'), a--, i += 2;
        }
        
        if(flag) {
            if(l == 'B' and a) ans.pb('G'), a--, i++;
            if(l == 'G' and b) ans .pb('B'), b--, i++;
        }

        if(ans.size()) l = *ans.rbegin();
    }

    if(ans.size() == n) { 
        for(auto x : ans) cout << x;
        cout << endl;
    } else cout << "NO" << endl;

    return 0;
}

