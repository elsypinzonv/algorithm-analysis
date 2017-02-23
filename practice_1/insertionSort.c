#include<stdio.h>

void insertionSort(int Data[], int dataLenght){
	int previousValue;
	for(int i=1; i<dataLenght; i++){
		int temporary = Data[i];
		previousValue=i-1;
		while((Data[previousValue]>temporary) && (previousValue>=0)){
			Data[previousValue+1] = Data[previousValue];
			previousValue--;
		}
		Data[previousValue+1] = temporary;
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
	insertionSort(Data, dataLenght);
	printAnswer(Data, dataLenght);
	return 0;
}