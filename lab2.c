
#include "cabecera.h"





//	función que crea un arreglo de caracteres que representa el tablero del juego, este tablero se crea por defecto como uno de 9 posiciones.

char* crear_tablero_defecto(){
	int i;
	char *tablero=NULL;
	tablero=(char*)calloc(9,sizeof(char));
	for(i=0;i<=9;i++){
		tablero[i]=' ';
	}


	return tablero;
}
// función que crea un arreglo de caracteres que representa el tablero del juego, este tablero se crea según las posiciones que hayan sido indicadas en las instrucciones MIPS.

char* crear_tablero(FILE *archivo){

	int size_dashboard;
	int i;
	char *tablero=NULL;
	char *dato1=(char*)malloc(sizeof(char)*20);
	char *dato2=(char*)malloc(sizeof(char)*20);
	char *dato3=(char*)malloc(sizeof(char)*20);
	char *dato4=(char*)malloc(sizeof(char)*20);
	int dato5;
	fscanf(archivo, "%[^,] %s %[^,] %s %d\n",dato1,dato2,dato3,dato4,&dato5);
	if(strcmp(dato3,"$sp")==0){
		size_dashboard=abs(dato5/4);
		tablero=(char*)calloc(size_dashboard,sizeof(char));
		for(i=0;i<=size_dashboard;i++){
			tablero[i]=' ';
			}
		}
	else{
		tablero=crear_tablero_defecto();
	}
		
	return tablero;
	}


// función que crea una estructura jugador, el cual tiene como atributos el registro MIPS con el que fue indicado en las instrucciones y el simbolo que usará en la partida a modo de identificador.


jugador* crear_jugador(FILE *archivo){
	jugador *jugadorx;
	jugadorx=(jugador*)malloc(sizeof(jugador));
	char *dato1=(char*)malloc(sizeof(char)*20);
	char *dato2=(char*)malloc(sizeof(char)*20);
	char *dato3=(char*)malloc(sizeof(char)*20);
	char *dato4=(char*)malloc(sizeof(char)*20);
	int dato5;

	fscanf(archivo, "%[^,] %s %[^,] %s %d\n",dato1,dato2,dato3,dato4,&dato5);
	

	
	strcpy(jugadorx->registro,dato1);

	
	if(dato5==1){
		jugadorx->identificador='X';
	}
	else if(dato5==2){
		jugadorx->identificador='O';
	}

	IF+=1;
	ID+=1;
	EX+=1;
	WB+=1;

	return jugadorx;
}

//función que recrea la operación addi de ensamblador y suma a las etapas en las cuales corresponda una unidad para indicar por donde pasaron las instrucciones, esta función añade el simbolo de un jugador al tablero.
char* operacion_addi(FILE *archivo, char* tablero, jugador *jugador1, jugador *jugador2){
	char *dato1=(char*)malloc(sizeof(char)*20);
	char *dato2=(char*)malloc(sizeof(char)*20);
	char *dato3=(char*)malloc(sizeof(char)*20);
	char *dato4=(char*)malloc(sizeof(char)*20);
	int dato5;
	fscanf(archivo, "%[^,] %s %[^,] %s %d\n",dato1,dato2,dato3,dato4,&dato5);
	if(strcmp(dato1,jugador1->registro)==0){
		if(tablero[dato5-1]==' '){
			tablero[dato5-1]=jugador1->identificador;
		}
	}
	else if(strcmp(dato1,jugador2->registro)==0){
		if(tablero[dato5-1]==' '){
			tablero[dato5-1]=jugador2->identificador;
		}
	}

	IF+=1;
	ID+=1;
	EX+=1;
	WB+=1;

	return tablero;
}
//función que recrea la operación subi de ensamblador y suma a las etapas en las cuales corresponda una unidad para indicar por donde pasaron las instrucciones, esta función borra el simbolo de un jugador en el tablero.
char* operacion_subi(FILE *archivo, char* tablero, jugador *jugador1, jugador *jugador2){
	char *dato1=(char*)malloc(sizeof(char)*20);
	char *dato2=(char*)malloc(sizeof(char)*20);
	char *dato3=(char*)malloc(sizeof(char)*20);
	char *dato4=(char*)malloc(sizeof(char)*20);
	int dato5;
	int posicion;
	fscanf(archivo, "%[^,] %s %[^,] %s %d\n",dato1,dato2,dato3,dato4,&dato5);
	posicion=dato5-1;
	if(strcmp(dato1,jugador1->registro)==0){
		if(tablero[posicion]==jugador1->identificador){
			tablero[posicion]=' ';
		}
	}
	else if(strcmp(dato1,jugador2->registro)==0){
		if(tablero[posicion]==jugador2->identificador){
			tablero[posicion]=' ';
		}
	}

	IF+=1;
	ID+=1;
	EX+=1;
	WB+=1;

	return tablero;
}

