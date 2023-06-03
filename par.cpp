#include <fstream>
#include <iostream>
#include <omp.h>
#include <sstream>
#include <vector>

#include <chrono>

struct Linea {
  int precio;
  std::string fecha;
  std::string estado;
};

struct Mes {
  unsigned long total;
  int cantidad;
};

void calcularInflacion(std::vector<Mes>& totales) {
  int i = 1;
  double inflacionAcumulada = 0.0;
  double ipcBase = (double)totales[0].total / (double)totales[0].cantidad;

  for (int month = 1; month < totales.size(); month++) {
    double ipcActual = (double)totales[month].total / (double)totales[month].cantidad;
    double variacionPorcentual = ((ipcActual - ipcBase) / ipcBase) * 100.0;
    inflacionAcumulada += variacionPorcentual;

    std::cout << "> MES: " << i++ << "\tIPC: " << ipcActual
              << "\tVARIACIÓN PORCENTUAL: " << variacionPorcentual << "%" << std::endl;
  }
  std::cout << "Inflación acumulada: " << inflacionAcumulada << "%" << std::endl;
}

int main() {
  std::ifstream inputfile("supermercado.csv", std::ifstream::binary);

  // Lee la primera linea
  std::string line;
  std::getline(inputfile, line);

  line = "";

  std::vector<Mes> totales(12);
  while (!inputfile.eof()) {
    std::vector<char> buffer(1024 * 1024 * 100, 0); // Leemos 100 MegaBytes
    std::vector<std::string> rows(2'000'000);
    inputfile.read(buffer.data(), buffer.size());
    std::stringstream buffer_stream(buffer.data());

    // Lee las lineas del archivo DESDE EL BUFFER
    do {
      std::string aux;
      std::getline(buffer_stream, aux);

      line += aux;

      // La linea esta incompleta
      if (buffer_stream.eof()) {
        // std::cout << line << std::endl;
        break;
      }

      rows.push_back(line);

      line = "";
    } while (!buffer_stream.eof());
    // Procesa las lineas del archivo.
    // Esto es paralelizable.
#pragma omp parallel for default(none) shared(rows, totales)
    for (int i=0; i< rows.capacity() ; i++) {
      auto e = rows[i];// Salta los espacios pre-alocados.
      if (e == "") {
        continue;
      }
      std::stringstream stream(e);
      Linea parsed;

      std::string word;
      // SKU
      std::getline(stream, word, ';');
      // Nombre
      std::getline(stream, word, ';');
      // Precio
      std::getline(stream, word, ';');
      try {
        parsed.precio = std::stoi(word.substr(1));
      } catch (std::invalid_argument error) {
        // std::cout << e << std::endl;
        continue;
      }
      // Descuento
      std::getline(stream, word, ';');

      std::getline(stream, parsed.fecha, ';');
      std::getline(stream, parsed.estado, ';');

      if (parsed.estado == "\"AUTHORIZED\"" ||
          parsed.estado == "\"FINALIZED\"") {

        stream = std::stringstream(parsed.fecha);
        // year
        std::getline(stream, word, '-');
        // month
        std::getline(stream, word, '-');

        int month = std::stoi(word) - 1;
        totales[month].total += parsed.precio;
        totales[month].cantidad++;
      }
    }
  }

  int i = 1;
  int cant = 0;
  for (auto month : totales) {
    cant += month.cantidad;
    std::cout << "> MES: " << i++ << "\tTOTAL: " << month.total
              << "\t CANT.:" << month.cantidad
              << "\tMEDIA: " << (double)month.total / (double)month.cantidad
              << std::endl;
  }

  std::cout << "Lineas totales: " << cant << std::endl;

  calcularInflacion(totales);


  return 0;
}
