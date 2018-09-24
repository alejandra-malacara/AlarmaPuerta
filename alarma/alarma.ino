// libreria sleep nos permite que se reduzca el consumo de energia 
// donde avr se puede poner en diferentes modos de suspension 
 #include <avr/sleep.h>
 
//Definimos pines 
#define boton 2 
#define buzzer 8

int volumen = 0; //inicializar varible en cero 

void setup() {
pinMode(boton,OUTPUT); //se declara pin 2 como salida 
pinMode(buzzer,OUTPUT); //se declara pin 8 como salida 
set_sleep_mode(SLEEP_MODE_PWR_DOWN);
attachInterrupt(digitalPinToInterrupt(boton),inter,RISING); // interrupccion en el boton 
}


void loop() {
     if(volumen==0){ // si la variable volumen esta en 0, el modo sleep se activa 
   sleep_enable();// modo de suspension 
    sleep_mode(); // Esta macro establece automáticamente el bit de habilitación de suspensión
                   //se pone en suspensión y borra el bit de habilitación de suspensión.
  }else{ //caso contrario,  estara en modo disable desabilita la suspension 
  sleep_disable();// modo inhabilitar 
  alarm(); //llama metodo alarma  
  }
}

void inter(){ // Metodo para la interrupcion 
volumen=!volumen; // si  volumen=true; después de la expresión volumen=!volumen ; entonces a tendrá el valor false o viceversa 
  
}

void alarm(){

   analogWrite(buzzer,128);// analogWrite escribe un valor en un pin analógico
                          // a pin buzzer le damos un ciclo de trabajo de 128
   delay(200);
   digitalWrite(buzzer,0);// el pin va a generar una onda constante del ciclo de trabajo especificado hasta la siguiente llamada
//                            // en este caso con digitalWrite 
   delay(100);
}
