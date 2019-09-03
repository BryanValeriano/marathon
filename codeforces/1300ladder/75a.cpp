#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
    string s1, s2, s3, s4;
    cin >> s1 >> s2;
    int a, b, c, d;
    a = stoi(s1);
    b = stoi(s2);
    a = a + b;

    for(int i = 0; i < s1.size(); i++) 
        if(s1[i] != '0') s3 += s1[i];

    for(int i = 0; i < s2.size(); i++) 
        if(s2[i] != '0') s4 += s2[i];

    s1 = to_string(a);
    s2 = "";

    for(int i = 0; i < s1.size(); i++) 
        if(s1[i] != '0') s2 += s1[i];
    
    b = stoi(s2);

    c = stoi(s3);
    d = stoi(s4);
    
    cout << (b == c + d? "YES" : "NO") << endl;
    return 0;
}

