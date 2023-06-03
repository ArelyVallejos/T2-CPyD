# T2-CPyD
Taller 2 para Computación Paralela y Distribuida, primer semestre 2023.
# Integrantes
Luz Arelý Castro Vallejos
Ian Vinzenzo Battistoni Fuentes
Vicente Velasquez
# Ejecución
El archivo sec.cpp ejecuta el codigo de forma secuencial y archivo par.cpp ejecuta el codigo de forma paralela.
# Secuencial
```bash
g++ main.cpp -o main -O2 && time ./sec
```
# OpenMP
```bash
g++ par.cpp -o par -fopenmp -O2 && time ./par
```
