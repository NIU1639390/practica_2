#include <stdio.h>
#include <stdlib.h>
#define N 512
#define k 2
int Mat1[N][N];
int Mat2[N][N];
int Mat3[N][N];
int Vect1[N], Vect2[N], Vect3[N];
void initMats(){
	int i,j;
	srand(8824553);
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			Mat1[i][j]=rand()%100;
			Mat2[i][j]=rand()%100;
		}
	}
	for(i=0;i<N;i++){
		Vect1[i]=rand()%100;
		Vect2[i]=rand()%100;
	}
}
int mulMat(){
	int suma;
	for(int c=0;c<N;c++){
		for(int f=0;f<N;f++){
			suma=0;
			for(int j=0;j<N;j++){
				suma += Mat1[f][j]*Mat2[j][c];
			}
			Mat3[f][c] = suma;
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			printf("%d ",Mat3[i][j]);
		}
		printf("\n");
	}
}
int Saxpy(){
	Vect3==Vect1;
	for(int i=0;i<N;i++){
		Vect3[i] += k * Vect2[i];
	}
	for(int i=0;i<N;i++){
		printf("%d ",Vect3[i]);
		printf("\n");
	}
}
int transMat(){
}
int main(){
	initMats();
	mulMat();
	Saxpy();  
}
			
