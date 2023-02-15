#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

struct farmacia {
  long int codigo;
  char preco[10];
  char nome[100];
  char estado[8];
  char situacao[8];
};



int main() {

  ofstream baseBin("base.dat", ios::binary);
  ifstream base("base.csv");
  farmacia produto;
  const char *mascara = "%ld, %[^;], %[^;], %[^;], %[^;]";

  string input;

  while (getline(base, input)) {

    sscanf(input.c_str(), mascara, &produto.codigo, &produto.preco,
           &produto.nome, &produto.estado, &produto.situacao);
    baseBin.write((char *)&produto, sizeof(farmacia));

    
  }

  return 0;
}