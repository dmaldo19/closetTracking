#include "Tops.h" 

Tops::Tops(const Tops &rhs):Estaciones(rhs){
    this->estampado = rhs.estampado;
    this->longitud = rhs.longitud;
}

Tops::Tops():Estaciones(){}

Tops::Tops(int f, const string &m, const string &o, const string &cor, const string &col, 
                        const string &tip, const string &tel, const string &tal, const string &e, const string &est, float l):
Estaciones(f, m, o, cor, col, tip, tel, tal, e), estampado(est), longitud(l){}

Tops::~Tops(){}

Tops::Tops(Tops &&rhs):Estaciones(move(rhs)), estampado{move(rhs.estampado)}, longitud{move(rhs.longitud)}{}

Tops & Tops::operator=(const Tops & rhs)
{
    if (this == &rhs) return *this;
    return *this;
}

void Tops::setEstampado(const string &e){
    estampado = e;
}

string Tops::getEstampado () const{
    return estampado;
}

void Tops::setLongitud(float l){
    longitud = l;
}

float Tops::getLongitud () const{
    return longitud;
}

bool Tops::operator==(const Tops& rhs) const {
    return Estaciones::operator==(rhs) && (estampado == rhs.estampado) && (longitud == rhs.longitud) && (tipo == rhs.tipo);
}