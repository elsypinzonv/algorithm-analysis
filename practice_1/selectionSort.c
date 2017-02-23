#include<stdio.h>

void swap(int *greaterData, int *smallerData){
	int temporary =*greaterData;
	*greaterData = *smallerData;
	*smallerData = temporary;
}

void selectionSort(int Data[], int dataLenght){
	for( int k=0; k<dataLenght; k++){
		int p= k;
		for(int i=k+1; i<dataLenght; i++){
			if(Data[i]<Data[p]){
				p=i;
			}
		}
		if(p!=k){
			swap(&Data[p], &Data[k]);
		}
	}
}

void printAnswer(int Data[], int dataLenght){
	for(int i=0; i<dataLenght; i++){
		printf("%d ", Data[i]);
	}
}

int main(){
	int dataLenght=10;
	int Data[] = {2, 4, 8, 9, 11, 2, 1, 6, 9, 3};
	selectionSort(Data, dataLenght);
	printAnswer(Data, dataLenght);
	return 0;
}