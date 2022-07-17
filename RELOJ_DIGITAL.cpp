#include<iostream>
#include<dos.h>
#include<conio.h>
#include<windows.h>
#include<time.h>

using namespace std;
const char *nombre_archivo = "archivo.txt";
const char *nombre_archivo_temp = "archivo_aux.txt";

struct Reloj{
	int n;
	char indentificador[100];
	char hora[20];
	char minutos[20];
	char segundos[20];
};

void menu();
void crear();
void leer();
void eliminar();
int opc = 0;

int main(){
menu();
}

const char *d0[7][4] ={  "**","**","**","*",
                         "* ","  ","  ","*",
                         "* ","  ","  ","*",
                         "* ","  ","  ","*",
                         "* ","  ","  ","*",
                         "* ","  ","  ","*",
                         "**","**","**","*"};

const char *d1[7][4] ={  "  ","  ","  ","*",
                         "  ","  ","  ","*",
                         "  ","  ","  ","*",
                         "  ","  ","  ","*",
                         "  ","  ","  ","*",
                         "  ","  ","  ","*",
                         "  ","  ","  ","*"};

const char *d2[7][4] ={  "**","**","**","*",
                         "  ","  ","  ","*",
                         "  ","  ","  ","*",
                         "**","**","**","*",
                         "* ","  ","  "," ",
                         "* ","  ","  "," ",
                         "**","**","**","*"};

const char *d3[7][4] ={  "**","**","**","*",
                         "  ","  ","  ","*",
                         "  ","  ","  ","*",
                         "**","**","**","*",
                         "  ","  ","  ","*",
                         "  ","  ","  ","*",
                         "**","**","**","*"};

const char *d4[7][4] ={  "* ","  ","  ","*",
                         "* ","  ","  ","*",
                         "* ","  ","  ","*",
                         "**","**","**","*",
                         "  ","  ","  ","*",
                         "  ","  ","  ","*",
                         "  ","  ","  ","*"};

const char *d5[7][4] ={  "**","**","**","*",
                         "* ","  ","  "," ",
                         "* ","  ","  "," ",
                         "**","**","**","*",
                         "  ","  ","  ","*",
                         "  ","  ","  ","*",
                         "**","**","**","*"};

const char *d6[7][4] ={  "**","**","**","*",
                         "* ","  ","  "," ",
                         "* ","  ","  "," ",
                         "**","**","**","*",
                         "* ","  ","  ","*",
                         "* ","  ","  ","*",
                         "**","**","**","*"};

const char *d7[7][4] ={  "**","**","**","*",
                         "  ","  ","  ","*",
                         "  ","  ","  ","*",
                         "  ","  ","  ","*",
                         "  ","  ","  ","*",
                         "  ","  ","  ","*",
                         "  ","  ","  ","*"};

const char *d8[7][4] ={  "**","**","**","*",
                         "* ","  ","  ","*",
                         "* ","  ","  ","*",
                         "**","**","**","*",
                         "* ","  ","  ","*",
                         "* ","  ","  ","*",
                         "**","**","**","*"};

const char *d9[7][4] ={  "**","**","**","*",
                         "* ","  ","  ","*",
                         "* ","  ","  ","*",
                         "**","**","**","*",
                         "  ","  ","  ","*",
                         "  ","  ","  ","*",
                         "**","**","**","*"};

const char *sep[7][4] ={ "  ","  ","  "," ",
                         "  ","  ","  "," ",
                         "  ","* ","* "," ",
                         "  ","  ","  "," ",
                         "  ","* ","* "," ",
                         "  ","  ","  "," ",
                         "  ","  ","  "," "};
                         

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); //Recupera un identificador para el dispositivo estándar especificado (salida estándar)
COORD CursorPosition;

void gotoxy(int x, int y)                               //Configuración de la posición del cursor
{
     CursorPosition.X =x;                               //coordenada de fila para celda de carácter
     CursorPosition.Y =y;                               //coordenada de columna para celda de carácter
     SetConsoleCursorPosition(console, CursorPosition); //función incorporada utilizada para configurar el cursor en cualquier lugar que quisiéramos en la consola

}

void setcursor (bool visible, DWORD size){           // establecer bool visible = 0 - invisible, bool visible = 1 - visible
    if(size == 0)
      size =20;                                      // tamaño predeterminado del cursor Cambiando a números del 1 al 20, disminuye el ancho del cursor

    CONSOLE_CURSOR_INFO lpCursor;                    //Un puntero a una estructura CONSOLE_CURSOR_INFO que proporciona las nuevas especificaciones para el cursor del búfer de pantalla de la consola.
    lpCursor.bVisible = false;                       //La visibilidad del cursor. Si el cursor es invisible, este miembro es falso
    lpCursor.dwSize = size;                          //El porcentaje de la celda de carácter que llena el cursor. Este valor está entre 1 y 100.
    SetConsoleCursorInfo(console, &lpCursor);

}

