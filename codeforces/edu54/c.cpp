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
double permi = 0.000001;

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        double d; cin >> d;
        double l = 0;
        double r = 2;
        double a;;
        double b;
        if(d == 0) { cout << setprecision(11) << "Y " << l << " " << l << endl; continue; }
        for(int ta = 0; ta <= 500; ta++) {
            b = (l+r)/2;
            a = d - b;
            if(a*b > d + permi) r = b - permi;
            else if(a*b < d - permi) l = b + permi; 
        }
        if(std::abs(a*b - d) < permi)    
            cout << setprecision(11) << "Y " << a << " " << b << endl;
        else 
            cout << "N " << endl;
    }

    return 0;
}

