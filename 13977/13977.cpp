#include <iostream>
#include <vector>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;

ll facto[4000001] = { 1, 1 };
ll inv_facto[4000001] = { 1, 1 };

ll powmod(ll a, ll b) {
	if (b == 0) return 1;
	ll half = powmod(a, b>>1);
	if (b & 1)
		return ((a * half) % MOD) * half % MOD;
	else
		return half * half % MOD;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int M;
	cin >> M;
	for (ll i = 2; i <= 4000000; i++) {
		facto[i] = facto[i - 1] * i % MOD;
		inv_facto[i] = powmod(facto[i], MOD - 2LL);
	}

	for (ll i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		if (b == 0)
			cout << 1 << '\n';
		else
			cout << ((facto[a] * inv_facto[b]) % MOD * inv_facto[a - b]) % MOD << '\n';
	}
	
	return 0;
}