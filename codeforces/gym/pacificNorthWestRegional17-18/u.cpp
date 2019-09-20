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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

double ok[7];

int main() {
    ios_base::sync_with_stdio(false);
    double tot = 0;
    double maxi = 0;
    int pos = 0;
    for(int i = 1; i <= 6; i++) {
        cin >> ok[i];
        tot += i*ok[i];
        if(ok[i] > maxi) {
            maxi = ok[i];
            pos = i;
        }
    }
    double diff = 3.5 - tot;
    cout << fixed << setprecision(3) << abs(diff/maxi) << endl;
    return 0;
}

