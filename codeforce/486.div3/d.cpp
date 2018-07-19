#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    int seq[N];
    for(int i = 0; i < N; i++)
        cin >> seq[i];
    sort(seq, seq + N);
    
    set<int>pot;
    int i = 0;
    //pot.insert(1);
    for(int j = 2 ; j <= 200000; j = j*2)
    {
        pot.insert(j);
    }



    set<int>tmp;
    set<int>maxx;
    for(int i = 0; i < N; i++)
    { 
        for(int j = i + 1; j < N; j++)
        {
            //cout << "seq[i] :" << seq[i] << " seq[j]: " << seq[j] << endl << "num: " << seq[j] - seq[i] << endl; 
            if(pot.count(seq[j] - seq[i])  != 0)
            {
                tmp.insert(seq[i]);
                tmp.insert(seq[j]);
            }
        }
        if(tmp.size() > maxx.size()) maxx = tmp;
        tmp.clear();
    }

    if(maxx.size() == 0)
    {
        for(int i = N; i > 0; i--)
            if(pot.count(seq[i]) != 0)
            {
                maxx.insert(seq[i]);
                break;
            }
    }
    set<int>::iterator it2;
    cout << maxx.size() << endl;
    for(set<int>::iterator it = maxx.begin(); it != maxx.end(); ++it)
    {
        cout << *it;
        it2 = it;
        ++it2;
        if(it2 != maxx.end()) cout << " ";
    }
    cout << endl;
    
    /*for(set<int>::iterator it = pot.begin(); it != pot.end(); ++it)
        cout << *it << " ";
    cout << endl;*/
    return 0;
}

