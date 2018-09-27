/* Ana Luisa Campos Magallanes
 * Instituto Tecnologico de León
 * Ingeniería en Sistemas Computacionales
 * Sistemas Programables 
 * 
 * Alarma notificadora de entrada de individuos
 */

//Declaración de constantes
const int SENSOR = 2;//Red switch
const int LED = 13;//Led del arduino
const int BOCINA = 3;//Buzzer

//Declaración de variables
volatile int estado = LOW;

void setup() {
  pinMode(SENSOR, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  //Interrupción que se activa cuando el reed suich tiene un cambio de estado y lleva al método cambio:
  attachInterrupt(digitalPinToInterrupt(SENSOR),cambio,CHANGE);
 
}

void loop() {
  digitalWrite(LED, estado);
  if(estado==HIGH)
    tone(BOCINA,440);
  else
    noTone(BOCINA);
}

//Método activado por la interrupción. Cambia el valor de la variable estado
void cambio(){
  estado = !estado;
}
