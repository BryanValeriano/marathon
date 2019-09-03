#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int a; 
    int b;
    int j = 0;

    cin >> n >> a >> b;

    if((a > (n/2) && b <= (n/2)) || (a <= (n/2) && b > (n/2)))
    {
        cout << "Final!" << endl;
        return 0;
    }
        
    while(a != b)
    {
        if(a % 2 == 0) a = a/2;
        else a = (a + 1)/2;

        if(b % 2 == 0) b = b/2;
        else b = (b + 1)/2;
        
        j++;
    }

    cout << j << endl;

    return 0;
}
