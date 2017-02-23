#include<stdio.h>

void swap(int *greaterData, int *smallerData){
	int temporary =*greaterData;
	*greaterData = *smallerData;
	*smallerData = temporary;
}

void simpleBubbleSort(int Data[], int dataLenght){
	for(int i=0; i<dataLenght; i++){
		for(int j=0; j<dataLenght-1; j++){
			if(Data[j] > Data[j+1]){
				swap(&Data[j],&Data[j+1]);
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
	simpleBubbleSort(Data, dataLenght);
	printAnswer(Data, dataLenght);
	return 0;
}
