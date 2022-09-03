#include <bits/stdc++.h>
using namespace std;

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

int main() {
    ios_base::sync_with_stdio(false);
    int n,k,q;

    cin >> n >> k >> q;
    string x; cin >> x;
    reverse(x.begin(), x.end());

    string s; cin >> s;
    string ns; ns = s;
    //cout << s << endl;

    while(q--) {

        string t;
        for(int i = -k; i <= k; i++) {
            int j = (i+n)%n;
            t += s[j];
        }
        ll mask = 0;
        int tmp = 0;
        for(int i = t.size()-1; i >= 0; i--) {
            mask += (t[i]=='1'?(1<<tmp):0);
            tmp++;
        }

        //cout << t << endl;
        //cout << "começou com " << mask << endl;

        for(int i = 0; i < n; i++) {
            ns[i] = x[mask];
            int fim = (i+k) % n;
            int fim2 = (fim+1)%n;

            mask <<= 1;
            mask %= 1<<(2*k+1);
            mask += (s[fim2] == '1');

            //cout << (i+1)%n << ", mask: " << mask << endl;
        }
        swap(ns,s);
        //cout << s << endl;
        //cout << " ------------\n";
    }

    cout << s << endl;
    return 0;
}

