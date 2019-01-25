# Dynamic Programming 문제2

### - DP문제 같으면 점화식을 세워보자!

----------------------------------------------------------------------------------------------------------------

![9095](https://user-images.githubusercontent.com/29946480/51743270-7852d100-20df-11e9-824c-d73d569817a8.JPG)


----------------------------------------------------------------------------------------------------------------

```c
#include<cstdio>
#include<cstdlib>


int d[1000];


int hap(int n) { 

	if (n == 3)
		return d[3] = 4;
	if (n == 2)
		return d[2] = 2;
	if (n == 1)
		return d[1] = 1;
	if (d[n] != 0)
		return d[n];
	else
		return d[n] = hap(n - 3) + hap(n - 2) + hap(n - 1);

}


int main()
{
	int T,N;
	int n[15] = {};
	int ans[15] = {};

	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		scanf("%d", &n[i]);
		ans[i] = hap(n[i]);
	}
	for (int j = 0; j < T; j++)
		printf("%d\n", ans[j]);


	system("pause");
	return 0;
}
```
