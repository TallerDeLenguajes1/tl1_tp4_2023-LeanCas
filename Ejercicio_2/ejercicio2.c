#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<conio.h>


typedef struct {
	int TareaID; 
	char *Descripcion;
	int Duracion;
}Tarea;

typedef struct Nodo{
	Tarea T;
	struct Nodo *Siguiente;
}Tnodo;


//HACEMOS USO DE PUNTERO DOBLE

//FUNCIONES

void cargar (Tnodo** L);

void mostrar (Tnodo* L);

void buscarTarea (Tnodo* L);

void realizadas (Tnodo** Lpendientes, Tnodo** Lrealizadas);


int main (){
	
	Tnodo* cabezaPen = NULL; //Inicializamos la cabecera de la listas
	
	Tnodo* cabezaRea = NULL;
	
	cargar(&cabezaPen);
	
	mostrar(cabezaPen);
	
	buscarTarea (cabezaPen);
	
	realizadas (&cabezaPen, &cabezaRea);
	
	mostrar(cabezaRea);
	
	
	
	
	
	return 0;
	
}


void cargar (Tnodo** L){
	
	printf("\n\n===== CARGAR TAREA =====");
		
	
	int bandera = 1, i = 1;
	
	Tnodo* nuevo;

	char descr[100];
	
	srand(time(NULL));
		
	while(bandera == 1){
		
		fflush(stdin);
		
		nuevo = (Tnodo*) malloc (sizeof(Tnodo)); //Reservamos memoria para el nuevo nodo
		
		//CARGAMOS LOS DATOS DEL NUEVO NODO
		
		nuevo->T.TareaID = i;
		
		printf("\nIngresar descripcion de la tarea %d : ",i);
		
		gets(descr);
		
		nuevo->T.Descripcion = (char*) malloc (sizeof(char) * (strlen(descr) + 1));
		
		strcpy(nuevo->T.Descripcion,descr);
		
		nuevo->T.Duracion = rand() % 91 + 10;
		
		//INSERTAMOS AL FINAL LA TAREA
		
		Tnodo* aux = *L;
		
		if(*L == NULL){
			
			*L = nuevo;
			
			nuevo->Siguiente = NULL;
			
		}else{
					
			while(aux->Siguiente != NULL){
					
				aux = aux->Siguiente;
				
			}
			
			aux->Siguiente = nuevo;
			
			nuevo->Siguiente = NULL;
			
		}
		
		i++;
		
		printf("\nDesea ingresar otra tarea : \n1)-SI\n2)-NO\n>>>>");
		
		scanf("%d",&bandera);
			
	}
	
	printf("\n======================");
			
}


void mostrar (Tnodo* L){
	
	printf("\n\n===== MOSTRAR TAREA =====");
	
	Tnodo* aux = L;
	               
	while(aux != NULL){
	    	
		printf("\n\n===== TAREA %d =====",aux->T.TareaID);
                                                        
		printf("\nDescripcion : %s",aux->T.Descripcion);
				
		printf("\nDuracion : %d",aux->T.Duracion);
		
		aux = aux->Siguiente;
		
	}
	
		
	printf("\n======================");
			
	
}


void buscarTarea (Tnodo* L){
	
	int idTarea, bandera = 0;
	
	printf("\n\n===== BUSCAR TAREA =====");
	
	printf("\nIngrese la tarea a buscar : ");
	
	scanf("%d",&idTarea);
	
	Tnodo* aux = L;
	
	while(aux->T.TareaID != idTarea && aux->Siguiente != NULL){
		
		aux = aux->Siguiente;
		
	}
		
	if(aux->T.TareaID == idTarea){
		
		printf("\n\n===== TAREA %d =====",aux->T.TareaID);
                                                        
		printf("\nDescripcion : %s",aux->T.Descripcion);
				
		printf("\nDuracion : %d",aux->T.Duracion);
		
		bandera = 1;
		
	}
	
	if(bandera == 0){
		
		printf("\nNo se encontro la tarea...");
		
	}
	
	printf("\n======================");
	
}


void realizadas (Tnodo** Lpendientes, Tnodo** Lrealizadas){
	
	int opcion;
	
	Tnodo* auxPend = *Lpendientes;
	
	
	Tnodo* auxReal = *Lrealizadas;
	
	Tnodo* anterior = NULL;
    //recorrer realizadas para llegar al final

	while(auxReal != NULL){

		auxReal = auxReal->Siguiente;

	}

	while(auxPend != NULL){
	    	
		printf("\n\n===== TAREA %d =====",auxPend->T.TareaID);
                                                        
		printf("\nDescripcion : %s",auxPend->T.Descripcion);
				
		printf("\nDuracion : %d",auxPend->T.Duracion);
		
		
		printf("\nSe realizo la tarea ?\n1)-Si\n2)-NO\n>>>>>>");
		
		scanf("%d",&opcion);
		
		if(opcion == 1){
            //desenganchar nodo
            if (anterior==NULL){ 

				anterior=auxPend->Siguiente;

			}else{

				anterior->Siguiente=auxPend->Siguiente;

			}

                
            //mover
						
			auxReal->Siguiente = auxPend;
			//Para que me pare en el nodo seguiente
			auxPend = auxPend->Siguiente;
			//para que real se pare en el ultimo nodo agregado
			auxReal=auxReal->Siguiente;

			auxReal->Siguiente=NULL;
			  
		}
        else{

			//PARA NO PERDER EL NODO "ANTERIOR"
			anterior=auxPend;

			auxPend = auxPend->Siguiente;

        }
        
	}
		
}


