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
vector<int>adj[26+5];
int ar[26+5][26+5];
bool visited[26+5];
void dfs(int nd, int src)
{
	visited[nd]=true;
	ar[src][nd]=1;
	for(int i=0;i<adj[nd].size();++i)
		if(!visited[adj[nd][i]])
			dfs(adj[nd][i],src);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	memset(ar,0,sizeof(ar));
    	memset(visited,false,sizeof(visited));
    	for(int i=0;i<26;++i)
    		adj[i].clear();
    	string str1,str2;
    	cin>>str1>>str2;
    	int m;
    	cin>>m;
    	while(m--)
    	{
    		string tmp;
    		cin>>tmp;
    		char a=tmp[0],b=tmp[3];
    		adj[a-'a'].push_back(b-'a');
    	}
    	for(int i=0;i<26;++i)
    	{
    		memset(visited,false,sizeof(visited));
    		dfs(i,i);
    	}
    	int len=str1.length();
    	bool flag=true;
    	for(int i=0;i<len;++i)
    	{
    		if(ar[str1[i]-'a'][str2[i]-'a']!=1)
    		{
    			flag=false;
    			break;
    		}
    	}
    	if(str1.length()!=str2.length())
    		cout<<"NO\n";
    	else if(!flag)
    		cout<<"NO\n";
    	else
    		cout<<"YES\n";
    }
    return 0;
}