//Bibliotecas
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <cstring>
#include <locale.h>
#include <fstream>
#include <iostream>
using namespace std;

string linea;

//TDA
struct vehiculo{
	//Atributos
	char modelo[20];
	char marca[20];
	int year;
	int numeroPasajeros;
	int numeroPuertas;
	char color[20];
	char placa[20];
	char propietario[20];
	int tenencia;
	int infracciones;
	char transmision[20];
	//Apuntadores
	vehiculo *next;
	vehiculo *prev;
};

vehiculo *PRIMERO=NULL;
vehiculo *ULTIMO=NULL;

//Prototipos de funciones
void menu(void);
void insertarInicio(void);
void insertarFinal(void);
void eliminarInicio(void);
void eliminarFinal(void);
void mostrarVehiculos(void);
void buscarFecha(void);
void buscarPropietario(void);
void ordenarPorYear(void);
void respaldar(void);
void leer(void);


// Funcion principal
int main(void){	
	//variables
	int opcion;
	
	//switch
	do {
		system("cls");
		menu();
		cout << "\nIngresa una opcion de menu --> ";
		cin >> opcion;
		switch(opcion) {
			case 1:
				insertarInicio();
				break;
			case 2:
				insertarFinal();
				break;
			case 3:
				eliminarInicio();
				break;
			case 4:
				eliminarFinal();
				break;
			case 5:
				mostrarVehiculos();
				break;
			case 6:
				buscarFecha();
				break;
			case 7:
				buscarPropietario();
				break;
			case 8:
				ordenarPorYear();
				break;
			case 9:
				respaldar();
				break;
			case 10:
				leer();
				break;
			case 0:
				cout << "Seleccionaste salir" << endl;
				break;
			default:
				cout << "Opcion no valida" << endl;
				break;
		}//switch
		system("pause");
	} while (opcion != 0);	
		
	return 0;
}//main

//Funciones----------------------------------------------------------------

//#0 Funcion de menu, interfaz del usuario
void menu(void){
	cout << "				Padron vehicular" << endl;
	cout << "______________________________________________________________" 	 << endl;
	cout << "!Bienvenido al padron vehicular! seleccione una opcion\n"		     << endl;
	
	cout << "1) Agregar un vehiculo al inicio de la lista" 						 << endl;
	cout << "2) Agregar un vehiculo al final de la lista" 						 << endl;
	cout << "3) Elimiar el primer vehiculo de la lista" 						 << endl;
	cout << "4) Elimiar el ultimo vehiculo de la lista" 					   	 << endl;
	cout << "5) Mostrar todos los vehiculos registrados" 					 	 << endl;
	cout << "6) Buscar por el año de un vehiculo" 							 	 << endl;
	cout << "7) Buscar por propietario de un vehiculo"			 			 	 << endl;
	cout << "8) Ordenar los vehiculos en orden creciente por el año del vehiculo"<< endl;
	cout << "9) Respaldar informacion en un archivo" 							 << endl;
	cout << "10) Consultar los datos del archivo\n" 							 << endl;
	
	
	cout << "0) Salir" 															<< endl;
}//menu

