#include <bits/stdc++.h>
#include "srm502-d2-500.cpp"

using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
//const int INF = 0x3f3f3f3f;


int main() {
    ios::sync_with_stdio(false);
    vector<string> s;
    s = {"8542861", "1954", "6", "523", "000000000", "5426", "8"};

    TheLotteryBothDivs kk = TheLotteryBothDivs();
    cout << fixed << setprecision(9);
    cout << kk.find(s) << endl;

    return 0;
}

