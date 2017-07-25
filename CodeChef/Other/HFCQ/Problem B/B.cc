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

const int N = 1000001;
const ll MOD = 1e9 + 7;

int sieve[N], primes[N], pcnt;

void getSieve(){
	for(int i = 2; i <= N; i++){
		if(sieve[i] == 0){
			sieve[i] = i; primes[pcnt++] = i;
		}
		for(int j = 0; j < pcnt and primes[j] <= sieve[i] and i*primes[j] <= N; j++) sieve[i*primes[j]] = primes[j];
	}
	return;
}


void RI() {}

template<typename... T>
void RI( int& head, T&... tail ) {
	    scanf("%d",&head);
			    RI(tail...);
}

mt19937 rng(0x5EED);
int randint(int lb, int ub) {
    return uniform_int_distribution<int>(lb, ub)(rng);
}
// Let's Fight! }}}

// n < 4,759,123,141        3 :  2, 7, 61
// n < 1,122,004,669,633    4 :  2, 13, 23, 1662803
// n < 3,474,749,660,383          6 :  pirmes <= 13
// n < 3,825,123,056,546,413,051  9 :  primes <= 23

long long mult(long long s, long long m, long long mod) {
  if (!m) return 0;
  long long ret = mult(s, m/2, mod);
  ret = (ret + ret) % mod;
  if (m & 1) ret = (ret + s) % mod;
  return ret;
}
long long power(long long x,long long p,long long mod){
	long long s=1,m=x;
	while(p) {
		if(p&1) s=mult(s,m,mod);
		p>>=1;
		m=mult(m,m,mod);
	}
	return s;
}
bool witness(long long a,long long n,long long u,int t){
	long long x=power(a,u,n);
	for(int i=0;i<t;i++) {
		long long nx=mult(x,x,n);
		if(nx==1&&x!=1&&x!=n-1) return 1;
		x=nx;
	}
	return x!=1;
}
bool Miller(long long n,int s=100) {
	// iterate s times of witness on n
	// return 1 if prime, 0 otherwise
	if(n<2) return 0;
	if(!(n&1)) return n==2;
	long long u=n-1;
	int t=0;
	// n-1 = u*2^t
	while(u&1) {
		u>>=1;
		t++;
	}
  const int test[] = {2,3,5,7,11,13,17,19,23};
  for (int i=0; i<9; i++) {
		long long a=test[i];
		if(witness(a,n,u,t)) return 0;
	}
	return 1;
}

void solve(){
	ll n, k;
	scanf("%lld%lld", &n, &k);
	
	int exponent = 1;
	for(ll i = 0, j = primes[i]; j*j*j <= k; j = primes[++i]){
		if(k % j == 0){
			k /= j;
			exponent <<= 1;
		}
	}
	
	if(Miller(k))
		exponent <<= 1;
	else if(k != 1)
		exponent <<= 2;
	
	ll ans = 1;
	for(ll i = 0, j = primes[i]; j*j*j <= n; j = primes[++i]){
		if(n % j == 0){
			n /= j;
			ans = (ans * (exponent+1))%MOD;
		}
	}
	
	if(Miller(n)){
		ans = (ans * (exponent+1))%MOD;
	}
	else if(n != 1){
		ans = (ans * (exponent+1))%MOD;
		ans = (ans * (exponent+1))%MOD;
	}
	
	printf("%lld\n", ans);
}

int main(){
	getSieve();
	int t; sd(t);
	while(t--) solve();
	return 0;
}