//#1 Funcion para agregar un vehiculo al inicio de la lista
void insertarInicio(void){
	// 1)Declarar la variable apuntador
	vehiculo *nuevo;
	
	// 2) Solicitar memoria
	nuevo = (vehiculo *) malloc(sizeof(vehiculo));
	
	// 3) Validar el apuntador
	if (nuevo == NULL){
		cout << "No hay memoria suficiente" << endl;
		return;
	}//if
	
	// 4)Guardar informacion
	cout << "Ingresa los datos del vehiculo" << endl;
	cout << "--------------------------------" << endl;
	cin.ignore();
	
	cout << "Modelo -->" << endl;
	cin.getline(nuevo->modelo,20,'\n');
	
	cout << "Marca -->" << endl;
	cin.getline(nuevo->marca,20,'\n');
	
	do {
		//Validar que sea una fecha correcta
		cout << "Año del vehiculo (entre 1950 y 2022)-->" << endl;
		cin >> nuevo->year;
		if(nuevo->year < 1950 || nuevo->year > 2022){
			cout << "Año invalido" << endl;
			cin.ignore();
		}//if
	}while(nuevo->year < 1950 || nuevo->year > 2022);
	
	do {
		//Validar que sea un numero de pasajeros sea mayor a 0
		cout << "Numero de pasajeros -->" << endl;
		cin >> nuevo->numeroPasajeros;
		if(nuevo->numeroPasajeros <= 0){
			cout << "El vehiculo tiene que tener minimo 1 pasajero" << endl;
		}
	}while(nuevo->numeroPasajeros <= 0);
	
	do {
		//Validar que sea un numero de puertas sea mayor a 0
		cout << "Numero de puertas -->" << endl;
		cin >> nuevo->numeroPuertas;
		if(nuevo->numeroPuertas <= 0){
			cout << "El vehiculo tiene que tener minimo 1 puerta" << endl;
		}
	}while(nuevo->numeroPuertas <= 0);
	
	cout << "Color -->" << endl;
	cin >> nuevo->color;
	
	cout << "Placa -->" << endl;
	cin >> nuevo->placa;
	cin.ignore();
	
	cout << "Propietario --> " << endl;
	cin.getline(nuevo->propietario,20,'\n');
	
	do {
		//Validar que la tenencia no sea menor a 0
		cout << "Tenencia -->" << endl;
		cin >> nuevo->tenencia;
		if(nuevo->tenencia < 0){
			cout << "La tenencia no puede ser un numero negativo" << endl;
		}
	}while(nuevo->tenencia < 0);
	
	do {
		//Validar que las infracciones no sean menor a 0
		cout << "Infracciones -->" << endl;
		cin >> nuevo->infracciones;
		if(nuevo->infracciones < 0){
			cout << "Las infracciones no pueden ser un numero negativo" << endl;
		}
	}while(nuevo->infracciones < 0);
	
	cout << "Transmision -->" << endl;
	cin >> nuevo->transmision;
	cout << "---------------------------------" << endl;
	
	// 5) Agregarlo aL inicio de la LDEA
	// caso a) Lista Vacia
	if (PRIMERO == NULL || ULTIMO == NULL){
		nuevo->next =NULL;
		nuevo->prev =NULL;
		PRIMERO = nuevo;
		ULTIMO = nuevo;
		cout << "Agregado con exito!" << endl;
		return;
	}// if
	
	//caso b) Lista NO vacia
	nuevo->prev =NULL;
	nuevo->next =PRIMERO;
	PRIMERO->prev = nuevo;
	PRIMERO = nuevo;
	cout << "Agregado con exito!" << endl;
	return;
}//insertarInicio

