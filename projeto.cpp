#include <fstream>
#include <iostream>

using namespace std;

struct farmacia {
  long int codigo;
  char preco[10];
  char nome[100];
  char estado[8];
  char situacao[8];
};

int main() {
  fstream lendo;
  farmacia produto;
  lendo.open("base.dat", ios::binary | ios::in);
  lendo.read((char *)&produto, sizeof(farmacia));
  if (not lendo.good()){
    cout<<"here";
  }
  while (lendo.good()) {
    cout << produto.codigo;
    cout << endl;
    lendo.read((char *)&produto, sizeof(farmacia));
  };
  lendo.close();
}