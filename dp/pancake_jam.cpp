#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
int flip;
 
vector<int> process(string tmp);
int solve(vector<int>row);

int main()
{
    int TC;
    int cont = 0;
    scanf("%d\n", &TC);
    while(TC--)
    {
        vector<int>row;
        string tmp;
        getline(cin, tmp);
        row = process(tmp);   

        int flips = solve(row);
        cout << "Case #" << ++cont << ": ";
        if(flips >= 0)cout << flips << endl;
        else cout << "IMPOSSIBLE" << endl;
    }
    
    return 0;
}

int solve(vector<int>row)
{
    int i = 0;
    int flips = 0;
    while(i < row.size() - flip + 1)
    {
        if(row[i] == 1)
        {
            for(int j = i; j < i + flip; j++)
            {
                row[j] = 1 - row[j];
            }
            flips++;
        }
        i++;
    }

    for(int i; i < row.size(); i++)
    {   
        if(row[i] == 1) return -1;
    }
    return flips;
}

vector<int> process(string tmp)
{
    vector<int>row;
    int cont = 0;
    string flipp;
    for(int i = 0; i < tmp.size(); i++)
    {
        if(tmp[i] == ' ')
        {
            while(i < tmp.size())
            {
                flipp.reserve(tmp.size() - i);
                flipp[cont] = tmp[i];
                cont++;
                i++;
            }
            string::size_type sz;
            flip = stoi(flipp, &sz);
            break;
        }
        else if(tmp[i] == '+')
            row.pb(0);
        else row.pb(1);
    }
    return row;
}