//#2 Funcion para agregar un vehiculo al final de la lista
void insertarFinal(void){
	// 1)Declarar la variable apuntador
	vehiculo *nuevo;
	
	// 2) Solicitar memoria
	nuevo = (vehiculo *) malloc(sizeof(vehiculo));
	
	// 3) Validar el apuntador
	if (nuevo == NULL){
		cout << "No hay memoria suficiente" << endl;
		return;
	}//if
	
	// 4)Guardar informacion
	cout << "Ingresa los datos del vehiculo" << endl;
	cout << "--------------------------------" << endl;
	cin.ignore();
	
	cout << "Modelo -->" << endl;
	cin.getline(nuevo->modelo,20,'\n');
	
	cout << "Marca -->" << endl;
	cin.getline(nuevo->marca,20,'\n');
	
	do {
		//Validar que sea una fecha correcta
		cout << "Año del vehiculo (entre 1950 y 2022)-->" << endl;
		cin >> nuevo->year;
		if(nuevo->year < 1950 || nuevo->year > 2022){
			cout << "Año invalido" << endl;
			cin.ignore();
		}//if
	}while(nuevo->year < 1950 || nuevo->year > 2022);
	
	do {
		//Validar que sea un numero de pasajeros sea mayor a 0
		cout << "Numero de pasajeros -->" << endl;
		cin >> nuevo->numeroPasajeros;
		if(nuevo->numeroPasajeros <= 0){
			cout << "El vehiculo tiene que tener minimo 1 pasajero" << endl;
		}
	}while(nuevo->numeroPasajeros <= 0);
	
	do {
		//Validar que sea un numero de puertas sea mayor a 0
		cout << "Numero de puertas -->" << endl;
		cin >> nuevo->numeroPuertas;
		if(nuevo->numeroPuertas <= 0){
			cout << "El vehiculo tiene que tener minimo 1 puerta" << endl;
		}
	}while(nuevo->numeroPuertas <= 0);
	
	cout << "Color -->" << endl;
	cin >> nuevo->color;
	
	cout << "Placa -->" << endl;
	cin >> nuevo->placa;
	cin.ignore();
	
	cout << "Propietario --> " << endl;
	cin.getline(nuevo->propietario,20,'\n');
	
	do {
		//Validar que la tenencia no sea menor a 0
		cout << "Tenencia -->" << endl;
		cin >> nuevo->tenencia;
		if(nuevo->tenencia < 0){
			cout << "La tenencia no puede ser un numero negativo" << endl;
		}
	}while(nuevo->tenencia < 0);
	
	do {
		//Validar que las infracciones no sean menor a 0
		cout << "Infracciones -->" << endl;
		cin >> nuevo->infracciones;
		if(nuevo->infracciones < 0){
			cout << "Las infracciones no pueden ser un numero negativo" << endl;
		}
	}while(nuevo->infracciones < 0);
	
	cout << "Transmision -->" << endl;
	cin >> nuevo->transmision;
	cout << "---------------------------------" << endl;
	
	// 5) Agregarlo al final de la LDEA
	//caso a) Lista vacia
	if (PRIMERO == NULL || ULTIMO == NULL){
		nuevo->next =NULL;
		nuevo->prev =NULL;
		PRIMERO = nuevo;
		ULTIMO = nuevo;
		cout << "Agregado con exito!" << endl;
		return;
	}// if
	
	//caso b) LDEA NO vacia
	nuevo->next = NULL;
	nuevo->prev = ULTIMO;
	ULTIMO->next = nuevo;
	ULTIMO = nuevo;
}//insertarFinal

//#3 Funcion para eliminar el primer vehiculo en la lista
void eliminarInicio(void){
	//Declaracion de variables
	vehiculo *borrar=PRIMERO;
	
	//caso a) Lista vacia
	if (PRIMERO == NULL){
		cout << "Nada que borrar aqui" << endl;
		return;
	}//if
	
	cout << "Datos del vehiculo a eliminar" 	<< endl;
	cout << "_____________________________" 	<< endl;
	cout << "Modelo: "				 			<< borrar->modelo << endl;
	cout << "Marca: "			 				<< borrar->marca << endl;
	cout << "Año: "				 				<< borrar->year << endl;
	cout << "Numero de pasajeros: " 			<< borrar->numeroPasajeros << endl;
	cout << "Numero de puertas: "			    << borrar->numeroPuertas << endl;
	cout << "Color: "			 				<< borrar->color << endl;
	cout << "Placa: " 							<< borrar->placa << endl;
	cout << "Propietario: "			 			<< borrar->propietario << endl;
	cout << "Tenencia: " 						<< borrar->tenencia << endl;
	cout << "Infracciones: " 			 		<< borrar->infracciones << endl;
	cout << "Transmision: " 					<< borrar->transmision << endl;
	cout << "_______________________________"  << endl;
	
	//caso b) Lista con 1 nodo
	if (PRIMERO == ULTIMO){
		free(borrar);
		cout << "Registro eliminado correctamente";
		PRIMERO=ULTIMO=NULL;
		return;
	}//if
	
	//caso c) Lista 2 o mas nodos
	PRIMERO = PRIMERO->next;
	PRIMERO->prev = NULL;
	free(borrar);
	cout << "Registro eliminado correctamente";
	return;
}//eliminarInicio

