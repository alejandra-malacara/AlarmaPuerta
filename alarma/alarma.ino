
 
#include <avr/sleep.h> // libreria sleep nos permite que se reduzca el consumo de energia 
                       // en  avr se puede poner en diferentes modos de suspension 
 
//Definimos pines 
#define boton 2 
#define buzzer 8
#define led 13
//variable 
int volumen = 0;  //inicializar varible en cero 

void setup(){
pinMode(boton,OUTPUT);                //se declara pin 2 como salida 
pinMode(buzzer,OUTPUT);               //se declara pin 8 como salida 
pinMode(led, OUTPUT);                 // se declara pin 13 como salid 
set_sleep_mode(SLEEP_MODE_PWR_DOWN);  //el mayor ahorro de energia, aqui se establece el modo de energia 
attachInterrupt(digitalPinToInterrupt(boton),inter,RISING); // interrupccion en el boton 
}                                     //llave final de metodo setup


void loop() {
  if(volumen==0){              // si la variable volumen esta en 0, el modo sleep se activa 
      digitalWrite(led, LOW);// led se apaga 
      sleep_enable();        // modo de suspension 
      sleep_mode();          // Esta macro establece automáticamente el bit de habilitación de suspensión
                             //se pone en suspensión 
   }//fin de if 
    else{                    //caso contrario,  estara en modo disable desabilita la suspension 
      sleep_disable();       // modo inhabilitar, desactiva el modo suspencion 
      alarm();               //llama metodo alarma  
    }                        // fin else 
}


void inter(){               // Metodo para la interrupcion 
 volumen=!volumen;          // si  volumen=true; después de la expresión volumen=!volumen ; entonces a tendrá el valor false 
 }


void alarm(){
 analogWrite(buzzer,128); // analogWrite escribe un valor en un pin analógico
                          // a pin buzzer le damos un ciclo de trabajo de 128
 delay(200);              // espera por 200ms
 digitalWrite(led, HIGH); // se enciende led 
 digitalWrite(buzzer,0);  // el pin va a generar una onda constante del ciclo de trabajo especificado hasta la siguiente llamada
                          // en este caso con digitalWrite 
 delay(100);              // espera por 100ms 
}
