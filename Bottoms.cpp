#include "Bottoms.h" 

Bottoms::Bottoms(const Bottoms &rhs):Estaciones(rhs){
    this->estampado = rhs.estampado;
    this->longitud = rhs.longitud;
}

Bottoms::Bottoms():Estaciones(){}

Bottoms::Bottoms(int f, const string &m, const string &o, const string &cor, const string &col, 
                        const string &tip, const string &tel, const string &tal, const string &e, const string &est, float l):
Estaciones(f, m, o, cor, col, tip, tel, tal, e), estampado(est), longitud(l){}

Bottoms::~Bottoms(){}

Bottoms::Bottoms(Bottoms &&rhs):Estaciones(move(rhs)), estampado{move(rhs.estampado)}, longitud{move(rhs.longitud)}{}

Bottoms & Bottoms::operator=(const Bottoms & rhs)
{
    if (this == &rhs) return *this;
    return *this;
}

void Bottoms::setEstampado(const string &e){
    estampado = e;
}

string Bottoms::getEstampado () const{
    return estampado;
}

void Bottoms::setLongitud(float l){
    longitud = l;
}

float Bottoms::getLongitud () const{
    return longitud;
}

bool Bottoms::operator==(const Bottoms& rhs) const {
    return Estaciones::operator==(rhs) && (estampado == rhs.estampado) && (longitud == rhs.longitud) && (tipo == rhs.tipo);
}