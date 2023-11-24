//Gonzalez Medina Maria Emma Valeria
//Hernandez Garcia Daira Daniela Yazmin
//Macias Ramirez Omar Ulises
//Maldonado Melendez Diego Alberto
//Sanchez Sanchez Jaime Ivan

//Definicion de la clase guardaropa que es la clase padre de todas
#include "Guardaropa.h"

Guardaropa::Guardaropa(const Guardaropa &rhs){
    // Copiar los atributos de marca y ocasion del objeto rhs al nuevo objeto
    this->marca = rhs.marca;
    this->ocasion = rhs.ocasion;
}

Guardaropa::Guardaropa(){}

Guardaropa::Guardaropa(int f, const string &m, const string &o):folio(f), marca(m), ocasion(o){}

Guardaropa::~Guardaropa(){}

Guardaropa::Guardaropa(Guardaropa &&rhs):folio{move(rhs.folio)}, marca{move(rhs.marca)}, ocasion{move(rhs.ocasion)}{}

Guardaropa & Guardaropa::operator=(const Guardaropa & rhs)
{
    if (this == &rhs) return *this;
    return *this;
}

void Guardaropa::setMarca(const string &m){
    marca = m;
}

string Guardaropa::getMarca() const{
    return marca;
}

void Guardaropa::setOcasion(const string &o){
    ocasion = o;
}

string Guardaropa::getOcasion() const{
    return ocasion;
}

bool Guardaropa::operator==(const Guardaropa& rhs) const {
    return (marca == rhs.marca) && (ocasion == rhs.ocasion);
}

void Guardaropa::setFolio(int f){
    folio = f;
}

int Guardaropa::getFolio() const{
    return folio;
}