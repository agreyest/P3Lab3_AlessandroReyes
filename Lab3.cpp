#include<iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <conio.h>
using namespace std;

//Funcion que crea matrices
int** CreateMatrix(int,int);
//Funcion que libere una matriz
void freeMatrix(int**&,int);
//Funcion que imprime una matriz
void printMatrix(int**,int, int);
//funcion para el juego de la vida conway
void LIVEorDEAD(int**, int,int,int);

int menu(){
	int retValue=0;
	while(retValue < 1 || retValue > 2){
		cout<<"BIENVENIDO AL JUEGO DE LA VIDA CONWAY!!!"<<endl
			<<"  1.- Jugar con matriz aleatorio"<<endl
			<<"  2.- Jugar con matriz predeterminada"<<endl
			<<"  3.- Salir"<<endl
			<<"Que opcion desea ver: ";
			
			cin>>retValue;
			
			if(retValue >= 0 && retValue <= 3){
				break;
			}else{
				cout<<endl<<"Opcion ingresada incorrecta, elija nuevamente"<<endl;
			}
			
			
	}//end while
	
	return retValue;
}//fin metodo de menu



int main(){
	int  opcion = menu();
	int seguir = 1;
	
	while(seguir == 1){
		switch(opcion){
			case 1:{//aleatorio
				int filas;
				int columnas;
				int turnos;
				int** Conway=NULL;
				
				cout<<endl<<"Ingrese el tamaño de x del tablero: ";
				cin>>filas;
				while(filas < 1){
					cout<<endl<<"intentelo de nuevo, el numero debe ser mayor o igual a 1: ";
					cin>>filas;
				}
				
				cout<<endl<<"Ingrese el tamaño de y del tablero: ";
				cin>>columnas;
				while(columnas < 1){
					cout<<endl<<"intentelo de nuevo, el numero debe ser mayor o igual a 1: ";
					cin>>columnas;
				}
				
				cout<<endl<<"Ingrese la cantidad de turnos por hacer: ";
				cin>>turnos;
				while(turnos < 1){
					cout<<endl<<"intentelo de nuevo, el numero debe ser mayor o igual a 1: ";
					cin>>turnos;
				}
				
				Conway = CreateMatrix(filas, columnas);
				printMatrix(Conway,filas,columnas);
				LIVEorDEAD(Conway, turnos, filas, columnas);
				
				freeMatrix(Conway,filas);
				opcion = menu();
				break;
			}//fin case 1
			
			case 2:{//predeterminada
				int turnos;
				int x=20,y=20;
				int temp_mat [20][20] = {
										{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
										{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0},
										{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
										{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0},
										{0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0},
										{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
										{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
										{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
										{0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
										{1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
										{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
										{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
										{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
										{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
										{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
										{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
										{0,0,1,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,0,0},
										{0,0,1,0,0,0,0,0,0,1,1,1,0,0,0,0,1,0,1,0},
										{0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
										{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
										};
				int ** mat = new int*[y];
				for(int i = 0; i < y ; i++){
					mat[i] = new int[x];
					for(int j = 0; j < x ; j++){
						mat[i][j] = temp_mat[i][j];
					}
				}

				cout<<endl<<"Ingrese la cantidad de turnos por hacer: ";
				cin>>turnos;
				while(turnos<1){
					cout<<endl<<"intentelo de nuevo, el numero debe ser mayor o igual a 1: ";
					cin>>turnos;
				}
				
				printMatrix(mat, x, y);
				LIVEorDEAD(mat, turnos, x, y);
				
				freeMatrix(mat,x);
				opcion = menu();
				break;
			}//fin case 2
			
			case 3:{
				cout<<endl<<"Gracias por entrar al sistema."<<endl;
				seguir=0;
				break;
			}//fin case 3
		}//fin del switch
	}//fin del while
	
}//fin del main


int** CreateMatrix(int filas, int columnas){
	int** matriz = NULL; 
	//crear el arreglo de apuntadores
	matriz = new int*[filas];
	
	//instanciar los arreglos de chars
	for(int i =0; i<filas;i++){
		matriz[i]=new int[columnas];
	} 
	
	for(int i = 0; i < filas; i++){
		for(int j = 0; j < columnas; j++){
			matriz[i][j] = rand()%2;
		}
	}
	return matriz;
}


void freeMatrix(int**& matriz, int size){
	for(int i = 0; i < size; i++){
		delete[] matriz[i];
	}
	
	//liberamos los apuntadores
	delete[] matriz;
	matriz = NULL;
}


void printMatrix(int** matriz, int filas, int columnas){
	for(int i = 0; i < filas; i++){
		cout<<"[";
		for(int j = 0; j < columnas; j++){
			cout<<matriz[i][j]<<",";
		}
		cout<<"]";
		cout<<endl;
	}
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
}

void LIVEorDEAD(int** matriz, int turns, int filas, int columnas){
	int** temporal = NULL; 
	temporal = CreateMatrix(filas, columnas);
	cout<<"temporal"<<endl;
	printMatrix(temporal,filas,columnas);
	
	for(int i = 0; i < turns; i++){
		
		for(int j = 0; j < filas; j++){
			for(int k = 0; k < columnas; k++){
				if(matriz[j][k] == 0 ){//if para chequear las casillas que esten muertes
					int cont_vivira = 0;//para contar los vecinos vivos
					
					if(j-1 >= 0 && k-1 >= 0){
						
						if(matriz[j][k] == 1){
							cont_vivira++;
						}
					}
					
					if(j-1 >= 0){
						if(matriz[j][k] == 1){
							cont_vivira++;
						}
					}
					
					if(j-1 >=0 && k+1 < columnas){
						if(matriz[j][k] == 1){
							cont_vivira++;
						}
					}
					
					if(k + 1 < columnas){
						if(matriz[j][k] == 1){
							cont_vivira++;
						}	
					}
					
					if(j +1 < filas && k +1 < columnas){
						if(matriz[j][k] == 1){
							cont_vivira++;
						}
					}
					
					if(i + 1 < filas){
						if(matriz[j][k] == 1){
							cont_vivira++;
						}
					}
					
					if(i + 1 < filas && k-1 >= 0){
						if(matriz[j][k] == 1){
							cont_vivira++;
						}
					}
					
					if(k-1 >= 0){
						if(matriz[j][k] == 1){
							cont_vivira++;
						}
					}
					
					if(cont_vivira == 3 ){
						temporal[j][k] = 1;
						cout<<"vivoooo"<<endl;
					}
					
				}
				else{//else para chequear las casillas que esten vivas
					int cont_live_die = 0;//nos va decir si sigue viva o muere
					
					if(j-1 >= 0 && k-1 >= 0){
						if(matriz[j][k] == 1){
							cont_live_die++;
						}
					}
					
					if(j-1 >= 0){
						if(matriz[j][k] == 1){
							cont_live_die++;
						}
					}
					
					if(j-1 >=0 && k+1 < columnas){
						if(matriz[j][k] == 1){
							cont_live_die++;
						}
					}
					
					if(k + 1 < columnas){
						if(matriz[j][k] == 1){
							cont_live_die++;
						}	
					}
					
					if(j +1 < filas && k +1 < columnas){
						if(matriz[j][k] == 1){
							cont_live_die++;
						}
					}
					
					if(i + 1 < filas){
						if(matriz[j][k] == 1){
							cont_live_die++;
						}
					}
					
					if(i + 1 < filas && k-1 >= 0){
						if(matriz[j][k] == 1){
							cont_live_die++;
						}
					}
					
					if(k-1 >= 0){
						if(matriz[j][k] == 1){
							cont_live_die++;
						}
					}
					
					if(cont_live_die != 3 && cont_live_die != 2){
						temporal[j][k] = 0;
						cout<<"F en"<<endl;
					}
					
				}
			}//fin for de columnas	
		}//fin for de filas
		cout<<"antes del cagadal"<<endl;
		printMatrix(matriz,filas,columnas);
		matriz = temporal;
		
		getch();
		printMatrix(matriz,filas,columnas);
	}//fin for de turnos
	cout<<"fin";
}








