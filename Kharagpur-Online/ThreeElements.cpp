/*
ID: tle4ever
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
#define MOD	1000000007
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	int cnt=0;
	while(t--)
	{
		cnt++;
		cout<<"Case "<<cnt<<": ";
		int n;
		cin>>n;
		int ar[n];
		for(int i=0;i<n;++i)
			cin>>ar[i];
		sort(ar,ar+n);
		cout<<(ar[n-1]+ar[n-2]+ar[n-3])<<endl;
	}
	return 0;
}
