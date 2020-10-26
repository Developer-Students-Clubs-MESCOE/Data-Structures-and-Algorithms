/*
*
*Problem Link : https://codeforces.com/problemset/problem/1064/D
*comment: Labyrinth is an implementation of 0-1 Bfs and dynamic programming
*Platform: codeforces
*Status: correct
*Author: Mayukh Chakrabarti (https://github.com/MayukhC99)
*
*/

#include<bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false); cin.tie(NULL);
#define booster cout.tie(NULL)
#define endl "\n"

typedef long long int ll;

#define mp make_pair
#define pb push_back
#define fi first
#define si second
#define pii pair<ll,ll>
#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n) for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n) for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;

#define mod 1000000007
const ll inf= 1e12;

using namespace std;

ll n,m,r,c,x,y;

ll rows[4]={0 , 0 , 1 , -1 };
ll cols[4]={1 ,-1 , 0 ,  0 };
ll cost[4]={0 , 1 , 0 ,  0 };

string maze[ 2005 ];
ll dp[ 2005 ][ 2005 ];

bool isValidCell(ll x1,ll y1){
	return (x1>=0 and y1>=0 and x1<n and y1<m and maze[x1][y1] == '.');
}

void Solve(){
	
	deque<pii> q;
	memset(dp,-1,sizeof dp);
	dp[r][c] = 0;
	q.push_front({r,c});

	while(!q.empty()){
		auto node = q.front();
		q.pop_front();

		ll ci = node.fi;
		ll cj = node.si;
		for(ll i = 0 ; i < 4 ; i++){
			ll ni = ci + rows[i];
			ll nj = cj + cols[i];
			ll len = cost[i];
			if(isValidCell(ni,nj)){
				if(dp[ni][nj] == -1 || (dp[ni][nj] > dp[ci][cj] + len)){
					dp[ni][nj] = dp[ci][cj] + len;
					if(len)
						q.push_back({ni,nj});
					else
						q.push_front({ni,nj});
				}
			}
		}
	}
	ll ans = 0;
	for(ll i = 0 ; i < n ; i++){
		for(ll j = 0 ; j < m ; j++){
			ll left = dp[i][j];
			if(left != -1){
				ll right = left + j - c;
				if(left>=0 and right >=0 and left <=x and right<=y)
					ans++;
			}
		}
	}
	cout<<ans<<endl;
}


int main(){
	speed;
	
	cin>>n>>m>>r>>c>>x>>y;
	r--; c--;
	for(ll i = 0 ; i < n ; i++){
		cin>>maze[i];
	}

	Solve();
	return 0;
}


