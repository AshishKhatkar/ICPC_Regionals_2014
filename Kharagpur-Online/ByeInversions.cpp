/*
ID: tle4ever
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
#define MOD	1000000007
ll ar[1000005], cnt[1000005], inversion_cnt;
void mergeSort(ll arr[], ll low, ll mid, ll high)
{
	ll i,m,k,l,temp[1000005];
	l=low;
	i=low;
	m=mid+1;
	while((l<=mid)&&(m<=high))
	{
		if(arr[l]<=arr[m])
		{
			temp[i]=arr[l];
			l++;
		}
		else
		{
			inversion_cnt+=(mid-l+1);
			temp[i]=arr[m];
			m++;
		}
		i++;
	}
	if(l>mid)
	{
		for(k=m;k<=high;k++)
		{
			temp[i]=arr[k];
			i++;
		}
	}
	else
	{
		for(k=l;k<=mid;k++)
		{
			temp[i]=arr[k];
			i++;
		}
	}
	for(k=low;k<=high;k++)
		arr[k]=temp[k];
}
void partition(ll arr[],ll low,ll high)
{
	ll mid;
	if(low<high)
	{
		mid=(low+high)/2;
		partition(arr,low,mid);
		partition(arr,mid+1,high);
		mergeSort(arr,low,mid,high);
	}
}
bool flag[1000005];
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	int cnt=0;
	while(t--)
	{
		cnt++;
		memset(flag,false,sizeof(flag));
		inversion_cnt=0;
		int n,k;
		cin>>n>>k;
		bool flag1=false;
		for(int i=0;i<n;++i)
		{
			cin>>ar[i];
			if(!flag[ar[i]])
				flag[ar[i]]=true;
			else
				flag1=true;
		}
		partition(ar,0,n-1);
		ll ans=inversion_cnt-k;
		cout<<"Case "<<cnt<<": ";
		if(ans>=0)
			cout<<ans<<endl;
		else
		{
			if(flag1)
				cout<<"0\n";
			else
			{
				if(abs(ans)&1)
					cout<<"1\n";
				else
					cout<<"0\n";
			}
		}
	}
	return 0;
}
