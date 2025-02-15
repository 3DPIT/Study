#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define NS 504
#define MS 504
int N = 5, M = 5;
int inputData[NS][MS];
int board[NS][MS];
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };
int ret;
int ah[4][3][3] = {
	{
		{1,1,1},
		{0,1,0},
		{0,0,0}
	},
	{
		{1,0,0},
		{1,1,0},
		{1,0,0}
	},
	{
		{0,1,0},
		{1,1,1},
		{0,0,0}
	},
	{
		{0,1,0},
		{1,1,0},
		{0,1,0}
	}
};

void init() {
	ret = 0x80000000;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N + 4; i++) {
		for (int j = 0; j < M + 4; j++) {
			inputData[i][j] = -5000;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &inputData[i][j]);
		}
	}
}
bool safeZone(int y, int x) {
	return 0 <= y && y < N && 0 <= x && x < M;
}
void dfs(int y, int x,int sum, int idx)
{
	if (idx == 3) {
		ret = ret < sum ? sum : ret;
		return;
	}

	for (int dir = 0; dir < 4; dir++) {
		int ny = y + dy[dir]; int nx = x + dx[dir];
		if (safeZone(ny, nx) && board[ny][nx] == 0) {
			board[ny][nx] = 1;
			dfs(ny, nx, sum + inputData[ny][nx], idx + 1);
			board[ny][nx] = 0;
		}
	}
}
void play()
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			board[i][j] = 1;
			dfs(i, j,inputData[i][j], 0);
			board[i][j] = 0;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

			for (int k = 0; k < 4; k++) {
				int sum = 0;
				for (int ii = 0; ii < 3; ii++) {
					for (int jj = 0; jj < 3; jj++) {
						if (ah[k][ii][jj] == 1) {
							sum += inputData[i + ii][j + jj];
						}
					}
				}

				ret = ret < sum ? sum : ret;
			}

		}
	}
}
int main(void)
{
	init();
	play();
	printf("%d\n", ret);
	return 0;
}