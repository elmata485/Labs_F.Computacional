#include <iostream>
#include <cmath>
#include <omp.h>
#include <sys/time.h>

// Esta función se utiliza para calcular el tiempo que tarda
// la ejecución de ciertas funciones
// Está basada en el uso de una función primitiva que evalúa al tiempo
// // transcurrido desde cierto valor de referencia
  
double seconds()
{
  struct timeval tmp;
  double sec;
  gettimeofday( &tmp, (struct timezone *)0 );
  sec = tmp.tv_sec + ((double)tmp.tv_usec)/1000000.0;
  return sec;
}


int main(int argc, char* argv[]){

  std::cout << "Primera aplicación científica!" << std::endl;
  std::cout << "La idea es calcular el valor de pi mediante" << std::endl;
  std::cout << "la evualuación de una integral definida." << std::endl;
  std::cout << "La integral definida tiene una solución analítica," << std::endl;
  std::cout << "sin embargo, usando sumas de Riemann se puede evaluar" << std::endl;
  std::cout << "la integral de forma numérica." << std::endl;
  std::cout << "Usar --n para indicar el número de particiones" << std::endl;

  // Número de iteraciones se lee como entrada de la aplicación
  // Se desea que el número de argumentos sean dos:
  // El nombre del programa y el número de iteraciones
  if(argc != 3){
    std::cerr << "Usage: " << argv[0] << " --n [iterations]" << std::endl;
    exit(1);
  }
  // Ahora leemos el número de iteraciones
  int n;
  n = atoi(argv[2]); // Porqué dereferenciamos argv en la posición 2?

  // Cálculo de la integral
  // Vamos a usar el punto medio de los rectángulos para evaluar la función
  double sum = 0.0; // Valor de la suma
  double w = 1.0 / n; // Número de particiones
  
  double time_1 = seconds();


  
  #pragma omp parallel for reduction(+: sum)
  for(int i = 0; i < n; ++i){
    
    double x = w * (i - 0.5); // Variable independiente
    sum += 4.0 / (1.0 + (x * x)); // Evaluamos la función en el valor de x
      
  }

  double time_2 = seconds();

  // sum es una variable que contiene la altura de los rectangulos
  // area = altura * base
  double pi_approx = sum * w;

  
  std::cout << "Number of Threads: " << num_procs << std::endl;
  std::cout << "Time to complete loop: " << time_2 - time_1 << std::endl;


  std::cout.precision(10);
  std::cout << "Valor approximado de pi:" << std::endl;
  std::cout << pi_approx << std::endl;
  
  return 0;
}
