# AlarmaPuerta
Instituto tecnológico de león 

Sistemas programables 

Practica 2 

Simulación de alarma de una puerta con Arduino 

Alumna: Malacara Avila Alejandra.

Grupo: 7:00 am – 8:40 am martes-jueves 


Introducción

Desarrolle una alarma con arduino para el acceso a una puerta. Cuando la puerta se abra, la alarma debería sonar.
Requisito indispensable: 
Reducir el consumo de energía al mínimo. Mientras la alarma no esté sonando el arduino deberá consumir la mínima cantidad de energía. Cuando la puerta se cierre esta deberá de dejar de sonar y regresar al estado de bajo consumo energético.

Material

1.	Arduino
2.	Cable USB 
3.	Protoboard 
4.	Buzzer
5.	Led
6.	Resistencias(220 ohms, 10k)
7.	Botón pulsador 
8.	Reed switch 
9.	Cables 

Buzzer: es un transductor electroacústico que produce un sonido o zumbido continuo o intermitente de un mismo tono (generalmente agudo). Sirve como mecanismo de señalización o aviso y se utiliza en múltiples sistemas, como en automóviles o en electrodomésticos, incluidos los despertadores.
Inicialmente este dispositivo estaba basado en un sistema electromecánico que era similar a una campana eléctrica pero sin el badajo metálico, el cual imitaba el sonido de una campana.
Su construcción consta de dos elementos, un electroimán o disco piezoeléctrico y una lámina metálica de acero. El zumbador puede ser conectado a circuitos integrados especiales para así lograr distintos tonos.
Cuando se acciona, la corriente pasa por la bobina del electroimán y produce un campo magnético variable que hace vibrar la lámina de acero sobre la armadura, o bien, la corriente pasa por el disco piezoeléctrico haciéndolo entrar en resonancia eléctrica y produciendo ultrasonidos que son amplificados por la lámina de acero.

Reed switch: es un interruptor eléctrico activado por un campo magnético.
El interruptor de lengüeta consiste en un par de contactos ferrosos encerrados al vacío dentro un tubo de vidrio. Cada contacto está sellado en los extremos opuestos del tubo de vidrio. El tubo de vidrio puede tener unos 10 mm de largo por 3 mm de diámetro.
Al acercarse a un campo magnético, los contactos se unen cerrando un circuito eléctrico. La rigidez de los contactos hará que se separen al desaparecer el campo magnético. Para asegurar la durabilidad, la punta de los contactos tiene un baño de un metal precioso.
El campo magnético puede estar generado por un imán permanente o por una bobina.

Desarrollo 

Para esta práctica, primero se realizó en la protoboard  poner el buzzer, donde una patita la conecte a GND en la placa arduino y la patita positiva la conecte al pin 8, también agregue un reed switch para usar un imán y el buzzer comenzara a sonar, pero lo sustituí por un botón ya que el reed switch  se rompió, así que con el botón lo coloque como pull up.

Ya por ultimo agregue un led que prendera  al sonar el buzzer y este mismo se tiene que apagar cuando el buzzer deje de sonar, y conecte la protoboard al voltaje (5v) y al GND.

En el código, igual  definí  el buzzer al pin 8, el led al pin 13 y el botón al pin 2, en el void setup declare las variables y su  modo de trabajo de los pins, los cuales fueron de salida para el buzzer, el led y el botón.  Utilice una variable de tipo int, la cual se llama volumen para hacer una condición.  

Cree un método llamado alarm donde utilizo en analogWrite para el buzzer y declarar su carga de trabajo, y el digitalWrite  el cual el  pin va a generar una onda constante del ciclo de trabajo especificado hasta la siguiente llamada, en este método es donde se generara el sonido del buzzer.

En el método loop se hace la condición donde volumen = 0  entonces la alarma no está sonando, si no se cumple se manda llamar el método alarm y se generara el sonido.

También se utilizó  de una interrupción y se creó el método inter donde si  volumen=true; después de la expresión volumen=!volumen ; entonces a tendrá el valor false, para esto, en setup() se declaró attachInterrupt(digitalPinToInterrupt(boton),inter,RISING), la cual es una  interrupción y se le agrego al botón 

Y el requerimiento principal de la practica fue el ahorro de energía el cual se logra con set_sleep_mode(SLEEP_MODE_PWR_DOWN) que nos da el mayor ahorro de energía, para poder usarlo se necesita de una librería #include <avr/sleep.h> donde avr son los distintos modos de suspensión, asi que cuando queremos que este en ahorro de energía en la condición del loop() inclui  sleep_enable();    que es un modo de suspensión  y sleep_mode();   la que habilita la suspensión, y para deshabilitar la suspensión se utiliza sleep_disable();. 











