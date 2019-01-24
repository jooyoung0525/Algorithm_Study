# 문자열 포맷에 관한 문제

**%d = 정수**

**%x = 16진수**

**%o = 8진수**

**%s = 문자열**

**%c = 문자**

**%f = 실수**

**%lf = double형**

**%Lf = long double형**

**(윈도우)%lld = long long형**

**%i = 입력형태에 따라 형태가 달라짐**


*번외) 많이 사용하는 자료형*
int(정수형), char(문자형), char*(문자열형), double...

```c
#include<cstdio>
#include<cstdlib>


int main() {

	int x;
	scanf("%i", &x); //%i는 입력 형태에 따라 10,8,16진수가 입력! (EX. 011==>9(8진수) , 0x11 ==>17(16진수)

	printf("%i", x);

	system("pause");
	return 0;
}
```
