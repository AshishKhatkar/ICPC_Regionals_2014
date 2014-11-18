/*
ID: ashish1610
PROG:
LANG: C++
Solved after the contest was over
*/
#include<bits/stdc++.h>
using namespace std;
#define N 100005
#define MAX 400005
#define ll	long long int
#define MOD	1000000007
ll arr[N];
struct seg_node
{
	int maxx;
	int st,end;
	ll sum;
	bool inc,dec;
};
seg_node tree[MAX];
inline void build_tree(int node, int a, int b) 
{
	if(a > b)
		return;
	if(a == b) 
	{
		tree[node].maxx=arr[a];
		tree[node].st=arr[a];
		tree[node].end=arr[a];
		tree[node].sum=arr[a];
		tree[node].inc = true;	
		tree[node].dec = true;
		return;
	}
	build_tree(node*2, a, (a+b)/2);
	build_tree(node*2+1, 1+(a+b)/2, b);
	tree[node].maxx=max(tree[2*node].maxx, tree[2*node+1].maxx);
	tree[node].sum=tree[2*node].sum + tree[2*node+1].sum;
	tree[node].inc = tree[2*node].inc && tree[2*node+1].inc && tree[2*node].end<=tree[2*node+1].st?true:false;
	tree[node].dec = tree[2*node].dec && tree[2*node+1].dec && tree[2*node].end>=tree[2*node+1].st?true:false;
	tree[node].st=tree[2*node].st;
	tree[node].end=tree[2*node+1].end;
}
inline void update_tree(int node, int a, int b, int i, ll value)
{
	if(a==b)
	{
		arr[a]=value;
		tree[node].maxx=arr[a];
		tree[node].st=arr[a];
		tree[node].end=arr[a];
		tree[node].sum=arr[a];
		tree[node].inc = true;	
		tree[node].dec = true;
		return;
	}
	int mid=(a+b)/2;
	if(i<=mid)
		update_tree(2*node,a,mid,i,value);
	else
		update_tree(2*node+1,mid+1,b,i,value);
	tree[node].maxx=max(tree[2*node].maxx, tree[2*node+1].maxx);
	tree[node].sum=tree[2*node].sum + tree[2*node+1].sum;
	tree[node].inc = tree[2*node].inc && tree[2*node+1].inc && tree[2*node].end<=tree[2*node+1].st?true:false;
	tree[node].dec = tree[2*node].dec && tree[2*node+1].dec && tree[2*node].end>=tree[2*node+1].st?true:false;
	tree[node].st=tree[2*node].st;
	tree[node].end=tree[2*node+1].end;
}
inline pair<pair<int,int>,int> query_tree_inc(int node, int a, int b, int i, int j)
{
	if(a>b || a>j || b<i)
		return make_pair(make_pair(-1,-1),-1);
	if(a>=i && b<=j)
		return make_pair(make_pair(tree[node].inc?1:0,tree[node].st),tree[node].end);
	int mid=(a+b)>>1;
	pair<pair<int,int>,int> flag1=query_tree_inc(2*node, a, mid, i, j);
	pair<pair<int,int>,int> flag2=query_tree_inc(2*node+1, mid+1, b, i, j);
	if(flag1.first.first==-1)
		return flag2;
	if(flag2.first.first==-1)
		return flag1;
	pair<pair<int,int>,int> ans=make_pair(make_pair(flag1.first.first && flag2.first.first && flag1.second<=flag2.first.second,flag1.first.second),flag2.second);
	return ans;
}
inline pair<pair<int,int>,int> query_tree_dec(int node, int a, int b, int i, int j)
{
	if(a>b || a>j || b<i)
		return make_pair(make_pair(-1,-1),-1);
	if(a>=i && b<=j)
		return make_pair(make_pair(tree[node].dec?1:0,tree[node].st),tree[node].end);
	int mid=(a+b)>>1;
	pair<pair<int,int>,int> flag1=query_tree_dec(2*node, a, mid, i, j);
	pair<pair<int,int>,int> flag2=query_tree_dec(2*node+1, mid+1, b, i, j);
	if(flag1.first.first==-1)
		return flag2;
	if(flag2.first.first==-1)
		return flag1;
	pair<pair<int,int>,int> ans=make_pair(make_pair(flag1.first.first && flag2.first.first && flag1.second>=flag2.first.second,flag1.first.second),flag2.second);
	return ans;
}
inline int query_tree_maxx(int node, int a, int b, int i, int j)
{
	if(a>b || a>j || b<i)
		return -1;
	if(a>=i && b<=j)
		return tree[node].maxx;
	int mid=(a+b)>>1;
	int flag1=query_tree_maxx(2*node, a, mid, i, j);
	int flag2=query_tree_maxx(2*node+1, mid+1, b, i, j);
	if(flag1==-1)
		return flag2;
	if(flag2==-1)
		return flag1;
	return max(flag1,flag2);
}
inline ll query_tree_sum(int node, int a, int b, int i, int j)
{
	if(a>b || a>j || b<i)
		return -1;
	if(a>=i && b<=j)
		return tree[node].sum;
	int mid=(a+b)>>1;
	ll flag1=query_tree_sum(2*node, a, mid, i, j);
	ll flag2=query_tree_sum(2*node+1, mid+1, b, i, j);
	if(flag1==-1)
		return flag2;
	if(flag2==-1)
		return flag1;
	return flag1+flag2;
}
int main()
{
	ios_base::sync_with_stdio(false);
	ll n,q;
	cin>>n>>q;
	for(int i=0;i<n;++i)
		cin>>arr[i];
	build_tree(1,0,n-1);
	while(q--)
	{
		char type;
		int l,r;
		cin>>type>>l>>r;
		if(type=='U')
			update_tree(1,0,n-1,l-1,r);
		else if(type=='M')
			cout<<query_tree_maxx(1,0,n-1,l-1,r-1)<<endl;
		else if(type=='S')
			cout<<query_tree_sum(1,0,n-1,l-1,r-1)<<endl;
		else if(type=='I')
			cout<<query_tree_inc(1,0,n-1,l-1,r-1).first.first<<endl;
		else if(type=='D')
			cout<<query_tree_dec(1,0,n-1,l-1,r-1).first.first<<endl;
	}
	return 0;
}