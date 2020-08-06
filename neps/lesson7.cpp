#include <bits/stdc++.h>

using namespace std;

int main()
{
	int P, R;

	cin >> P >> R;

	if(P == 0)
	{
		cout << "C" << endl;
	}
	else if(P ==  R and R == 1)
	{
		cout << "A" << endl;
	}else{
		cout << "B" << endl;
	}

	return 0;	
}
