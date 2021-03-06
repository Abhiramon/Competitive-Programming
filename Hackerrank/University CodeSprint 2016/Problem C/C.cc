#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(auto it=(v).begin(); it != (v).end(); ++it)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define tr(...) cout<<__FUNCTION__<<' '<<__LINE__<<" = ";trace(#__VA_ARGS__, __VA_ARGS__)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

template<typename T>
void trace(const char* name, T&& arg1){cout<<name<<" : "<<arg1<<endl;}

template<typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}

const ld PI = 3.1415926535897932384626433832795;

const int N = 100100;
const int MAXN = 400100;
const int OFF = 200100;

int tree[MAXN]; // Careful, indexing begins from 1.

int query(int idx, int sum = 0){
    for(; idx; idx -= (idx & -idx)) sum += tree[idx];
    return sum;
}

void update(int idx, int val){
    for(; idx < MAXN; idx += (idx & -idx)) tree[idx] += val;
}

int n;
int a[N];
int cnt[N];

int main(){ _
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	for(int i = 0; i < n; i++){
		update(OFF + a[i] - i, 1);
	}
	
	for(int i = 0; i < n; i++){
		cnt[i] = query(OFF-i);
		update(OFF + a[i]-i,   -1);
		update(OFF + a[i]-i-n,  1);
	}
	
	int id = 0, mx = cnt[0];
	for(int i = 1; i < n; i++){
		if(cnt[i] > mx){
			mx = cnt[i];
			id = i;
		}
	}	
	
	cout << id + 1 << endl;
	
	return 0;
}