//función que recrea la operación sw de ensamblador y suma a las etapas en las cuales corresponda una unidad para indicar por donde pasaron las instrucciones, esta función añade el simbolo de un jugador al tablero.
char* operacion_sw(FILE *archivo, char* tablero, jugador *jugador1, jugador *jugador2){
	char *dato1=(char*)malloc(sizeof(char)*20);
	char *dato2=(char*)malloc(sizeof(char)*20);
	int dato3;
	char *dato4=(char*)malloc(sizeof(char)*20);
	char *dato5=(char*)malloc(sizeof(char)*20);
	fscanf(archivo, "%[^,] %s %d %[^$] %[^)] ",dato1,dato2,&dato3,dato4,dato5);
	if(strcmp(dato1,jugador1->registro)==0){
		if(tablero[dato3/4]==' '){
			tablero[dato3/4]=jugador1->identificador;
		}
	}
	else if(strcmp(dato1,jugador2->registro)==0){
		if(tablero[dato3/4]==' '){
			tablero[dato3/4]=jugador2->identificador;
		}
	}
	IF+=1;
	ID+=1;
	EX+=1;
	MEM+=1;

	return tablero;
}

//funcion que escribe en el archivo correspondiente
//el tablero de la partida realizada
void mostrar_tablero(char* tablero){
		printf("[%c|%c|%c]\n",tablero[0],tablero[1],tablero[2]);
		printf("[%c|%c|%c]\n",tablero[3],tablero[4],tablero[5]);
		printf("[%c|%c|%c]\n",tablero[6],tablero[7],tablero[8]);
	}

// funcion que verifica el resultado de la partida y escribe en caso de un ganador en
// el archivo correspondiente el resultado, el ganador y el registro
void resultados(FILE *archivo, char *tablero, jugador *jugador1, jugador *jugador2){


	fprintf(archivo,"[%c|%c|%c]\n",tablero[0],tablero[1],tablero[2]);
	fprintf(archivo,"[%c|%c|%c]\n",tablero[3],tablero[4],tablero[5]);
	fprintf(archivo,"[%c|%c|%c]\n",tablero[6],tablero[7],tablero[8]);

	if(tablero[0]==tablero[1] && tablero[1]==tablero[2]){
		if(tablero[0]==jugador1->identificador){
			fprintf(archivo, "\nEl ganador es el simbolo X, jugador con el registro: %s", jugador1->registro);
		}
		else{
			fprintf(archivo, "\nEl ganador es el simbolo O, jugador con el registro: %s", jugador2->registro);
		}
	}
	else if(tablero[3]==tablero[4] && tablero[4]==tablero[5]){
		if(tablero[3]==jugador1->identificador){
			fprintf(archivo, "\nEl ganador es :X, jugador con el registro: %s", jugador1->registro);
		}
		else{
			fprintf(archivo, "\nEl ganador es :O, jugador con el registro: %s", jugador2->registro);
		}
	}
	else if(tablero[6]==tablero[7] && tablero[7]==tablero[8]){
		if(tablero[6]==jugador1->identificador){
			fprintf(archivo, "\nEl ganador es :X, jugador con el registro: %s", jugador1->registro);
		}
		else{
			fprintf(archivo, "\nEl ganador es :O, jugador con el registro: %s", jugador2->registro);
		}
	}
	else if(tablero[0]==tablero[3] && tablero[3]==tablero[6]){
		if(tablero[0]==jugador1->identificador){
			fprintf(archivo, "\nEl ganador es :X, jugador con el registro: %s", jugador1->registro);
		}
		else{
			fprintf(archivo, "\nEl ganador es :O, jugador con el registro: %s", jugador2->registro);
		}
	}
	else if(tablero[1]==tablero[4] && tablero[4]==tablero[7]){
		if(tablero[1]==jugador1->identificador){
			fprintf(archivo, "\nEl ganador es :X, jugador con el registro: %s", jugador1->registro);
		}
		else{
			fprintf(archivo, "\nEl ganador es :O, jugador con el registro: %s", jugador2->registro);
		}
	}
	else if(tablero[6]==tablero[4] && tablero[4]==tablero[2]){
		if(tablero[6]==jugador1->identificador){
			fprintf(archivo, "\nEl ganador es :X, jugador con el registro: %s", jugador1->registro);
		}
		else{
			fprintf(archivo, "\nEl ganador es :O, jugador con el registro: %s", jugador2->registro);
		}
	}
	else if(tablero[2]==tablero[5] && tablero[5]==tablero[8]){
		if(tablero[2]==jugador1->identificador){
			fprintf(archivo, "\nEl ganador es :X, jugador con el registro: %s", jugador1->registro);
		}
		else{
			fprintf(archivo, "\nEl ganador es :O, jugador con el registro: %s", jugador2->registro);
		}
	}
	else if(tablero[0]==tablero[4] && tablero[4]==tablero[8]){
		if(tablero[0]==jugador1->identificador){
			fprintf(archivo, "\nEl ganador es :X, jugador con el registro: %s", jugador1->registro);
		}
		else{
			fprintf(archivo, "\nEl ganador es :O, jugador con el registro: %s", jugador2->registro);
		}
	}
	else if(tablero[0]==' '|| tablero[1]==' '||tablero[2]==' '||tablero[3]==' '||tablero[4]==' '||tablero[5]==' '||tablero[6]==' '||tablero[7]==' '||tablero[8]==' '){
		fprintf(archivo, "\nNo hay ganadores, ya que, faltaron jugadas para completar la partida");
	}
	else{
		fprintf(archivo, "\n Se ha producido un empate");
	}
}

