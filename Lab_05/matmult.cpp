#include <iostream>
#include <vector>
#include <omp.h>
#include <sys/time.h>



double seconds() {
  struct timeval tmp;
  double sec;
  gettimeofday( &tmp, (struct timezone *)0 );
  sec = tmp.tv_sec + ((double)tmp.tv_usec)/1000000.0;
  return sec;
}

int main(int argc, char* argv[]){


  // Definamos la dimensión de las matrices mediante argumentos de la terminal
  if(argc != 7){
    std::cerr << "Usage: " << argv[0] << " --l [filas de A] --m [columnas de B] --n [columnas de A/filas de B]" << std::endl;
    exit(1);
  }
  // Ahora leemos las dimensiones
  int l, m, n;
  l = atoi(argv[2]);
  m = atoi(argv[4]);
  n = atoi(argv[6]);

  // Definamos nuestras matrices de entrada
  std::vector<double> A(l * n, 0.0); // Inicialización a 0.0
  std::vector<double> B(n * m, 0.0);
  std::vector<double> C(l * m, 0.0);

  // Inicialización de A
  for(int i = 0; i < l; ++i){
    for(int j = 0; j < n; ++j){
      A[(i * n) + j] = i;
    }
  }
  // Inicialización de B
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      B[(i * m) + j] = j;
    }
  }


  // C ya se encuentra inicializada en 0!
  // Eso significa que podemos hacer la suma parcial en cada uno de sus elementos

  int num_procs;
  double time_1 = seconds();
  double sum=0;
  #pragma omp parallel
  {
    num_procs = omp_get_num_threads();


    #pragma omp for 
    for(int i = 0; i < l; ++i){
      for(int j = 0; j < m; ++j){
        for(int k = 0; k < n; ++k){
          sum += A[(i * n) + k] * B[(k * m) + j];
        }
        C[(i*m)+j]=sum;
      }
    }
  } 
  double time_2 = seconds();
  std::cout << num_procs  << time_2 - time_1 << std::endl;

    
  return 0;
}



