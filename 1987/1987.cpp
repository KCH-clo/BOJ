#include <iostream>
#include <string>
using namespace std;

int R, C;
int ans = 1;
string map[20];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

int get_bit(char c) {
	return 1 << (c - 'A');
}

void dfs(int x, int y, int dist, int state) {
	ans = max(ans, dist);
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < C && ny >= 0 && ny < R) {
			if ((get_bit(map[ny][nx]) & state) == 0) {
				dfs(nx, ny, dist + 1, state | (get_bit(map[ny][nx])));
			}
		}
	}

}


int main()
{
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> map[i];
	}
	dfs(0, 0, 1, get_bit(map[0][0]));
	cout << ans << endl;
	return 0;
}