//Villarreal Razo Carlos Gabriel

#include <stdio.h>
#include <stdlib.h>

int FiboIterativo(int n);
int FiboRecursivo(int n);
int multiplicacion(int x, int y);
void OrdenarArreglo(int *arreglo, int n);

int main(){
	
	int op=0, n=0, x, y, i;
	int *arreglo;
	
	while(op!=5){
		printf("Ingresa el numero de opcion que deseas llevar a cabo:\n");
		printf("1. Fibonacci iterativo.\n2. Fibonacci recursivo.\n3. Multiplicacion\n4. Ordenar arreglo.\n5. Salir\n\n");
		scanf("%d",&op);
		
		switch(op){
			case 1:
				printf("\nIngresa el termino que quieres calcular de la serie de Fibonacci: ");
				scanf("%d",&n);
				printf("\nEl termino %d es: %d\n\n", n, FiboIterativo(n));
			break;
			case 2:
				printf("\nIngresa el termino que quieres calcular de la serie de Fibonacci: ");
				scanf("%d",&n);
				printf("\nEl termino %d es: %d\n\n", n, FiboRecursivo(n));
			break;
			case 3:
				printf("\nIngresa el termino X: ");
				scanf("%d",&x);
				printf("\nIngresa el termino Y: ");
				scanf("%d",&y);
				printf("\nEl resultado de la multiplicacion entre %d y %d es: %d\n\n", x, y, multiplicacion(x,y));
			break;
			case 4:
				printf("\nIngresa la cantidad de numeros que deseas en el arreglo: ");
				scanf("%d",&n);

				arreglo=(int *)malloc(n*sizeof(int));

				i=0;
				while(i<n){
					printf("\nIngresa el elemento %d del arreglo: ",i+1);
					scanf("%d",&arreglo[i]);
					i++;
				}

				printf("\nEl arreglo original es:\n");
				i=0;
				while(i<n){
					printf("%d\t",arreglo[i]);
					i++;
				}

				OrdenarArreglo(arreglo,n);

				printf("\nEl arreglo ordenado es:\n");
				i=0;
				while(i<n){
					printf("%d\t",arreglo[i]);
					i++;
				}
				printf("\n\n");

			break;
			case 5:
				printf("Saliendo del programa\n\n");	
			break;
			default:
				printf("Ingresa un numero de opcion correcto\n\n");	
		}
	}
	return 0;
}

int FiboIterativo(int n){
	int a=0, b=1, c=0, i;
	if(n<2){
		return n;
	}
	for(i=0; i<=n-2; i++){
		c=a+b;
		a=b;
		b=c;
	}
	
	return c;
}

int FiboRecursivo(int n){
	if(n<2){
		return n;
	}else{
		return FiboRecursivo(n-1)+FiboRecursivo(n-2);
	}
}

int multiplicacion(int x, int y){
	int z;
	if(y==0){
		return 0;
	}
	z=multiplicacion(x,y/2);
	if(y%2==0){
		return 2*z;
	}else{
		return x+2*z;
	}
}

void OrdenarArreglo(int *arreglo, int n){
	int i=0, j=0, aux, temp;
	
	while(i<n-1){
		j=i+1;
		aux=i;
		
		while(j<n){
			if(arreglo[aux]>=arreglo[j]){
				aux=j;
			}
			j++;
		}

		temp=arreglo[i];
		arreglo[i]=arreglo[aux];
		arreglo[aux]=temp;
		i++;
	}
}
