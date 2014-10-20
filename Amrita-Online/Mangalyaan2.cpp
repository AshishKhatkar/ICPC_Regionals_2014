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
	while(t--)
	{
		int n,p,tmp;
		cin>>n>>p;
		int ans=0;
		for(int i=0;i<n;++i)
		{
			cin>>tmp;
			if(tmp>=p)
				ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
