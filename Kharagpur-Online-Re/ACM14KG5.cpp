/*
ID: tle4ever
PROG:
LANG: C++
Removed Template from it
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
#define MOD	1000000007
ll dp[100005][320];
vector<int> fac[100005];
void pre_compute()
{
	for(int i=1;i<=100000;++i)
	{
		for(int j=1;j<=(sqrt(i));++j)
			fac[i].push_back(i/j);
		fac[i].push_back(int(sqrt(i)));
	}
	for(int i=1;i<320;++i)
		dp[0][i]=1;
	dp[0][0]=0;
	for(int i=1;i<=100000;++i)
	{
		for(int j=1;j<320;++j)
			dp[i][j]=(dp[i-1][j]+dp[i][j-1])%MOD;
	}
}
int main()
{
    int t;
    cin>>t;
    pre_compute();
    while(t--)
    {
    	int n,k;
    	cin>>n>>k;
    	if(n==1)
    		cout<<"-1\n";
    	else if(k==1)
    		cout<<"1\n";
    	else
    	{
    		ll ans=0;
    		for(int i=1;i<fac[k].size();++i)
    			ans=(ans+dp[n-1][i]*(fac[k][i-1]-fac[k][i]))%MOD;
    		ans=(ans+dp[n][(int)sqrt(k)])%MOD;
    		cout<<ans<<endl;
    	}
    }
    return 0;
}