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
vector<pair<ll,ll> > v;
bool compare(pair<ll,ll> p1, pair<ll,ll> p2)
{
	if(p1.first==p2.first)
		return p1.second<p2.second;
	return p1.first<p2.first;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		v.clear();
		int n;
		ll s,e;
		cin>>s>>e;
		cin>>n;
		pair<ll,ll>p;
		for(int i=0;i<n;++i)
		{
			cin>>p.first>>p.second;
			v.push_back(p);
		}
		sort(v.begin(),v.end(),compare);
		bool flag=true;
		for(int i=0;i<n;++i)
		{
			if(!((v[i].first<=s && v[i].second<=s) || (v[i].first>=e && v[i].second>=e)))
			{
				flag=false;
				break;
			}
		}
		if(flag)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}