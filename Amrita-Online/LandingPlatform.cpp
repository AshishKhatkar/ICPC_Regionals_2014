/*
ID: tle4ever
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
#define MOD	1000000007
ll ar[105][105], ar1[105][105];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int m,n;
		cin>>m>>n;
		memset(ar,0,sizeof(ar));
		memset(ar1,0,sizeof(ar1));
		for(int i=1;i<=m;++i)
		{
			for(int j=1;j<=n;++j)
			{
				cin>>ar[i][j];
				ar1[i][j]=ar[i][j];
			}
		}

		for(int i=1;i<=n;++i)
			for(int j=i,k=1;j>=1 && k<=m;--j,++k)
				ar1[k][j]+=ar1[k-1][j+1];

		for(int i=2;i<=m;++i)
			for(int j=n,k=i;j>=1 && k<=m;--j,++k)
				ar1[k][j]+=ar1[k-1][j+1];
		ll ans=LONG_LONG_MIN;
		for(int i=1;i<=m;++i)
		{
			for(int j=1;j<=n;++j)
			{
				ll tmp=ar[i][j];
				for(int r=i+1,c=j+1,cnt=2; r<=m && c<=n; ++r,++c,++cnt)
				{
					tmp+=ar[r][c];
					if(cnt%2)
						ans=max(ans,tmp-ar1[i-1][j+cnt]+ar1[i-1+cnt][j]-ar[(i+r)/2][(j+c)/2]);
					else
						ans=max(ans,tmp-ar1[i-1][j+cnt]+ar1[i-1+cnt][j]);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
