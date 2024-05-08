#include <stdio.h>

float Capital_pagar_x_anio(float montocredito,float tiempo){
  return montocredito/tiempo;
}

float Menu(int a){
  float valor;
  switch(a){
    case 1:
      printf("Ingresa el monto de credito\n");
      scanf("%f",&valor);
      break;
    case 2:
      printf("Ingresa la tasa de interes anual\n");
      scanf("%f",&valor);
      break;
    case 3:
      printf("Ingresa el tiempo de pago en años\n");
      scanf("%f",&valor);
      break;
  }
  return valor;
}

float Capital_rest_a_pagar(float montocredito, float captxanio, int i){
  float caprest = montocredito;
  if(i != 0){caprest = montocredito - captxanio;}
  return caprest;
}


float calcular_interes(float caprest,float interes){
  float interes_anio = (caprest*interes)/100;
  return interes_anio;
}

float calcular_capital_mas_interes(float interes_anio,float captxanio){
  float capital_mas_interes = captxanio + interes_anio;
  return capital_mas_interes;
}

float cuota_por_anio(float capital_mas_interes){
  float cuota_anio = capital_mas_interes/12;
  return cuota_anio;
}

float suma_total_interes(float interes_anio, float acum){
  float suma_interes_anio = acum + interes_anio;
  return suma_interes_anio;
}

float suma_total(float capital_mas_interes,float acum){
  float suma_capital_mas_interes = capital_mas_interes + acum;
  return suma_capital_mas_interes;
}

void imprimir_resultados(float capitalrestante[20],float interes_anio[20],float capital_mas_interes[20],float cuotames_x_anio[20],float suma_interes_anio,float suma_capital_mas_interes,float captalapagarxanio, float tiempo){
    printf("Capital restante a pagar: \t");
    for(int k = 0; k < tiempo; k++){
        if (k == 0){
        printf("%.2f\t",capitalrestante[k]);
        }
        else{
        printf("%.2f\t\t",capitalrestante[k]);  
        }
    }
    printf("\n");

    printf("Capital a pagar por año: \t");
    for(int k = 0; k < tiempo; k++){
        printf("%.2f\t\t",captalapagarxanio);}
    printf("\n");

    printf("Interes anual: \t\t\t");
    for(int k = 0; k < tiempo; k++){
        printf("%.2f\t\t",interes_anio[k]);}
    printf("\n");

    printf("Capital + Interes: \t\t");
    for(int k = 0; k < tiempo; k++){
        printf("%.2f\t\t",capital_mas_interes[k]);}
    printf("\n");

    printf("Cuota mensual por año: \t");
    for(int k = 0; k < tiempo; k++){
        printf("%.2f\t\t",cuotames_x_anio[k]);}
    printf("\n");
    printf("\n");
    printf("Suma total de interes anual:\t\t%.2f\n",suma_interes_anio);
    printf("Suma total de capital + interes: \t%.2f\n",suma_capital_mas_interes);
}


void calculosdecredito(float tiempo, float montocredito,float interes,float captalapagarxanio){
  float suma_interes_anio = 0,suma_capital_mas_interes=0;
  float capitalrestante[20],interes_anio[20],capital_mas_interes[20],cuotames_x_anio[20];
    for(int i = 0; i < tiempo; i++){
        capitalrestante[i]= Capital_rest_a_pagar(montocredito,captalapagarxanio,i);
        interes_anio[i]= calcular_interes(capitalrestante[i],interes);
        capital_mas_interes[i]= calcular_capital_mas_interes(interes_anio[i],captalapagarxanio);
        cuotames_x_anio[i]= cuota_por_anio(capital_mas_interes[i]);
        suma_interes_anio= suma_total_interes(interes_anio[i],suma_interes_anio); 
        suma_capital_mas_interes= suma_total_interes(capital_mas_interes[i],suma_capital_mas_interes);
        montocredito = capitalrestante[i]; 
    }
    imprimir_resultados(capitalrestante,interes_anio,capital_mas_interes,cuotames_x_anio,suma_interes_anio,suma_capital_mas_interes,captalapagarxanio,tiempo);

}