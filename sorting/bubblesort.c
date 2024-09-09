#include<stdio.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubblesort(int arr[], int size){
	int flag; //If the array is already sorted then it will optimize the algorithm
	for(int i=0; i<size-1; i++){
		flag = 0;
		for(int j=0; j<size-1-i; j++)//j<size-1-i In each iteration, largest element gets put into it's place, so we need less comparisons. If there are 5 elements, then the largest element will be placed at the last location. So we need not to consider that position
		
		{
			if(arr[j] > arr[j+1]){
				swap(&arr[j], &arr[j+1]);
				flag = 1; // Set flag to 1 if a swap occurs
			}
		}
		if(flag == 0){
			break;
		}
	}
}

void printArray(int arr[], int size){
	int i = 0;
	while(i < size){
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
}

int main(){
	int arr[] = {50,40,30,20,10};
	
	int length = sizeof(arr)/sizeof(arr[0]);
	
	printf("The array before sorting is: ");
	printArray(arr, length);
	
	bubblesort(arr, length);
	printf("After sorting the array is: ");
	printArray(arr, length);
	
	return 0;
}
