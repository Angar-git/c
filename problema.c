#include <stdio.h>

int Recibe_Arreglos(int id[],float calif, float tiempo, int lim);
void Ordena_Tiempo(int id[],float calif[], float tiempo[], int num);
void Ordenar_Lista(int id[], float calif[], int num);
int main(){
	
	int i, num, cf, tm, clave;
	
	do{
		printf("Ingrese el numero de alumnos: ");
		scanf("%d", &num);
	}while(num<1 || num>30);
	
	float calif[num], tiempo[num];
	int id[num];
	
	for(i=0; i<num; i++){
		printf("\nAlumno %d: \n", i+1);
		printf("Numero de lista del alumno: ");
		scanf("%d", &id[i]);
		printf("\nCalificacion: ");
		scanf("%f", &calif[i]);
		printf("\nTiempo de respuesta: ");
		scanf("%f", &tiempo[i]);
		cf=calif[i];
		tm=tiempo[i];
		if(Recibe_Arreglos(id,cf,tm,i) == 1){
			i--;
		}
	}
	Ordena_Tiempo(id,calif,tiempo,num);
	Ordenar_Lista(id,calif,num);
}

int Recibe_Arreglos(int id[],float calif, float tiempo, int lim){
	
	int i, j, t;
	float time;
	
		for(i=0; i<lim; i++){
		for(j=i+1; j<lim; j++){
			if(id[i]==id[j]){
			printf("Numero de lista repetidos.\n");
			return 1;
			}
		}
	}
	
	t= tiempo;
	time = (t+1)-tiempo;
	if(calif<0 || calif>100){
		printf("Error en calif.");
		return 1;
	}else if(time<0.40 || time>1 || t>60 || t<0){
		printf("Error en time");
		return 1;
	}
	
}


void Ordena_Tiempo(int id[],float calif[], float tiempo[], int num){
	
	int i, j, k, x, y, min, iguales=1;
	
	for(i=0; i<num-1; i++){
  		min=i;
  		for(j=i+1; j<num; j++){
  			if(tiempo[j]<tiempo[min]){
  				min=j;
			}
		}
		
		if(min != i){
			k=tiempo[i];
			tiempo[i]=tiempo[min];
			tiempo[min]=k;
			
			x=calif[i];
			calif[i]=calif[min];
			calif[min]=x;
			
			y=id[i];
			id[i]=id[min];
			id[min]=y;
			
		}
	}
	for(i=0;i<num-1;i++)
	{
		if(tiempo[i]==tiempo[i+1])
		{
			iguales=1;
		}
		else
		{
			iguales=2;
			break;
		}
		
	}
	if(iguales==2)
	{
		int suma=(num/2);
		iguales=3;
		for(i=0; i<num;i++)
		{
			if(i<suma)
			{
				calif[i]+=5.00;	
			}else
			{
				if(tiempo[i]==tiempo[i-1] && iguales==3)
				{
					calif[i]+=5.00;	
				}
				else
				{
					calif[i]-=5.00;
					iguales=4;	
				}
			}		
		}
	}
	else
	{
		printf("Todos los alumnos contestaron en el mismo tiempo el examen \n");
		printf("No se descuentan ni agregan puntos \n");
	}
	
	
}

void Ordenar_Lista(int id[], float calif[], int num){
	int i, j, min, k;
	float x;
	
	for(i=0; i<num-1; i++){
  		min=i;
  		for(j=i+1; j<num; j++){
  			if(id[j]<id[min]){
  				min=j;
			}
		}
		
		if(min != i){
			k=id[i];
			id[i]=id[min];
			id[min]=k;
			
			x=calif[i];
			calif[i]=calif[min];
			calif[min]=x;
		}
	}
	
	for(i=0; i<num;i++){
		printf("Numero de lista: %d    Calificacion: %.2f", id[i], calif[i]);
		printf(" \n _____________________ \n");
	}
	
}


