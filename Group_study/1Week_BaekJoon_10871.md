![10871](https://user-images.githubusercontent.com/29946480/51605946-d783da80-1f53-11e9-9c42-dce5fa31af68.JPG)

```c
#include<cstdio>
#include<cstdlib>



int main()
{
	int N,x;
	int arr[10000] = {};
	scanf("%d %d",&N, &x);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i < N; i++) {
		if (x > arr[i])
			printf("%d ", arr[i]);
	}

	system("pause");
	return 0;
}
```
