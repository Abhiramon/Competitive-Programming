#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(__typeof((v).begin()) it=(v).begin(); it != (v).end(); ++it)
#define meta __FUNCTION__,__LINE__

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

using namespace std;

template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}

typedef long long ll;
typedef pair<int,int> pii;

void solve(){
	string s; cin >> s;
	vector<char> u, v, w;
	for(int i = 0; i < s.length(); i++){
		v.pb(s[i]);
	}
	
	sort(v.begin(), v.end());
	u = v;

	int n = s.length(); 

	ll cnt = 0;
	int total = 0;
	do{
		w = u;	
		do{
			vector<char> tmp = w;
			total ++;	
			
			if(tmp == v) continue;
			
			bool flag = true;
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					for(int k = 0; k < n; k++){
						for(int l = 0; l < n; l++){
							swap(tmp[i], tmp[j]);
							swap(tmp[k], tmp[l]);
							
							if(tmp == v and tmp != w){
								flag = false;
								i = j = k = l = n+1;
								break;
							}
							
							swap(tmp[k], tmp[l]);
							swap(tmp[i], tmp[j]);
						}
					}
				}
			}
			
			lab:
			if(flag) cnt++;
			
		} while(next_permutation(w.begin(), w.end()));

	} while(next_permutation(v.begin(), v.end()));	
	
	cout << cnt << endl;
}


int main(){ _
	int t; cin >> t;
	while(t--) solve();
	return 0;
}
