/*
ID: ashish1610
PROG:
LANG: C++
Solved after the contest was over
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
#define MOD	1000000007
int ar[26];
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		memset(ar,0,sizeof(ar));
		string str;
		cin>>str;
		for(int i=0;i<str.length();++i)
			ar[str[i]-'a']++;
		ll p,q;
		cin>>p>>q;
		for(int i=0;i<26;++i)
			ar[i]*=p;
		while(q--)
		{
			ll n;
			cin>>n;
			ll cnt=0;
			char ans='1';
			bool flag=false;
			for(int i=0;i<26;++i)
			{
				cnt+=ar[i];
				if(cnt>=n)
				{
					ans=i+'a';
					flag=true;
					break;
				}
			}
			if(cnt>=n && !flag)
				ans=25+'a';
			if(ans=='1')
				cout<<-1<<endl;
			else
				cout<<ans<<endl;
			
		}
	}
	return 0;
}