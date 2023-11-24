#include "Prendas.h"

Prendas::Prendas(const Prendas &rhs):Guardaropa(rhs){
    this->corte = rhs.corte;
    this->color = rhs.color;
    this->tipo = rhs.tipo;
    this->tela = rhs.tela;
    this->talla = rhs.talla;
}

Prendas::Prendas():Guardaropa(){}

Prendas::Prendas(int f, const string &m, const string &o, const string &cor, const string &col, const string &tip, const string &tel, const string &tal):
Guardaropa(f, m, o), corte(cor), color(col), tipo(tip), tela(tel), talla(tal){}

Prendas::~Prendas(){}

Prendas::Prendas(Prendas &&rhs):Guardaropa(move(rhs)), corte{move(rhs.corte)},
      color{move(rhs.color)},tipo{move(rhs.tipo)}, tela{move(rhs.tela)}, talla{move(rhs.talla)} {}

Prendas & Prendas::operator=(const Prendas & rhs)
{
    if (this == &rhs) return *this;
    return *this;
}

void Prendas::setCorte(const string &c){
    corte = c;
}

string Prendas::getCorte () const{
    return corte;
}

void Prendas::setColor(const string &c){
    color = c;
}

string Prendas::getColor() const{
    return color;
}

void Prendas::setTipo(const string &t){
    tipo = t;
}

string Prendas::getTipo() const{
    return tipo;
}

void Prendas::setTela(const string &t){
    tela = t;
}

string Prendas::getTela() const{
    return tela;
}

void Prendas::setTalla(const string &t){
    talla = t;
}

string Prendas::getTalla() const{
    return talla;
}

bool Prendas::operator==(const Prendas& rhs) const {
    return Guardaropa::operator==(rhs) && (corte == rhs.corte) && (color == rhs.color) 
            && (tipo == rhs.tipo) && (tela == rhs.tela) && (talla == rhs.talla);
}