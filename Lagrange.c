//	Lagrange

#include<stdio.h>
#include<stdlib.h>

void alocaInt(int **p, int tam);
void alocaFloat(float **p, int tam);
void qtdNumerosTabela(int *num);
void receberTermos(int *num, float *x, float *y);
void pontoInterpolacao(float *xp, float *x, int *num);
void verificarIntervalo(float *xp, float *x, int *num);
void calculaL(float *x, float *xp, float *L, int *num);
void implementarLagrange(float *y, float *yp, float *L, int *num);
void mostraResultados(float *L, float *yp, float *xp, int *num);

void main(){
	float *x=NULL, *y=NULL, *xp=NULL, *yp=NULL, *L=NULL;
	int *num=NULL;
	alocaInt(&num,1);
	qtdNumerosTabela(num);
	alocaFloat(&x,*num);
	alocaFloat(&y,*num);
	receberTermos(num,x,y);
	alocaFloat(&xp,1);
	pontoInterpolacao(xp,x,num);
	alocaFloat(&yp,1);
	alocaFloat(&L,*num);
	calculaL(x,xp,L,num);
	implementarLagrange(y,yp,L,num);
	mostraResultados(L,yp,xp,num);
	system("PAUSE");
}

void mostraResultados(float *L, float *yp, float *xp, int *num){
	int f;
	for(f=0; f<(*num); f++){
		printf("\nL[%i] -> %.3f",f,*(L+f));
	}
	printf("\n\nInterpolation point = %.3f  in  f(x) = %.3f\n\n",*xp,*yp);
}

void implementarLagrange(float *y, float *yp, float *L, int *num){
	int f;
	for(f=0; f<*(num); f++){
		*yp += (*(L+f)) * (*(y+f));
	}
}

void calculaL(float *x, float *xp, float *L, int *num){
	int i, j;
	float numeradorL, denominadorL;
	for(i=0; i<(*num); i++){
		numeradorL = 1;
		denominadorL = 1;
		for(j=0; j<(*num); j++){
			if(i!=j){
				numeradorL *= (*xp - *(x+j));
				denominadorL *= (*(x+i) - *(x+j));
			}
		}
		*(L+i) = numeradorL / denominadorL;
	}
}

void verificarIntervalo(float *xp, float *x, int *num){
	int f;
	if(*xp < *x){
		printf("\nMinimum number not reached, choose another one!\n");
		pontoInterpolacao(xp,x,num);
	}else if(*xp > *(x+*num-1)){
		printf("\nMaximum number not reached, choose another one!\n");
		pontoInterpolacao(xp,x,num);
	}else{
		for(f=0; f<(*num); f++){
			if(*xp == *(x+f)){
				printf("\nThis number exists in the table, choose another one!\n");
				pontoInterpolacao(xp,x,num);
				break;
			}
		}
	}
}

void pontoInterpolacao(float *xp, float *x, int *num){
	printf("\nEnter interpolation point: ");
	scanf("%f",xp);
	verificarIntervalo(xp,x,num);
}

void receberTermos(int *num, float *x, float *y){
	int f;
	printf("\nEnter data:\n");
	for(f=0; f<(*num); f++){
		printf("x[%d] = ",f);
		scanf("%f",x+f);
		printf("y[%d] = ",f);
		scanf("%f",y+f);
	}
}

void qtdNumerosTabela(int *num){
	printf("\nEnter number of data: ");
	scanf("%d",num);
}

void alocaFloat(float **p, int tam){
  if((*p=(float*)realloc(*p,tam*sizeof(float)))==NULL){
    printf("\nDynamic Allocation Error! (float)\n");
    exit(1);
  }
}

void alocaInt(int **p, int tam){
  if((*p=(int*)realloc(*p,tam*sizeof(int)))==NULL){
    printf("\nDynamic Allocation Error! (int)\n");
    exit(1);
  }
}