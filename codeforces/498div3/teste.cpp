#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n;
	cin>>n;
	long long a[n];
	for(long long i=0;i<n;i++)
		cin>>a[i];
		
	long long i=0,j=n-1,left=0,right=0,ans=0;
	
	while(i<=j)
	{
		if(left<right)left+=a[i++]; else right+=a[j--];
		if(left==right)
			ans=max(left,right);
	}
	cout<<ans<<endl;
	return 0;
}
