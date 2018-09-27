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
}

//Cambia el estado si hubo un cambio en el reed switch
void cambio(){
  estado = !estado;
}
