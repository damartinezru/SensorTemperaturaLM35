#include <SoftwareSerial.h>
SoftwareSerial BT1(3, 2); // RX | TX
int n1;
float temp;
int sensorPin = A0;//Declaramos el Pin analógico que usaremos.
int sensorValue=0;//Variable para guardar la lectura del Pin analógico.
int temC=0;//Variable para calcular los grados Celsius.

void setup()
 {Serial.begin(9600);
 BT1.begin(9600);
 pinMode(8,OUTPUT);
 pinMode(9,OUTPUT);
 }
void loop() 
{ while (BT1.available() >0 )
 {char c = BT1.read();
 if (c == 71) 
 {Serial.println("peticion web enviada");
 delay(500);
 servidor();
 }
 } 
}
void escribir(String text)
{BT1.print("AT+CIPSEND=0,"); 
 BT1.println(text.length());
 if (BT1.find(">")) // Si se recibe el mensaje
 {Serial.println(text);
 BT1.println(text); //mandamos el mensaje por el wifi 
 delay(10);
 while ( BT1.available() > 0 ) 
 {if ( BT1.find("SEND OK") ) //buscamos "ok" y luego salimos
 break; 
 }
 }
}
void servidor(void) 
 { escribir("<!DOCTYPE HTML>");
 escribir("<html>"); //una pagina web necesita esto <HTML> y </HTML> es el inicio y fin del documento
 escribir("<head><DIV align=\"center\"><title>Lm35 arduino con modulo wifi esp8266 html</title></DIV)"); //nombre de la pestaÃ±a que llevara la pagina
 escribir("<meta http-equiv=\"refresh\" content=\"5\"></head>"); //tiempo para refrescar la pagina web
 escribir("<body><DIV align=\"center\"><h3> <FONT SIZE=\"18\" COLOR=\"red\"> GRUPO #4 - MICROCONTROLADORES 2017-3 </h3></DIV>"); //titulo del inicio de la pagina
 escribir(" <BODY BGCOLOR=\"white\"> "); 
  sensorValue = analogRead(sensorPin);//Leemos el Pin analógico 
  temC=(((5 * sensorValue)*100)/1024);//Calculamos la temperatura en ºC.
 escribir("<FONT FACE=\"Arial\" SIZE=\"12\" COLOR=\"blue\"> la temperatura es </FONT>"); //escribimos y cambiamos el tamaÃ±o, letra y color
 escribir(String(-1*temC)); //imprimimos la variable
 escribir(" grados <br /><br />");
 escribir ("<iframe src=\"https://drive.google.com/open?id=0B8h_plFn_3IyN293ZlFmSU51aEU\"></iframe>");

 escribir("<DIV align=\"center\"><A HREF=\"http://modulowifiesp8266.blogspot.com.co/2017/12/sensor-de-temperatura-lm35.html\" target=\"_blank\">INFORMACION LM35</a><BR></DIV>");
  escribir("<DIV align=\"center\"><A HREF=\"https://modulowifiesp8266.blogspot.com.co/2017/12/modulo-wifi-esp-8266.html\" target=\"_blank\">INFORMACION ESP8266</a><BR></DIV>");
   escribir("<DIV align=\"center\"><A HREF=\"http://modulowifiesp8266.blogspot.com.co/2017/12/conexiones-modulo-wifi-y-lm35-arduino.html\" target=\"_blank\">INFORMACION CONEXIONES ARDUINO LM35 Y ESP8266</a><BR></DIV>");
    escribir("<DIV align=\"center\"><A HREF=\"https://modulowifiesp8266.blogspot.com.co/2017/12/grafica-de-temperatura-diferentes.html\" target=\"_blank\">GRAFICAS DE TEMPERATURA </a><BR></DIV>");
 delay(1);
 BT1.println("AT+CIPCLOSE=0");
 }
 //delay(500);

