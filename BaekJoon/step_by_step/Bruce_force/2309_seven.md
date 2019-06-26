-----------------------------------------------------------------------------------------------------
## 난쟁이 9명중 7명 선택 == 난쟁이 9명중 2명 선택안함

--> for문을 이용해서 2명을 선택하고 나머지 난쟁이키를 더해준다.

--> 난쟁이 키가 100이되면, 선택한 난쟁이 2명의 키를 100이상의 수로 바꿔준다.

--> 오름차순으로 정렬하고 100이하의 수만 출력.

-----------------------------------------------------------------------------------------------------
```c
#include<cstdio>
#include<cstdlib>
#include<algorithm>

using namespace std;

int arr[1000];

int main()
{
	
	int ans;

	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	for (int i = 0; i < 9; i++)
	{

		for (int j = 0; j < 9; j++)
		{
			if (i == j) continue;		
			ans = 0;

			for (int k = 0; k < 9; k++)
			{
				if (i!=k && j!=k)
					ans += arr[k];				
			}

			if (ans == 100)
			{
				arr[i] = 10000;
				arr[j] = 10000;
				goto EXIT; // 처음 써 본 문법. EXIT로 가라! ==> 이중반복문 루프 빠져나올때, break는 루프 한개만 빠져나오기 때문에 goto사용하면 편리

			}
		}	
	}
EXIT:
	
	sort(arr, arr + 9);

	for (int w = 0; w < 9; w++)
	{
		if (arr[w] < 100) {
			printf("%d\n", arr[w]);
		}
	}
	
  /*
  
  아래처럼 써도 됨 ==> 어차피 정렬되면 선택된 키는 맨뒤로 가기때문
  
  for (int w = 0; w < 7; w++)
		printf("%d\n", arr[w]);
    
	*/
  
	system("pause");
	return 0;
}
```
