# TestCase의 갯수가 주어지지 않았을 때
---------------------------------------------------------------------------------------------------



**Scanf의 리턴 값(성공적으로 입력을 받은 인자의 갯수)을 이용**


```c
#include<cstdio>
#include<cstdlib>


int main() {

	int a, b;
	
	while (scanf("%d %d", &a, &b) == 2) 
	      //while조건문 안에서 scanf가 입력을 받으므로, 따로 또 scanf를 작성하지 않아도 된다!!
	{
		
		printf("%d\n", a+b);

	}

	
	system("pause");
	return 0;
}
```