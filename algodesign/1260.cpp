#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(false);
    int TC, c, tmp, count;
    vector<int>sales;

    cin >> TC;
    while(TC--)
    {
        cin >> c;
        count = 0;
        for(int i = 0; i < c; i++)
        {
            cin >> tmp;
            sales.pb(tmp);
        }
        for(int i = c - 1; i >= 0; i--)
        {
            for(int j = 0; j < i; j++)
                if(sales[i] >= sales[j])
                    count++;
        }
        cout << count << endl;
        sales.clear();
    }

    
    return 0;
}

