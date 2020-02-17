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

class TheLotteryBothDivs {
public:

    bool isPrefix(string a, string b) {
        if(a.size() > b.size()) return false;

        for(int i = 1; i <= a.size(); i++)
            if(a[a.size()-i] != b[b.size()-i])
                return false;

        return true;
    }

    double find(vector<string> goodSuffixes) {
        double size[10];
        double x = 1;
        double ans = 0;
        bool vis[55];

        for(int i = 0; i < 55; i++) vis[i] = true;

        for(int i = 1; i <= 9; i++) {
            size[i] = x/10;
            x /= 10;
        }

        sort(goodSuffixes.begin(), goodSuffixes.end(), [&] (const string &a, const string &b) {return a.size() < b.size();});

        for(int i = 0; i < goodSuffixes.size(); i++)
            for(int j = i+1; j < goodSuffixes.size(); j++)
                if(isPrefix(goodSuffixes[i], goodSuffixes[j]))
                    vis[j] = false;

        for(int i = 0; i < goodSuffixes.size(); i++)
            if(vis[i]) ans += size[goodSuffixes[i].size()];

        return ans;
    }
};

