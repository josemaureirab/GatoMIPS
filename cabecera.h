#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//ESTRUCTURA JUGADOR LA CUAL ALMACENA SU REGISTRO Y SU SIMBOLO EN LA PARTIDA

struct jugador{
    char registro[25];
	char identificador;
};

typedef struct jugador jugador;

//VARIABLES GLOBALES DEL CODIGO DEL LABORATORIO

//VARIABLES PARA TENER EN CONSIDERACIÓN LOS REGISTROS MIPS 
char* registros[32] = {"$zero", "$at", "$v0", "$v1", "$a0", "$a1", "$a2", "$a3", "$t0", "$t1", "$t2", "$t3", "$t4", "$t5", "$t6", 
	"$t7", "$s0", "$s1", "$s2", "$s3", "$s4", "$s5", "$s6", "$s7", "$t8", "$t9", "$k0", "$k1", "$gp", "$sp", "$fp", "$ra"};

//VARIABLES PARA ALMACENAR CUANTAS VECES SE PASA POR CADA UNA DE ESTAS ETAPAS EN LA REALIZACION DE UNA PARTIDA
int IF=0;
int ID=0;
int EX=0;
int MEM=0;
int WB=0;

//CABECERAS DE LAS FUNCIONES A UTILIZAR EN EL CODIGO DEL LABORATORIO

char* crear_tablero_defecto();
char* crear_tablero(FILE *archivo);
jugador* crear_jugador(FILE *archivo);
char* operacion_addi(FILE *archivo, char* tablero, jugador *jugador1, jugador *jugador2);
char* operacion_subi(FILE *archivo, char* tablero, jugador *jugador1, jugador *jugador2);
char* operacion_sw(FILE *archivo, char* tablero, jugador *jugador1, jugador *jugador2);
void mostrar_tablero(char* tablero);
void resultados(FILE *archivo, char *tablero, jugador *jugador1, jugador *jugador2);
void generar_archivos_de_salida(char* tablero,jugador *jugador1, jugador *jugador2);