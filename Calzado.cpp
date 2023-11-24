#include "Calzado.h"

Calzado::Calzado(const Calzado &rhs):Estaciones(rhs){
    this->modelo = rhs.modelo;
}

Calzado::Calzado(int f, const string &m, const string &o, const string &cor, const string &col, 
                        const string &tip, const string &tel, const string &tal, const string &e, const string &mod):
Estaciones(f, m, o, cor, col, tip, tel, tal, e), modelo(mod){}

Calzado::Calzado():Estaciones(){}

Calzado::~Calzado(){}

Calzado::Calzado(Calzado &&rhs):Estaciones(move(rhs)), modelo{move(rhs.modelo)}{}

Calzado & Calzado::operator=(const Calzado & rhs)
{
    if (this == &rhs) return *this;
    return *this;
}

void Calzado::setModelo(const string &m){
    modelo = m;
}

string Calzado::getModelo () const{
    return modelo;
}

bool Calzado::operator==(const Calzado& rhs) const {
    return Estaciones::operator==(rhs) && (modelo == rhs.modelo);
}