//•	función que genera los dos archivos con los resultados de la partida y con los contadores de las etapas del camino de dato.

void generar_archivos_de_salida(char* tablero,jugador *jugador1, jugador *jugador2){
	FILE *resultado;
	FILE *etapas;
	char *nombre_resultado=(char*)malloc(sizeof(char)*20);
	char *nombre_etapas=(char*)malloc(sizeof(char)*20);
	printf("\nIngrese el nombre del archivo contenedor del resultado (incluyendo el .txt)\n");
	scanf("%s", nombre_resultado);
	printf("\nIngrese el nombre del archivo contenedor de las etapas (incluyendo el .txt)\n");
	scanf("%s", nombre_etapas);
	resultado=fopen(nombre_resultado,"w");
	etapas=fopen(nombre_etapas,"w");
	resultados(resultado, tablero, jugador1, jugador2);
	fprintf(etapas, "ETAPA : CANTIDAD\n");
	fprintf(etapas, "IF : %d \n",IF);
	fprintf(etapas, "ID: %d \n",ID);
	fprintf(etapas, "EX : %d \n",EX);
	fprintf(etapas, "MEM : %d \n",MEM);
	fprintf(etapas, "WB : %d \n",WB);

	fclose(etapas);
	fclose(resultado);
}

int main(){
	int contador;
	jugador *jugador1;
	jugador *jugador2;
	jugador1=(jugador*)malloc(sizeof(jugador));
	jugador2=(jugador*)malloc(sizeof(jugador));
	char *tablero=(char*)calloc(9,sizeof(char));
	tablero=crear_tablero_defecto();
	char *dato1=(char*)malloc(sizeof(char));
	char *nombreJugadas=(char*)malloc(sizeof(char)*20);
	printf("Ingrese el nombre del archivo contenedor de las jugadas (incluyendo el .txt)");
	scanf("%s", nombreJugadas);
	FILE *archivo;
	archivo=fopen(nombreJugadas,"r");
	contador=0;
	while(feof(archivo)==0){
		contador+=1;
		fscanf(archivo, "%s", dato1);
		if(strcmp("addi", dato1)==0){
			if(contador==1){
				jugador1=crear_jugador(archivo);
			}
			else if(contador==2){
				jugador2=crear_jugador(archivo);
			}
			else if(contador==3){
				tablero=crear_tablero(archivo);
			}
			else{
				tablero=operacion_addi(archivo,tablero,jugador1,jugador2);
			}
		}
		else if(strcmp("subi", dato1)==0){
			tablero=operacion_subi(archivo,tablero,jugador1,jugador2);
		}
		else if(strcmp("sw", dato1)==0){
			tablero=operacion_sw(archivo,tablero,jugador1,jugador2);
			
		}
	}
	mostrar_tablero(tablero);
	generar_archivos_de_salida(tablero,jugador1,jugador2);
	free(tablero);
	free(jugador1);
	free(jugador2);
	free(dato1);
	fclose(archivo);
	return 0;
}


