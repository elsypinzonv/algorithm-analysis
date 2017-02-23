#include<stdio.h>

void swap(int *greaterData, int *smallerData){
	int temporary =*greaterData;
	*greaterData = *smallerData;
	*smallerData = temporary;
}

void optimizedBubbleSort(int Data[], int dataLenght){
	for(int i=0; i<dataLenght; i++){
		for(int j=0; j<i; j++){
			if(Data[i] < Data[j]){
				swap(&Data[j],&Data[i]);
			}
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
	optimizedBubbleSort(Data, dataLenght);
	printAnswer(Data, dataLenght);
	return 0;
}