#include<stdio.h>

void shellSort(int Data[], int dataLenght){
	int k = dataLenght/2;
	while(k>=1){
		int v,j;
		for(int i=k; i<dataLenght; i++){
			v= Data[i];
			j= i - k;
			while(j>=0 && Data[j]>v){
				Data[j+k] = Data[j];
				j-=k;
			}
			Data[j + k] = v;
		}
		k/=2;
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
	shellSort(Data, dataLenght);
	printAnswer(Data, dataLenght);
	return 0;
}