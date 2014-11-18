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
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n,a,m;
    	cin>>n>>a>>m;
    	int ans=a+m;
    	if(a+m>n)
    		ans=ans%n;
    	if(ans==0)
    		ans=n;
    	cout<<ans<<endl;
    }
    return 0;
}