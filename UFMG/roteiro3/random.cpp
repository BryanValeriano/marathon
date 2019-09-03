#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(false);
    srand(time(0));  // Initialize random number generator.
    ofstream myfile;
    myfile.open("rf3.txt");
    int r;
    for(int i = 0; i < 10e3; i++)
    {
        r = (rand() % 100000);
        myfile << r << " ";
    }
    myfile << endl;
    for(int i = 0; i < 10e3; i++)
    {
        myfile << 1 << " ";
    }
    myfile.close();
    
    return 0;
}

