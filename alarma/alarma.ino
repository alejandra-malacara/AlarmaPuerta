//Definimos pines 
#define boton 2 
#define buzzer 8

int volumen = 0; //inicializar varible en cero 

void setup() {
pinMode(boton,OUTPUT); //se declara pin 2 como salida 
pinMode(buzzer,OUTPUT); //se declara pin 8 como salida 
attachInterrupt(digitalPinToInterrupt(boton),inter,RISING); // interrupccion en el boton 


}

void loop() {
  if(volumen==0){ //Mientras volumen este en cero no ocurre nada 

  }else{ // caso contrario 
  analogWrite(buzzer,128); // analogWrite escribe un valor en un pin analógico
                           // a pin buzzer le damos un ciclo de trabajo de 128
    delay(200);
    digitalWrite(buzzer,0); // el pin va a generar una onda constante del ciclo de trabajo especificado hasta la siguiente llamada
                            // en este caso con digitalWrite 
    delay(100);
  }

}

void inter(){ // Metodo para la interrupcion 
volumen=!volumen; // si  volumen=true; después de la expresión volumen=!volumen ; entonces a tendrá el valor false o viceversa 
  
}
