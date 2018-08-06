#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(false);
    int x,y;
    cin >> x >> y;

    if(log(y) + log(log(x)) > log(x) + log(log(y))) cout << ">" << endl;
    else if(log(y) + log(log(x)) < log(x) + log(log(y))) cout << "<" << endl;
    else cout << "=" << endl;
    return 0;
}

