# Merge Sort(병합정렬)
--------------------------------------------------------------------------------------------------------------------------

- 정렬할 배열을 반씩(잘게쪼갬) 나눈다.

- 앞 배열의 맨 앞의 값과, 뒷 배열의 맨 앞의 값을 비교하여 다른(정답)배열에 저장해준다. (쪼갠배열을 정렬하며 합해줌)

--------------------------------------------------------------------------------------------------------------------------

![1427](https://user-images.githubusercontent.com/29946480/51586306-054f2c00-1f20-11e9-941a-c0d6518d8b79.JPG)

-------------------------------------------------------------------------------------------------------------------------
# ↓↓Time Out↓↓

```c
#include<cstdio>
#include<cstdlib>
#define max 1000

void merging(int arr[],int s1,int e1,int s2,int e2) {

	int temp[max];
	int p = s1;
	int q = s2;
	int temp_idx = 0;

	while (p <= e1 && p <= e2)
	{
		if (arr[p] < arr[q]) {
			temp[temp_idx++] = arr[q];
			q++;
		}

		else {
			temp[temp_idx++] = arr[p];
			p++;
		}
	}

	if (p > e1)
	{
		for (int i = q; i <= e2; i++)
			temp[temp_idx++] = arr[i];
	}
	else
	{
		for (int i = p; i <= e1; i++)
			temp[temp_idx++] = arr[i];
	}

	for (int i = s1; i <= e2; i++)
	{
		arr[i] = temp[i - s1];
	}


}


void mergeSort(int arr[], int start, int end)
{
	if (start == end)
		return;
	
	else {
	
		int mid = (start + end) / 2;

		mergeSort(arr, start, mid);
		mergeSort(arr, mid+1, end);

		merging(arr, start, mid, mid + 1, end);
	}

}

int main() {

	int arr[max];
	int N;
	
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	mergeSort(arr,0,N-1);
	
	for (int i = 0; i < N; i++)
		printf("%d", arr[i]);

	system("pause");
	return 0;

}
```
