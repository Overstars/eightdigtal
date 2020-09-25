//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
#define ff first
#define ss second
const int maxn=2e5+10,inf=0x3f3f3f3f,mod=1000000007;
const ll INF=0x3f3f3f3f3f3f3f3f;
const double eps=1e-9;
//#define DEBUG//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
void show(const string &s)
{
	for(int i=0;i<9;i++)
	{
		cout<<' '<<s[i]<<((i+1)%3==0?'\n':' ');
	}
	cout<<endl;
}
list<string>ans;
unordered_map<string,bool>vis;
string target="123804765";
int nx[]={0,1,0,-1},ny[]={1,0,-1,0},lim=INT_MAX;
bool ok=0;
void dfs(string s,int depth)
{
	if(vis[s]||ok||depth>lim)//与普通dfs区别只有深度限制
		return;
	ans.push_back(s);
	show(s);
	if(s==target)
	{
		ok=1;
		return;
	}
	vis[s]=1;
	int pos=s.find('0');
	int x=pos/3,y=pos%3;
	for(int i=0;i<4;i++)
	{
		int xx=x+nx[i],yy=y+ny[i];//0移动到的位置
		if(xx<0||xx>2||yy<0||yy>2)
			continue;
		swap(s[xx*3+yy],s[pos]);
		dfs(s,depth+1);
		swap(s[xx*3+yy],s[pos]);
	}
	if(!ok)
		ans.pop_back();
}
int ids(string s)
{
	lim=3;
	int inc=2;
	while(!ok)
	{
		lim+=inc;
		ans.clear();
		vis.clear();
		dfs(s,0);
	}
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	string s;
	cin>>s;
	ids(s);
//	dfs(s,0);
	cout<<ans.size()<<endl;
	for(string &x:ans)
		show(x);
	return 0;
}
//283164705

