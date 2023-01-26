#include <iostream>
#define INF (int)1E9;
using namespace std;

int dp[501][501];
int cost[501];
int csum[501];
int main()
{
	int T;
	cin >> T;
	while (T--) {
		int K;
		cin >> K;
		for (int i = 1; i <= K; i++) {
			cin >> cost[i];
			csum[i] = cost[i] + csum[i - 1];
		}

		for (int i = 1; i < K; i++) {
			for (int j = 1; j+i <= K; j++) {
				dp[j][j + i] = INF;
				int v = csum[j + i] - csum[j - 1];
				for (int k = 0; k < i; k++) {
					dp[j][j + i] = min(dp[j][j + i], dp[j][j+k] + dp[j+k+1][j+i] + v);
				}
			}
		}
		cout << dp[1][K] << endl;

	}
	return 0;
}