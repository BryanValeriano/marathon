#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
 
int main()
{
    string a; string b; string tmp1 , tmp2;
    cin >> a >> b;
    tmp1 = min(a, b);
    tmp2 = max(a, b);
    int j;

    for(int i = tmp1.length() - 1; i >= 0; i--)
    {
        j = 0;
        if(tmp1[i] == tmp2[tmp2.length() - 1 - j])
        {
            tmp1.pop_back();
            tmp2.pop_back();
            j++;
        }
        else break;
    }
    cout << tmp1.length() + tmp2.length() << endl;

    return 0;
}

