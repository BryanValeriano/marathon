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
int a,b,c,d;

ii test() {
    // a/b c/d
    int b1 = (b*d)/__gcd(b,d);
    int d1 = b1;
    int a1 = (b1/b) * a;
    int c1 = (d1/d) * c;
    int cima1 = a1 - c1;
    cout << a1 << " " << c1 << " ";
    int baixo1 = (a*c)/ __gcd(a,c);
    cout << baixo1 << endl;
    double um = double(cima1)/double(baixo1);

    // b/a d/c
    a1 = (a*c)/__gcd(a,c);
    c1 = a1;
    b1 = (a1/a) * b;
    d1 = (c1/c) * d; 
    int cima2 = b1 - d1;
    cout << b1 << " " << d1 << " ";
    int baixo2 = (b*d)/__gcd(b,d); 
    cout << baixo2 << endl;
    double dois = double(cima2)/double(baixo2);

    // a/b d/c
    b1 = (b*c)/__gcd(b,c);
    c1 = b1;
    a1 = (b1/b) * a;
    d1 = (c1/c) * d;
    int cima3 = abs(a - d);
    int baixo3 = b1;
    double tres = double(cima3)/double(baixo3);

    // b/a c/d
    a1 = (a*d)/__gcd(a,d);
    d1 = a1;
    b1 = (a1/a) * b;
    c1 = (d1/d) * d;
    int cima4 = abs(b - d);
    int baixo4 = a1;
    double quatro = double(cima4)/double(baixo4);
    
    
    cout << cima1 << "/" << baixo1 << " " << um << endl;
    cout << cima2 << "/" << baixo2 << " " << dois << endl;
    //cout << cima3 << "/" << baixo3 << endl;
    //cout << cima4 << "/" << baixo4 << endl;

    if(um > 0 and (um <= dois or dois < 0) ) return ii(cima1,baixo1);
    else return ii(cima2,baixo2);

    //if(cima1 >= 0 and um <= dois and um <= tres and um <= quatro)
    //    return ii(cima1, baixo1);
    //if(cima2 >= 0 and dois <= um and dois <= tres and dois <= quatro)
    //    return ii(cima2, baixo2);
    //if(cima3 >= 0 and tres <= um and tres <= dois and tres <= quatro)
    //    return ii(cima3, baixo3);
    //if(cima4 >= 0 and quatro <= um and quatro <= dois and quatro <= tres)
    //    return ii(cima4,baixo4);
    return ii(0,0);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> a >> b >> c >> d;
    //reduce
    if(a % b == 0) { b /= b; a /= b; }   
    if(b % a == 0) { b /= a; a /= a; }   
    if(c % d == 0) { c /= d; d /= d; }
    if(d % c == 0) { c /= c; d /= c; }
    ii ans = test();
    cout << ans.fi << "/" << ans.se << endl; 
    
    return 0;
}