//#4 Funcion para eliminar el ultimo vehiculo en la lista
void eliminarFinal(void){
	//Declaracion de variables
	vehiculo *borrar=PRIMERO;
	
	//caso a) Lista vacia
	if (PRIMERO == NULL){
		cout << "Nada que borrar aqui" << endl;
		return;
	}//if
	
	cout << "Datos del vehiculo a eliminar" 	<< endl;
	cout << "_____________________________" 	<< endl;
	cout << "Modelo: "				 			<< borrar->modelo << endl;
	cout << "Marca: "			 				<< borrar->marca << endl;
	cout << "Año: "				 				<< borrar->year << endl;
	cout << "Numero de pasajeros: " 			<< borrar->numeroPasajeros << endl;
	cout << "Numero de puertas: "			    << borrar->numeroPuertas << endl;
	cout << "Color: "			 				<< borrar->color << endl;
	cout << "Placa: " 							<< borrar->placa << endl;
	cout << "Propietario: "			 			<< borrar->propietario << endl;
	cout << "Tenencia: " 						<< borrar->tenencia << endl;
	cout << "Infracciones: " 			 		<< borrar->infracciones << endl;
	cout << "Transmision: " 					<< borrar->transmision << endl;
	cout << "_______________________________"  << endl;
	
	//caso b) Lista con 1 nodo
	if (PRIMERO == ULTIMO){
		free(borrar);
		cout << "Registro eliminado correctamente";
		PRIMERO=ULTIMO=NULL;
		return;
	}//if
	
	//caso c) Lista 2 o mas nodos
	ULTIMO = ULTIMO->prev;
	ULTIMO->next = NULL;
	free(borrar);
	cout << "Registro eliminado correctamente";
	return;
}//eliminarFinal

//#5 Funcion para mostrar todos los vehiculos en la lista
void mostrarVehiculos(void){
	//Declarar apuntador
	vehiculo *copia=PRIMERO;
	
	//a) Lista vacia
	if(PRIMERO == NULL){
		cout << "Nada que observar" << endl;
		return;
	}//if
	
	//b)Lista NO vacia
	system("cls");
	cout << "Vehiculo registrado en la lista" << endl;
	while (copia != NULL){
		cout << "______________________________________" 						<< endl;
		cout << "Modelo: "				 			<< copia->modelo 			<< endl;
		cout << "Marca: "			 				<< copia->marca				<< endl;
		cout << "Año: "				 				<< copia->year				<< endl;
		cout << "Numero de pasajeros: " 			<< copia->numeroPasajeros	<< endl;
		cout << "Numero de puertas: "			    << copia->numeroPuertas		<< endl;
		cout << "Color: "			 				<< copia->color				<< endl;
		cout << "Placa: " 							<< copia->placa				<< endl;
		cout << "Propietario: "			 			<< copia->propietario		<< endl;
		cout << "Tenencia: " 						<< copia->tenencia			<< endl;
		cout << "Infracciones: " 			 		<< copia->infracciones		<< endl;
		cout << "Transmision: " 					<< copia->transmision		<< endl;
		cout << "______________________________________"  						<< endl;
		copia = copia->next;
	}//while
	cout << "__________________________________________" << endl;
	
	return;
}//mostrarVehiculos

