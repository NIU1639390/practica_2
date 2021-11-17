#include <stdio.h>
#include <stdlib.h>
#define N 512
int Mat1[N][N], Mat2[N][N];
int Vect1[N], Vect2[N];
//Generamos Matrices y vectores
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
//Multiplicacion de matrices
int mulMat(int Mat1[N][N], int Mat2[N][N], int tempM1M2[N][N]){
	int suma;
	for(int c=0;c<N;c++){
		for(int f=0;f<N;f++){
			suma=0;
			for(int j=0;j<N;j++){
				suma += Mat1[f][j]*Mat2[j][c];
			}
			tempM1M2[f][c] = suma;
		}
	}
}
//SAXPY con los vectores
int Saxpy(int Vector1[N], int Vector2[N], int b, int tempV1V2[N]){
	tempV1V2==Vect2;
	for(int i=0;i<N;i++){
		tempV1V2[i] += b * Vect1[i];
	}
}
//Matiz transpuesta
int transMat(int tempM1M2[N][N],int tempTransM1M2[N][N]){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			tempTransM1M2[i][j] = tempM1M2[j][i];
		}
	}
}
//Suma de la diagonal de la matriz
int sumDiagonal(int tempTransM1M2[N][N]){
	int suma=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
		 	if(i==j){
		 		suma += tempTransM1M2[i][j];
		 	}
		 }
	}	
}
//Suma los elementos de cada fila y lo coloca en un vector
int sumElement(int tempM1M2[N][N], int tempC[N]){
	int suma;
	for(int i=0;i<N;i++){
		suma=0;
		for(int j=0;j<N;j++){
			suma+=tempM1M2[j][i];
		}
		tempC[i]=suma;
	}
}
//Devuelve si ha podido hacer la operacion (True=1, False=0)
int PermutaF(int Matriu[N][N],int x, int y) {
	if (x>=N||y>=N) {
		return 0;
	}
	else {
		int tempV[N];
		for (int i=0; i<N; i++) {
			tempV[i]=Matriu[x][i];
		}
		for (int i=0; i<N; i++) {
			Matriu[x][i]=Matriu[y][i];
		}
		for (int i=0; i<N; i++) {
			Matriu[y][i]=tempV[i];
		}
		return 1;
	} 
}
//Programa principal
int main(){
	initMats();
	int tempM1M2[N][N];
	mulMat(Mat1, Mat2, tempM1M2);
	for (int j = 10; j < 20; j++){
		printf("%d ", tempM1M2[10][j]);
	}
	printf("\n\n");
	int tempV1V2 [N];
	Saxpy(Vect1, Vect2, 4, tempV1V2);
	for (int i=100; i<120; i++) {
		printf ("%d ", tempV1V2[i]);
	}
	printf ("\n\n");
	int tempTransM1M2[N][N];
   	transMat(tempM1M2,tempTransM1M2);
   	for (int i = 10; i < 20; i++){
		printf("%d\n", tempTransM1M2[i][10]);
  	}
  	printf("\n");
	int realitzat;
	realitzat=PermutaF(Mat1, 5, 10);
	printf ("%d\n", realitzat);
	realitzat=PermutaF(Mat2, 100, 512);
	printf ("%d\n\n", realitzat);
	printf("%d\n\n",sumDiagonal(tempTransM1M2));
	int tempC [N];
	sumElement(tempM1M2,tempC);
	for (int i=400; i<420; i++) {
		printf ("%d\n", tempC[i]);
	}	
}
			