void printDigit(int no, int x, int y)                 //dígito de impresión según el tiempo
{
  for(int i=0;i<7;i++){
    for(int j=0; j<4;j++){
        switch(no){
          case 0: gotoxy(x+j, y+i); cout<< d0[i][j]; break;
          case 1: gotoxy(x+j, y+i); cout<< d1[i][j]; break;
          case 2: gotoxy(x+j, y+i); cout<< d2[i][j]; break;
          case 3: gotoxy(x+j, y+i); cout<< d3[i][j]; break;
          case 4: gotoxy(x+j, y+i); cout<< d4[i][j]; break;
          case 5: gotoxy(x+j, y+i); cout<< d5[i][j]; break;
          case 6: gotoxy(x+j, y+i); cout<< d6[i][j]; break;
          case 7: gotoxy(x+j, y+i); cout<< d7[i][j]; break;
          case 8: gotoxy(x+j, y+i); cout<< d8[i][j]; break;
          case 9: gotoxy(x+j, y+i); cout<< d9[i][j]; break;
          case 10: gotoxy(x+j, y+i); cout<<sep[i][j]; break;
        }
    }
  }
}


void menu(){
	system("cls");
	
		FILE* archivo = fopen(nombre_archivo,"rb");	
		if (!archivo){
			archivo = fopen(nombre_archivo,"w+b");
			}
			
    setcursor(0,0);                      //configuración del cursor invisible

    srand((unsigned) time (NULL));       //hace uso del reloj interno de la computadora para controlar la elección de la semilla.
                                         //Dado que el tiempo está cambiando continuamente, la semilla está cambiando para siempre.

    time_t now = time(0);                //fecha/hora actual según el sistema actual

    char *dt= ctime(&now);               //convertir ahora a forma de cadena

    tm *lotm = localtime(&now);          //Convierta ahora a tm struct para la zona horaria local
    dt = asctime(lotm);

    int hour = lotm->tm_hour;            //imprimir varios componentes de la estructura tm.
    int min = lotm->tm_min;
    int sec = lotm->tm_sec;
    int go = 0;
    int valor = 0;
    int n;
    char identificador;
    char hora;
	char minutos;
	char segundos;

    int gap=8;                           //espacio entre dígitos

    int posX;                            //cursor position
    int posY= 8;
    
    
	system("cls");
	
	while(1){
        system("cls");

        posX= 15;

        if(kbhit()){                     //La función kbhit se usa para determinar si una tecla ha sido presionada o no.
            char ch = getch();           //Almacena la tecla presionada en ch
        
        system("cls");
    	go=1;
		if(go==1){
				printf(" Cargando");
				Sleep(400);
				system("cls");
				printf(" Cargando.");
				Sleep(400);
				system("cls");
				printf(" Cargando..");
				Sleep(400);
				system("cls");
				printf(" Cargando...");
				Sleep(400);
				system("cls");
				printf(" Cargando");
				Sleep(400);
				system("cls");
				printf(" Cargando.");
				Sleep(400);
				system("cls");
				printf(" Cargando..");
				Sleep(400);
				system("cls");
				printf(" Cargando...");
				Sleep(400);
				system("cls");
				go=2;
				}
    
        
        cout<<"======================================="<<endl;
		cout<<"      C R E A  T U  A L A R M A       "<<endl;
		cout<<"======================================="<<endl<<endl;
		
		cout<<"1. Programar Alarma"<<endl;
		cout<<"2. Ver mis Alarmas"<<endl;
		cout<<"3. Eliminar Alarma"<<endl;
		cout<<"4. Salir"<<endl;
		cout<<"5. Regresar al reloj"<<endl;
		cout<<endl;
		cout<<"Digite su opcion: ";
		cin>>opc; 
		
		if(ch==27){                  //Termina el ciclo cuando se presiona escape (tecla) y finaliza el programa
                break;
            }
        }    
    
        switch(opc)
	{
		case 1: crear();		;break;
		case 2: leer();			;break;
 		case 3: eliminar();		;break;
 		case 4: exit(-1);		;break; 
		default:cout<<"Opcion no valida";  
	}
		
		system("cls");
		
		
        if(hour< 10){                      //hora de impresión
            printDigit(0,posX,posY);
            printDigit(hour,posX+=gap, posY);
        }
        else{
            printDigit(hour/10,posX,posY);
            printDigit(hour%10,posX+=gap, posY);
        }

		
        printDigit(10,posX+=gap,posY);     //imprimiendo el símbolo de dos puntos entre horas y minutos
        
		
        if(min< 10){                       //imprimiendo minutos
            printDigit(0,posX+=gap,posY);
            printDigit(min,posX+=gap, posY);
        }
        else{
            printDigit(min/10,posX+=gap,posY);
            printDigit(min%10,posX+=gap, posY);
        }

		
        printDigit(10,posX+=gap,posY);      //imprimiendo el símbolo de dos puntos entre minutos y segundos{ 

		
        if(sec< 10){                        //imprimiendo segundos
            printDigit(0,posX+=gap,posY);
            printDigit(sec,posX+=gap, posY);
        }
        else{
            printDigit(sec/10,posX+=gap,posY);
            printDigit(sec%10,posX+=gap, posY);
        }
        
        gotoxy(39,20); cout<<" A L A R M A S "<<endl;
        
        gotoxy(24,22); cout<<"Presiona la barra de espacio para ir al menu"<<endl<<endl;
		
		/*Reloj reloj;
		int id=0;
		fread(&reloj,sizeof(Reloj),1,archivo);
		cout<<"\t\t Alertas Pendientes";
		cout<<endl;
		cout<<"\t\t\t Hora "<<reloj.hora<<" : "<<reloj.minutos<<" - "<<reloj.indentificador<<endl;
		fread(&reloj,sizeof(Reloj),1,archivo);*/
	
		/*Reloj reloj;
		int id=0;	
		fread(&reloj,sizeof(Reloj),1,archivo);
		cout<<"\t\t\t\t\t Alertas Pendientes  "<<endl;
		do{
		cout<<"\t\t\t No. "<<reloj.n<<" Hora "<<reloj.hora<<" : "<<reloj.minutos<<" - "<<reloj.indentificador<<endl;
		fread(&reloj,sizeof(Reloj),1,archivo);
		id+=1;	
		}while(feof(archivo)==0);
		fclose(archivo);
		cout<<endl;
		system("pause");*/
		
        Sleep(950);                         //Se deducen 50 milisegundos de tiempo de procesamiento
        sec++;
        if(sec>=60){
            sec =0;
            min++;
        }
        if(min>=60){
            min=0;
            hour++;
        }
        if(hour>=24){
            sec=0;   
            min=0;
            hour =0;
        }
    
    }
		
}