//#6 Funcion para mostrar todos los vehiculos que tienen la misma fecha en la lista
void buscarFecha(void){
	//Declaracion de variables
	int targetYear;
	vehiculo *copia=PRIMERO;
	
	//Lista vacia, no hay alumnos
	if(PRIMERO == NULL){
		cout << "No se tienen vehiculos en la lista" << endl;
		return;
	}//if
	
	//Solicitar nombre del vehiculo
	cout << "Ingresa el año del vehiculo a buscar--> ";
	cin >> targetYear;	
	cin.ignore();
	
	while(copia!=NULL){
		if (targetYear == copia->year){
			cout << "Datos del vehiculo encontrado" 	<< endl;
			cout << "_____________________________" 	<< endl;
			cout << "Modelo: "				 			<< copia->modelo << endl;
			cout << "Marca: "			 				<< copia->marca << endl;
			cout << "Año: "				 				<< copia->year << endl;
			cout << "Numero de pasajeros: " 			<< copia->numeroPasajeros << endl;
			cout << "Numero de puertas: "			    << copia->numeroPuertas << endl;
			cout << "Color: "			 				<< copia->color << endl;
			cout << "Placa: " 							<< copia->placa << endl;
			cout << "Propietario: "			 			<< copia->propietario << endl;
			cout << "Tenencia: " 						<< copia->tenencia << endl;
			cout << "Infracciones: " 			 		<< copia->infracciones << endl;
			cout << "Transmision: " 					<< copia->transmision << endl;
			cout << "_______________________________"	<< endl;
	    } //if	
		if(copia->next == NULL){
				return;
			}    
		copia = copia->next;
	}//while
	
	cout << "El año " << targetYear << " no esta registrado en la lista" << endl;
	return;
}//buscar

//#7 Funcion para buscar al propietario de un vehiculo
void buscarPropietario(void){
	//Declaracion de variables
	char targetPropietario[20];
	vehiculo *copia=PRIMERO;
	
	//Lista vacia, no hay vehiculos
	if(PRIMERO == NULL){
		cout << "No hay vehiculos en la lista" << endl;
		return;
	}//if
	
	//Solicitar dueño del vehiculo
	cout << "Ingresa el nombre del propietario a buscar --> ";
	cin >> targetPropietario;

	cin.ignore();	
	while(copia!=NULL){
		if (strcmp(targetPropietario,copia->propietario) == 0){
			cout << "Datos del vehiculo encontrado" 	<< endl;
			cout << "_____________________________" 	<< endl;
			cout << "Modelo: "				 			<< copia->modelo << endl;
			cout << "Marca: "			 				<< copia->marca << endl;
			cout << "Año: "				 				<< copia->year << endl;
			cout << "Numero de pasajeros: " 			<< copia->numeroPasajeros << endl;
			cout << "Numero de puertas: "			    << copia->numeroPuertas << endl;
			cout << "Color: "			 				<< copia->color << endl;
			cout << "Placa: " 							<< copia->placa << endl;
			cout << "Propietario: "			 			<< copia->propietario << endl;
			cout << "Tenencia: " 						<< copia->tenencia << endl;
			cout << "Infracciones: " 			 		<< copia->infracciones << endl;
			cout << "Transmision: " 					<< copia->transmision << endl;
			cout << "_______________________________"  << endl;
			return;
	    } //if
		copia = copia->next;
	}//while

	cout << "El propietario " << targetPropietario << " no esta registrado en la lista" << endl;
	return;	
}//buscarPropietario

