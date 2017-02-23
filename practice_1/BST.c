#include<stdio.h>

 #define MAX_LENGTH 10

typedef struct  data{
	int stack[MAX_LENGTH];
	int size;
}Stack;

void initializeStack(Stack *s){
	s->size=0;
}
void push(int newValue, Stack *s){
	s->stack[s->size] = newValue;
	s->size++;
}

int isEmpty(Stack *s){
	return (s->size <= 0);
}

void pop(Stack *s){
	if (!isEmpty(s)) s->size--;
}

int top(Stack *s){
	return s->stack[s->size -1];
}


void build(int index, int value, int *root, int *left, int *right){
	int j=0;
	while(1){
		if(value>=root[j]){
			if(right[j]==-1){
				right[j]=index;
				break;
			}else j = right[j];
		}else{
			if(left[j]==-1){
				left[j]=index;
				break;
			}else j = left[j];

		}
	}

}

void insertNode(int index, int value, int *root, int *left, int *right){
	root[index]= value;
	left[index] = -1;
	right[index] = -1;
	if(index > 0) build(index, value,root, left, right);
}

void initialize(int *flag){
	for(int i=0; i<MAX_LENGTH; i++){
		flag[i]=0;
	}
}

void inOrder(int *root, int *left, int *right){
	Stack s;
	int flag[MAX_LENGTH];
	initializeStack(&s);
	initialize(flag);
	push(0,&s);
	int nod;
	while(!isEmpty(&s)){
		nod=top(&s);
		pop(&s);
		if(flag[nod]==0){	
			if(right[nod]!=-1)push(right[nod], &s);
			push(nod, &s);
			if(left[nod]!=-1)push(left[nod], &s);
			flag[nod]++;
		}else{
			printf("%d ", root[nod]);
		}
	}
}

void BST(int Data[]){
	int root[MAX_LENGTH];
	int left[MAX_LENGTH];
	int right[MAX_LENGTH];
	for(int i=0; i<MAX_LENGTH; i++){
		insertNode(i, Data[i], root, left,right);	
	}
	inOrder(root, left, right);
}

int main(){
	int Data[] = {7, 3, 1, 9, 6, 8, 7, 2, 11, 3};
	BST(Data);
	return 0;
}