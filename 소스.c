#include <stdio.h>

int num[1000], chk[1001], prime[150], answer[3], sw, sel, n;

void dfs(int st, int j,int sum)
{
	int i, next;

	if (sw == 1) return;

	if (st == 3 ) {
		if (sum == n)
		{
			printf("%d %d %d\n", answer[0], answer[1], answer[2]);
			sw = 1;
		}
		return;
	}

	for (i = j; i <= sel; i++)
	{
		next = sum + prime[i];
		if ((next <= n - 4 && st == 0) || (next <= n - 2 && st == 1) || (next == n && st == 2))
		{
			answer[st] = prime[i];
			dfs(st + 1, i, next);
		}
	}
}

int main()
{
	int T, maxNum=0, i, j, cnt=0;

	scanf("%d", &T);
	for (i = 0; i < T; i++)
	{
		scanf("%d", &num[i]);
		maxNum = (maxNum < num[i]) ? num[i] : maxNum;
	}

	for (i = 2; i <maxNum; i++)
	{
		if (chk[i] == -1) continue;

		prime[cnt] = i;
		chk[i] = cnt++;
		for (j = i; j <=maxNum; j+=i)
			if (i != j) chk[j] = -1;
	}

	for (i = 0; i < T; i++)
	{
		for (j = num[i]-2; j > 1; j--)
		{
			if (chk[j] != -1)
			{
				sel = chk[j];
				break;
			}
		}

		sw = 0;
		n = num[i];
		dfs(0, 0,0);

		if (sw == 0) printf("0\n");
	}

	return 0;
}