void leer(){
		system("cls");
		FILE* archivo = fopen(nombre_archivo,"rb");	
		if (!archivo){
			archivo = fopen(nombre_archivo,"w+b");	
		}
		Reloj reloj;
		int id=0;	
		fread(&reloj,sizeof(Reloj),1,archivo);
		cout<<"______________________________________________________"<<endl;
		cout<<"\t Lista de alarmas creadas"<<endl;
		do{
		cout<<"______________________________________________________"<<endl;
		cout<<"Id: "<<id<<endl;
		cout<<"No. "<<reloj.n<<endl;
		cout<<"Nombre de la Alarma: "<<reloj.indentificador<<endl;
		cout<<"Alarma: "<<reloj.hora<<" : "<<reloj.minutos<<" : "<<reloj.segundos<<endl<<endl;
		
			
		fread(&reloj,sizeof(Reloj),1,archivo);
		id+=1;	
		}while(feof(archivo)==0);
		fclose(archivo);
		cout<<endl;
		
		cout<<"Presiona dos teclas al mismo tiempo para volver al menu:)"<<endl;
		system("pause");
		
		menu();	
}

void crear(){
	system("cls");
	char continuar;
	int go=0;
	FILE* archivo = fopen(nombre_archivo,"ab");
	Reloj reloj;
	string identificador,hora,minutos,segundos;
	do{
		fflush(stdin);
		cout<<"Ingrese el Numero de la Alarma: ";
		cin>>reloj.n;
		cin.ignore();
		cout<<"Ingrese el nombre de su Alarma: ";
		getline(cin,identificador);
		strcpy(reloj.indentificador,identificador.c_str());
		cout<<endl;
		cout<<"Escriba su Alarma en formado de 24h ";
		cout<<endl<<endl;
		cout<<"Ingrese la hora: ";
		cin>>reloj.hora;
		cout<<"Ingrese los minutos: ";
		cin>>reloj.minutos;
		cout<<"Ingrese los segundos: ";
		cin>>reloj.segundos;
		fwrite(&reloj,sizeof(Reloj),1,archivo);
		cout<<endl;
		cout<<"Desea crear otra Alarma (s/n): ";
		cin>>continuar;
		cout<<endl;
		
	} while ( (continuar=='s') || (continuar=='S') );
	fclose(archivo);
	
	cout<<"Presiona dos teclas al mismo tiempo para volver al menu:)"<<endl;
	cout<<endl;
	
	system("pause");
	
	menu();
}

void eliminar(){
 	
 	system("cls");
	FILE *archivo, *archivo_temp; 
	int n; 
	Reloj reloj; 
	
	archivo_temp=fopen(nombre_archivo_temp,"w+b"); 
	archivo=fopen(nombre_archivo,"rb"); 
	                      				                
	cout<<"No. de la alarma a eliminar: "; 
	cin>>n;
	
	                                                                                
		while(fread(&reloj,sizeof(Reloj),1,archivo)){	
			if (reloj.n != n) 
			fwrite(&reloj,sizeof(Reloj),1,archivo_temp); 
			}
	                
		fclose(archivo_temp); 
		fclose(archivo); 
	                
		archivo_temp=fopen(nombre_archivo_temp,"rb"); 
		archivo=fopen(nombre_archivo,"wb"); 
	 
		while(fread(&reloj,sizeof(Reloj),1, archivo_temp)){ 
			fwrite(&reloj,sizeof(Reloj),1, archivo); 
		}
	                
	fclose(archivo_temp); 
	fclose(archivo); 
	
	cout<<"Presiona dos teclas al mismo tiempo para volver al menu:)"<<endl;
	system("pause");
	
	menu(); 

}	
