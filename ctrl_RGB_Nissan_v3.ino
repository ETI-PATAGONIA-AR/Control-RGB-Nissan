/////////////////////////////////////////////////////////////////////////////////////////
// Control de luces RGB version BETA3 - Club Nissan XTERRA/Frontier                    //
//                             -Control de intensidad de color                         //
//                             -Control de seleccion de color (Blanco/Rojo/Azul/Verde) //
// Alejandro Martin Torres - Comodoro Rivadavia prof.martintorres@educ.ar - 2976256173 //
/////////////////////////////////////////////////////////////////////////////////////////

//////////// CONFIGURACION DE HARDWARE ////////////
int Pin_DC = A0;        // defino el pin de lectura del valor de tension del modulo dimmer
int botonSeleccion = 8; // defino el pin para seleccion
int ledRojo = 9;        // defino el pin a utilizar para el color ROJO
int ledVerde = 10;       // defino el pin a utilizar para el color VERDE
int ledAzul = 11;        // defino el pin a utilizar para el color AZUL
/////////////// VARIABLES DE ENTORNO ///////////////
int Dimer;
int mode = 0;        // para que empiece por el color BLANCO por defecto
                     // 0=Blanco, 1= Rojo, 2=Verde, 3=Azul  
////////////////////////////////////////////////////
void setup() 
{
  Serial.begin(9600);
  pinMode(botonSeleccion, INPUT);   // declaro el pin 8, entrada seleccion color
  //pinMode(ledRojo,OUTPUT);          // declaro el pin 9, salida led rojo
  //pinMode(ledVerde,OUTPUT);         // declaro el pin 10, salida led verde
  //pinMode(ledAzul,OUTPUT);          // declaro el pin 11, salida led azul
  mode = 0;
}
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////// CUERPO DEL PROGRAMA ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
void loop() 
{
if (digitalRead(botonSeleccion)== HIGH)
{
  mode=mode+1;
  delay (400);
}

if (mode == 0)   // Color BLANCO
{
  //Potenciometro();
  int lee_dimer = analogRead(Pin_DC);
  Dimer= map(lee_dimer,0,1023,0,240);
  Serial.println("Led BLANCO");
  Serial.println(Dimer);
  analogWrite (ledRojo,Dimer);
  analogWrite (ledVerde,Dimer);
  analogWrite (ledAzul,Dimer);
  //delay (1000);
}

if (mode == 1)   // Color ROJO
{
  //Potenciometro();
  int lee_dimer = analogRead(Pin_DC);
  Dimer= map(lee_dimer,0,1023,0,240);
  Serial.println("Led ROJO");
  Serial.println(Dimer);
  analogWrite (ledRojo,Dimer);
  analogWrite (ledVerde,0);
  analogWrite (ledAzul,0);
  //delay (1000);
  }

if (mode == 2)   // Color VERDE
{
  //Potenciometro();
  int lee_dimer = analogRead(Pin_DC);
  Dimer= map(lee_dimer,0,1023,0,240);
  Serial.println("Led VERDE");
  Serial.println(Dimer);
  analogWrite (ledRojo,0);
  analogWrite (ledVerde,Dimer);
  analogWrite (ledAzul,0);
  //delay (1000);
}

if (mode == 3)   // Color AZUL
{
  //Potenciometro();
  int lee_dimer = analogRead(Pin_DC);
  Dimer= map(lee_dimer,0,1023,0,240);
  Serial.println("Led AZUL");
  Serial.println(Dimer);
  analogWrite (ledRojo,0);
  analogWrite (ledVerde,0);
  analogWrite (ledAzul,Dimer);
  //delay (1000);
}
if (mode == 4)   
{
  mode=0;
}
}
////////////////////////////// FUNCION LECTURA DIMER //////////////////////////////////
void Potenciometro()
 { 
int lee_dimer = analogRead(Pin_DC);
Dimer= map(lee_dimer,0,1023,0,240);
 }
///////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////// FIN DEL PROGRAMA /////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////



 
