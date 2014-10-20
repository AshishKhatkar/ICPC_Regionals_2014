/*
ID: tle4ever
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
#define MOD	1000000007
ll dp[20005][505];
int main()
{
	ios_base::sync_with_stdio(false);
	string str;
	cin>>str;
	int len=str.length();
	int q;
	cin>>q;
	while(q--)
	{
		memset(dp,0,sizeof(dp));
		int m,l;
		cin>>m>>l;
		dp[0][(str[0]-'0')%m]=1;
		for(int i=1;i<len;++i)
		{
			dp[i][(str[i]-'0')%m]++;
			for(int j=0;j<m;++j)
				dp[i][(j*10+str[i]-'0')%m]+=dp[i-1][j];
		}
		ll ans=0;
		for(int i=0;i<len;++i)
			ans+=dp[i][l];
		cout<<ans<<endl;
	}
	return 0;
}
