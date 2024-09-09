#include <stdio.h>

// Forward declaration of the merge function
void merge(int arr[], int start, int mid, int end);

void mergesort(int arr[], int start, int end){
	if(start < end){
		int mid = start+(end-start)/2;
		// Recursively sort the first and second halves
		mergesort(arr,start,mid);
		mergesort(arr,mid+1,end);
		
		// Merge the sorted halves
		merge(arr,start,mid,end);
	}
}

void merge(int arr[], int start, int mid, int end){
	int n1 = mid - start + 1;
	int n2 = end - mid;
	
	// Create temporary arrays
	int left[n1], right[n2];
	
	// Copy data to temp arrays left[] and right
	for(int i=0; i<n1; i++){
		left[i] = arr[start + i];
	}
	for(int j=0; j<n2; j++){
		right[j] = arr[mid + 1 + j];
	}
	
	// Merge the temp arrays back into arr[start..end]
	int i=0; // Initial index of first subarray
	int j=0; // Initial index of second subarray
	int k=start; // Initial index of merged subarray
	
	while(i<n1 && j<n2){
		if(left[i] <= right[j]){
			arr[k] = left[i];
			i++;
		} else{
			arr[k] = right[j];
			j++;
		}
		k++;
	}
	
	// Copy the remaining elements of left[], if any
	while(i<n1){
		arr[k] = left[i];
		i++;
		k++;
	}
	
	// Copy the remaining elements of right[], if any
	while(j<n2){
		arr[k] = right[j];
		j++;
		k++;
	}
}

void printArray(int arr[], int size){
	for(int i=0; i<size; i++){
		printf("%d", arr[i]);
		printf("\n");
	}
}


int main(){
	int arr[] = {12, 11, 13, 5, 6, 7};
	int arr_size = sizeof(arr) / sizeof(arr[0]);
	
	printf("Given array is \n");
	printArray(arr, arr_size);
	
	mergesort(arr, 0, arr_size-1);
	
	printf("\nSorted array is \n");
	printArray(arr, arr_size);
	
	return 0;



}
