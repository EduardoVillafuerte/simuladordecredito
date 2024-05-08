#include <stdio.h>
#include "funciones.h"


int main(void) {

  float montocredito,interes,tiempo,captalapagarxanio;
  montocredito = Menu(1);
  interes = Menu(2);
  tiempo = Menu(3);
  captalapagarxanio = Capital_pagar_x_anio(montocredito,tiempo);
  calculosdecredito(tiempo,montocredito,interes,captalapagarxanio); 
  return 0;
}


