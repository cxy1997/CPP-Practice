#include <stdio.h>
int main()
{
	FILE *fp = fopen_s("1348.in", "r");
	int n, m, i, x;
	unsigned long long sum = 0, t, y;
	fscanf_s(fp, "%d", &n);
	unsigned long long *songs = new unsigned long long[n];
	for (i = 0; i < n; ++i)
	{
		fscanf_s(fp, "%d", &t);
		songs[i] = sum;
		sum += t;
	}
	fscanf_s(fp, "%d", &m);
	unsigned long long **dancers = new unsigned long long*[2];
	dancers[0] = new unsigned long long[m / 2];
	dancers[1] = new unsigned long long[m / 2];
	int num[2] = { 0,0 };
	for (i = 0; i < m; ++i)
	{
		fscanf_s(fp, "%d %d", &x, &y);
		dancers[x - 1][num[x - 1]++] = y;
	}
	i = 0;
	x = 0;
	m /= 2;
	unsigned long long wait[2] = { 0,0 };
	while (i < n)
	{
		while (x < m && dancers[0][x] <= songs[i] && dancers[1][x] <= songs[i])
		{
			wait[0] += songs[i] - dancers[0][x];
			wait[1] += songs[i] - dancers[1][x];
			printf("%d %d %d %d\n", i, x, wait[0], wait[1]);
			++x;
		}
		++i;
	}

	for (i = 0; i < n; ++i) printf("%d ", songs[i]);
	printf("\n");
	for (i = 0; i < m; ++i) printf("%d ", dancers[0][i]);
	printf("\n");
	for (i = 0; i < m; ++i) printf("%d ", dancers[1][i]);
	printf("\n");

	printf("%0.2f %0.2f", wait[0] / m, wait[1] / m);
}
