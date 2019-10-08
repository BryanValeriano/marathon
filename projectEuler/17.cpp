#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
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

string um = "onetwotrheefourfivesixseveneightnine";
string d = "teneleventwelvethirteenfourteenfifteensixteenseventeeneighteennineteen";
string c = "twentythirtyfortyfiftysixtyseventyeightyninety";
string e = "and";
string f = "hundredand";
string g = "onethousand";

int main() {
    ios_base::sync_with_stdio(false);
    int uns = um.size();
    int dois = d.size();
    int quaseCem = 8*uns + c.size()*10;
    int maisCem = g.size() + f.size()*901 - e.size()*9 + (uns+dois+quaseCem)*9;
    maisCem += uns*100;
    cout << maisCem << endl;
    cout << maisCem+uns+dois+quaseCem << endl;

    return 0;
}

