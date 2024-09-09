#include<stdio.h>

void bubblesort(int arr[], int size){
	int flag; //If the array is already sorted then it will optimize the algorithm
	for(int i=0; i<size-1; i++){
		flag = 0;
		for(int j=0; j<size-1-i; j++)//j<size-1-i In each iteration, largest element gets put into it's place, so we need less comparisons. If there are 5 elements, then the largest element will be placed at the last location. So we need not to consider that position
		
		{
			if(arr[j] > arr[j+1]){
				swap(&arr[j], &arr[j+1]);
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

}

int main(){
	int arr[] = {50,40,30,20,10};
	
	printf("The array before sorting is: ");
	printArray(arr, arr.length);
	
	printf("After sorting the srray is: ");
	printArray(arr, arr.length);
	
	return 0;
}
