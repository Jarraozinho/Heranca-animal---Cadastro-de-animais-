// Construtores e Destrutores em Hierarquia
// (C) Copyright Fernando Montenegro e Roberto Pacheco

#include <iostream>

using namespace std;

class Animal {
 protected :
  long quantidade;
  string origem;
 public :
  inline Animal (long qtde,string org);
  inline ~Animal ();
  void mostrar ();

};

class Bovino:public Animal {
 protected :
  string raca;
 public :
   inline Bovino (string marca, long qtde ,string org);
   inline ~Bovino ();
   void mostrar ();
};



class BovinoLeite : public Bovino {
   long producao_diaria;
  public :
   BovinoLeite (long prod, string marca, long qtde,string org);
   ~BovinoLeite ();
   void mostrar ();
};

class BovinoCorte : public Bovino {
   long peso_arroba;
  public :
   BovinoCorte (long prod, string marca, long qtde,string org);
   ~BovinoCorte ();
   void mostrar ();
};

/******************** Int Main do Programa *************************/

int main () {
  BovinoLeite vaca (100,"Holandesa",350,"Mato Grosso");
  vaca.mostrar();
  BovinoCorte vac (10,"Nelori",1000,"Mato Grosso do Sul");
  vac.mostrar();
  return 0;
}


/******************** Funcoes da Animal *************************/

Animal::Animal (long qtde,string org) {
    quantidade = qtde;
    origem = org;
  cout << "\nEstou construindo um Animal";
}
Animal::~Animal() {
  cout << "\nApagando um Animal ...";
}

void Animal::mostrar ()  {
  cout << "\nQuantidade de Animais : " << quantidade;
  cout << "\nOrigem do Animal : " << origem ;
}


/******************* Funcoes da Classe Bovino *******************/

Bovino::Bovino (string marca ,  long qtde, string org) : Animal (qtde,org)  {
  raca = marca;
  origem = org;
  cout << "\nEstou construindo um Bovino";
}

Bovino::~Bovino() {
 cout << "\nApagando um Bovino ...";
}

void Bovino::mostrar ()  {
   cout << "\nRaca : " << raca << endl;
   cout << "\nOrigem : " << origem << endl;
}

/*************** Funcoes da Classe BovinoLeite ******************/

BovinoLeite::BovinoLeite(long prod, string marca,long qtde ,string org)
   : Bovino(marca, qtde, org) {
         producao_diaria = prod;
         cout << "\nEstou construindo um Bovino leiteiro";
}

BovinoLeite::~BovinoLeite() {
  cout << "\nApagando um Bovino leiteiro ...";
}

void BovinoLeite::mostrar ()  {
   // uma maneira de implementar o metodo mostrar na classe BovinoLeite
   // metodo tem acesso aos dados protegidos das classes base
   cout << "\nFicha do gado Leiteiro" ;
   cout << "\n\nQuantidade de Animais : " << quantidade;
   cout << "\nRaca do Animal        : " << raca;
   cout << "\nProducao Diaria       : " << producao_diaria ;
   cout << "\nOrigem do animal       :" << origem;

   // outra forma de implementar o metodo mostrar na classe BovinoLeite
   Animal::mostrar();
   Bovino::mostrar();
   cout << "producao diaria :" << producao_diaria <<endl;
}

/*************** Funcoes da Classe BovinoCorte ******************/

BovinoCorte::BovinoCorte(long peso_arroba, string marca, long qtde , string org)
   : Bovino(marca, qtde, org) {
         peso_arroba = peso_arroba;
         cout << "\nEstou construindo um Bovino De Corte";
}

BovinoCorte::~BovinoCorte() {
  cout << "\nApagando um Bovino de Corte ...";
}

void BovinoCorte::mostrar ()  {
   // uma maneira de implementar o metodo mostrar na classe BovinoLeite
   // metodo tem acesso aos dados protegidos das classes base
   cout << "\n\nQuantidade de Animais : " << quantidade;
   cout << "\nRaca do Animal        : " << raca;
   cout << "\nPeso do animal       : " << peso_arroba;
   cout << "\nOrigem do animal       :" << origem ;

   // outra forma de implementar o metodo mostrar na classe BovinoLeite
   Animal::mostrar();
   Bovino::mostrar();
   cout << "peso arroba :" << peso_arroba << endl;
}
