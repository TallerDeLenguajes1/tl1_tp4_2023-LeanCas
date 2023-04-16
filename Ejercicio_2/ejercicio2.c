#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


typedef struct Tarea {
	int TareaID; //Numerado en ciclo iterativo
	char *Descripcion;
	int Duracion; // entre 10 – 100
}tarea;

void inicializar (tarea **lista, int longitud);

void cargar (tarea **lista, int longitud);

void realizadas (tarea **lista, int longitud,tarea **realizadas);

void mostrar (tarea **lista, int longitud);

void buscarTareaPorId (tarea **lista, int longitud);

int main (){
	
	int cant_Tareas;
	
	tarea **lista_Tareas, **lista_realizadas;
	
	printf("\nIngrese cuantas tareas se deben realizar : ");
	
	scanf("%d",&cant_Tareas);
	
	lista_Tareas = (tarea**) malloc (sizeof(tarea*) * cant_Tareas);
	
	lista_realizadas = (tarea**) malloc (sizeof(tarea*) * cant_Tareas);
	
	inicializar(lista_Tareas,cant_Tareas);
	
	cargar(lista_Tareas,cant_Tareas);
	
	realizadas(lista_Tareas,cant_Tareas,lista_realizadas);
	
	printf("\n\n\t===== TAREAS REALIZADAS =====");
	
	mostrar(lista_realizadas,cant_Tareas);
	
	printf("\n\n\t===== TAREAS PENDIENTES =====");
	
	mostrar(lista_Tareas,cant_Tareas);
	
	
	return 0;
}

void inicializar (tarea **lista, int longitud){
	
	int i;
	
	for (i=0 ; i<longitud ; i++){
		
		lista[i] = NULL;
		
	}
		
}

void cargar (tarea **lista, int longitud){
	
	int i;
	
	char descripAux[100];
	
	
	for(i=0 ; i<longitud ; i++){
		
		fflush(stdin);
		
		lista[i] = (tarea*) malloc(sizeof(tarea));

		srand(time(NULL));
		
		lista[i]->TareaID = i+1;
		
		printf("\n\nIngresar la descripcion de la tarea %d : ",i+1);
		
		gets(descripAux);
		
		lista[i]->Descripcion = (char*) malloc (sizeof(char) * strlen(descripAux));
		
		strcpy(lista[i]->Descripcion,descripAux);
		
		lista[i]->Duracion = rand() % 91 + 10;
		
	}
		
}


void realizadas (tarea **lista, int longitud,tarea **realizadas){
	
	int i,eleccion;
	
	for(i=0 ; i<longitud ; i++){
		
		realizadas[i] = (tarea*) malloc(sizeof(tarea));
		
		printf("\n\n===== TAREA %d =====",lista[i]->TareaID);
		
		printf("\nDescripcion : %s",lista[i]->Descripcion);
		
		printf("\nDuracion : %d",lista[i]->Duracion);
		
		printf("\nSe realizo la tarea ? \n1)-SI\n2)-NO\n>>>>>>");
		
		scanf("%d",&eleccion);
		
		if(eleccion == 1){
			
			
			realizadas[i] = lista[i];
			
			lista[i] = NULL;
			
			
		}else {
			
			realizadas[i] = NULL;
			
		}
			
	}	
	
}

void mostrar (tarea **lista, int longitud){
	
	int i;
	
	for(i=0 ; i<longitud ; i++){  
	
		if(lista[i] != NULL ){
	                	
			printf("\n\n===== TAREA %d =====",lista[i]->TareaID);
			
			printf("\nDescripcion : %s",lista[i]->Descripcion);
			
			printf("\nDuracion : %d",lista[i]->Duracion);
			
		}   
	
	}
	
}

void buscarTareaPorId (tarea **lista, int longitud){
	
	printf("\nIngrese la id de la tarea buscada : ");
	
	scanf("%d",&idTarea);
	
	if(lista[idTarea] != NULL){
		
		printf("\n\n===== TAREA %d =====",lista[idTarea]->TareaID);
			
		printf("\nDescripcion : %s",lista[idTarea]->Descripcion);
			
		printf("\nDuracion : %d",lista[idTarea]->Duracion);
			
	}else {
		
		printf("\nLa id de la tarea no existe ");
	}
	
		
}
