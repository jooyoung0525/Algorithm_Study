***scanf이용한 문제 풀이***
--------------------------------------------------------------------------------------------------------------------------

```c
#include<cstdio>
#include<cstdlib>


int main() {

	char input[101];

	while (scanf("%[^\n]\n",input) == 1) 
                                             //scanf로 입력받을 때, \n을 제외한 모든 값을 입력받음.
                                             //scanf의 리턴값이 1일때, 계속 반복
	
		printf("%s\n",input);
	

	
	system("pause");
	return 0;
}
```
------------------------------------------------------------------------------------------------------------------------
***fgets를 이용한 문제풀이***
------------------------------------------------------------------------------------------------------------------------

### fgets ( char * str, int num, FILE * stream ) ==> 문자열 자료형(char *)
-  str = 읽어들인 문자열을 저장할 배열주소
-  num = 마지막 NULL문자를 포함해 읽어들일 최대 문자 수. (10개입력받고 싶으면 = 11)
-  stream = 문자열을 읽어들일 스트림의 FILE 객체를 가리키는 포인터. 
             
	        특히, 표준 입력(stdin) 에서 입력을 받으려면 여기에 stdin 을 써주면 된다.
	     
             
             
```c
#include<cstdio>
#include<cstdlib>


int main() {

	char input[101];

	while (fgets(input,101,stdin))                            
  		printf("%s",input); //fgets함수는 입력이 끝나면 자동으로 \n을 
                                    //실행하기 때문에 %s\n를 해줄 필요가 없다.
  

	
	system("pause");
	return 0;
}
```
