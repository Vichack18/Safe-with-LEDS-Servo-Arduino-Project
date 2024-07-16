#include <Keypad.h>
#include <Servo.h>

const byte FILAS=4; // PQ vamos a usar 4 filas del pad //
const byte COLUMNAS=3; // " " columnas //
char keys[FILAS][COLUMNAS]{
  {'1','2','3'}, 
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
}; // QUE ES LO QUE el arduino tiene que leer cada vez q apretemos botones, esta expresado de manera
// textual //

// En donde estan conectadas las filas y columnas //
byte pinesFilas[FILAS]={8,7,6,5};
byte pinesColumnas[COLUMNAS]={4,3,2};

Keypad teclado=Keypad(makeKeymap(keys), pinesFilas, pinesColumnas, FILAS, COLUMNAS); 
// Funcion de la libreria //
char TECLA; // Almacenara la tecla que presionemos del pad
int ledr=10,leda=11,ledv=12,ledb=13;

// variables de estado Ej: si el led esta apagado y apretamos el numero 1 se va a prender //
int estador=0;
int estadoa=0,estadov=0,estadob=0;

Servo servo; // creamos objeto //

void setup() {
  // put your setup code here, to run once:
 Serial.begin (9600);
 pinMode (ledr, OUTPUT);
 pinMode (leda, OUTPUT);
 pinMode (ledv, OUTPUT);
 pinMode (ledb, OUTPUT);
 servo.attach(9);
 servo.write(0); // para que se ponga a 0 grados cuando se inicie el arduino

}

void loop() {
  // put your main code here, to run repeatedly:
  TECLA=teclado.getKey(); // tecla = a lo que lea de mi teclado // A lo que presione se guarda en TECLA
  if (TECLA){
    Serial.println(TECLA); // Imprimir que teclas estamos apretando
  }

  if (TECLA=='1'){  // Si se presiona 1, si esta en 0 se prende y cambia estado a 1, y sino, si esta en 1 se apaga y cambia estado a 0 //
    if (estador==0){
      digitalWrite(ledr,HIGH);
      estador=1;
    }
    else{
      digitalWrite(ledr,LOW);
      estador=0;
    }
  }

  if (TECLA=='2'){  // Si se presiona 1, si esta en 0 se prende y cambia estado a 1, y sino, si esta en 1 se apaga y cambia estado a 0 //
    if (estadoa==0){
      digitalWrite(leda,HIGH);
      estadoa=1;
    }
    else{
      digitalWrite(leda,LOW);
      estadoa=0;
    }
  }

  if (TECLA=='3'){  // Si se presiona 1, si esta en 0 se prende y cambia estado a 1, y sino, si esta en 1 se apaga y cambia estado a 0 //
    if (estadov==0){
      digitalWrite(ledv,HIGH);
      estadov=1;
    }
    else{
      digitalWrite(ledv,LOW);
      estadov=0;
    }
  }

  if (TECLA=='4'){  // Si se presiona 1, si esta en 0 se prende y cambia estado a 1, y sino, si esta en 1 se apaga y cambia estado a 0 //
    if (estadob==0){
      digitalWrite(ledb,HIGH);
      estadob=1;
    }
    else{
      digitalWrite(ledb,LOW);
      estadob=0;
    }
  }

  if (TECLA=='5'){
    servo.write(180);
  }
  if (TECLA=='6'){
    servo.write(90);
  }
  if (TECLA=='7'){
    servo.write(0);
  }

}