//#8 Funcion para ordenar los vehiculos por su año en orden creciente
void ordenarPorYear(void){
	//Declarar apuntador
	vehiculo *copia=PRIMERO, *copia2=NULL;
	int aux;
	
	//a) Lista vacia
	if(PRIMERO == NULL){
		cout << "No hay vehiculos registrados" << endl;
		return;
	}//if
	
	//b)Lista con 1 nodo
	if(copia->next == NULL && copia->prev == NULL){
		cout << "	Datos del vehiculo" 	<< endl;
		cout << "_____________________________" 	<< endl;
		cout << "Modelo: "				 			<< copia->modelo << endl;
		cout << "Marca: "			 				<< copia->marca << endl;
		cout << "Año: "				 				<< copia->year << endl;
		cout << "Numero de pasajeros: " 			<< copia->numeroPasajeros << endl;
		cout << "Numero de puertas: "			    << copia->numeroPuertas << endl;
		cout << "Color: "			 				<< copia->color << endl;
		cout << "Placa: " 							<< copia->placa << endl;
		cout << "Propietario: "			 			<< copia->propietario << endl;
		cout << "Tenencia: " 						<< copia->tenencia << endl;
		cout << "Infracciones: " 			 		<< copia->infracciones << endl;
		cout << "Transmision: " 					<< copia->transmision << endl;
		cout << "_______________________________"	<< endl;		
		return;
	}//if
	
	//c) Lista con 2 o mas nodos
	while(copia!=NULL){
		copia2=copia->next;
		while(copia2!=NULL){
			if(copia->year > copia2->year){
				aux = copia->year;
				copia->year = copia2->year;
				copia2->year = aux;
			}//if
			copia2 = copia2->next;
		}//while
		cout << "	Datos del vehiculo" 	<< endl;
		cout << "_____________________________" 	<< endl;
		cout << "Modelo: "				 			<< copia->modelo << endl;
		cout << "Marca: "			 				<< copia->marca << endl;
		cout << "Año: "				 				<< copia->year << endl;
		cout << "Numero de pasajeros: " 			<< copia->numeroPasajeros << endl;
		cout << "Numero de puertas: "			    << copia->numeroPuertas << endl;
		cout << "Color: "			 				<< copia->color << endl;
		cout << "Placa: " 							<< copia->placa << endl;
		cout << "Propietario: "			 			<< copia->propietario << endl;
		cout << "Tenencia: " 						<< copia->tenencia << endl;
		cout << "Infracciones: " 			 		<< copia->infracciones << endl;
		cout << "Transmision: " 					<< copia->transmision << endl;
		cout << "_______________________________"	<< endl;	
		if(copia->next == NULL){
			return;
		}//if
		copia = copia->next;
	}//while principal
	
	
}//ordenarPorYear

//#9 Respaldar los datos guardados en la lista en un arhcivo

void respaldar(void){
	ofstream archivoGuardar;//("prueba.txt");
	vehiculo *copia=PRIMERO;
	
	archivoGuardar.open("prueba.txt",ios::app);
	
	archivoGuardar <<  "Vehiculo registrado en la lista" << endl;
	while (copia != NULL){
		archivoGuardar <<  "______________________________________" 						<< endl;
		archivoGuardar <<  "Modelo: "				 			<< copia->modelo 			<< endl;
		archivoGuardar <<  "Marca: "			 				<< copia->marca				<< endl;
		archivoGuardar <<  "Año: "				 				<< copia->year				<< endl;
		archivoGuardar <<  "Numero de pasajeros: " 			<< copia->numeroPasajeros	<< endl;
		archivoGuardar <<  "Numero de puertas: "			    << copia->numeroPuertas		<< endl;
		archivoGuardar <<  "Color: "			 				<< copia->color				<< endl;
		archivoGuardar <<  "Placa: " 							<< copia->placa				<< endl;
		archivoGuardar <<  "Propietario: "			 			<< copia->propietario		<< endl;
		archivoGuardar <<  "Tenencia: " 						<< copia->tenencia			<< endl;
		archivoGuardar <<  "Infracciones: " 			 		<< copia->infracciones		<< endl;
		archivoGuardar <<  "Transmision: " 					<< copia->transmision		<< endl;
		archivoGuardar <<  "______________________________________"  						<< endl;
		copia = copia->next;
	}//while
	archivoGuardar <<  "__________________________________________" << endl;
	
	cout << "Datos guardados exitosamente!" << endl;
	
	archivoGuardar.close();
}

//10# Funcion para leer los datos guardados en el archivo
void leer(void){
	string linea;
	string texto;
	
	ifstream archivo("prueba.txt");	
	
	while ( getline(archivo,linea)) {
		texto = texto + linea+"\n";
	} // while
	archivo.close();
	cout << texto << endl;
	
	
}
