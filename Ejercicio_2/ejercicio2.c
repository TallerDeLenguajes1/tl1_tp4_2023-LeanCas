#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


typedef struct {
	int TareaID; 
	char *Descripcion;
	int Duracion;
}Tarea;

struct Nodo{
	Tarea T;
	struct Nodo *Siguiente;
};

typedef struct Nodo* lista;


lista inicializar ();

lista insertaAlFinal(lista L,lista nuevo);

lista cargar (lista L);

void mostrar (lista L);

void buscarTarea (lista L);






int main (){
	
	lista pendientes, realizadas;
			
	pendientes = inicializar();
	
	pendientes = cargar(pendientes);
	
	mostrar(pendientes);
	
	buscarTarea(pendientes);
	
	
	
	
	
	
	
	
	
	return 0;
	
}

lista inicializar (){
	
	return NULL;
		
}

lista insertaAlFinal(lista L, lista nuevo) {
	nuevo->Siguiente = NULL;
    if (L == NULL) {
        L = nuevo;
    } else {
        lista aux = L;
        while (aux->Siguiente != NULL) {
            aux = aux->Siguiente;
        }
        aux->Siguiente = nuevo;
    }
    return L;
}

lista cargar (lista L){
		
	char descripAux[100];
    lista nuevo;
	int i=0, bandera=1;
	
	while(bandera == 1){
		
		fflush(stdin);
		
		nuevo = (lista) malloc (sizeof(struct Nodo));
		
		nuevo->T.TareaID = i++;
		
		printf("\n\nIngresar la descripcion de la tarea %d : ",i);
	
		gets(descripAux);
		
		nuevo->T.Descripcion = (char*) malloc (sizeof(char) * (strlen(descripAux) + 1));
		
		strcpy(nuevo->T.Descripcion,descripAux);
		
		nuevo->T.Duracion = rand() % 91 + 10;
		
		L=insertaAlFinal(L,nuevo);
		
		printf("\nDesea cargar otra tarea ? \n1)-SI\n2)-NO\n>>>>");
		
		scanf("%d",&bandera);
		
	}
	
	return L;
			
}


void mostrar (lista L){
	
	lista aux = L;
	               
	while(aux != NULL){
	    	
		printf("\n\n===== TAREA %d =====",aux->T.TareaID);
                                                        
		printf("\nDescripcion : %s",aux->T.Descripcion);
				
		printf("\nDuracion : %d",aux->T.Duracion);
		
		aux = aux->Siguiente;
		
	}
			
	
}

void buscarTarea (lista L){
	
	int idTarea;
	
	lista aux = L;
	
	printf("\n===== BUSCAR TAREA =====");
	
	printf("\nIngrese el ID de la tarea : ");
	
	scanf("%d",&idTarea);
	
	while(aux != NULL){
		
               
		if(aux->T.TareaID == idTarea){
	    	
			printf("\n\n===== TAREA %d =====",aux->T.TareaID);
	                                                        
			printf("\nDescripcion : %s",aux->T.Descripcion);
					
			printf("\nDuracion : %d",aux->T.Duracion);
			
		}
		
		aux = aux->Siguiente;
			
	}
	

	
	
}



/*void realizadas (tarea **lista, int longitud,tarea **realizadas){
	
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
	
	int idTarea;
	 
	printf("\nIngrese la id de la tarea buscada : ");
	
	scanf("%d",&idTarea);
	
	if(lista[idTarea] != NULL){
		
		printf("\n\n===== TAREA %d =====",lista[idTarea]->TareaID);
			
		printf("\nDescripcion : %s",lista[idTarea]->Descripcion);
			
		printf("\nDuracion : %d",lista[idTarea]->Duracion);
			
	}else {
		
		printf("\nLa id de la tarea no existe ");
	}
	
		
}*/
