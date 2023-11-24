#include "CuerpoCompleto.h" 

CuerpoCompleto::CuerpoCompleto(const CuerpoCompleto &rhs):Estaciones(rhs){
    this->estampado = rhs.estampado;
    this->longitud = rhs.longitud;
}

CuerpoCompleto::CuerpoCompleto(int f, const string &m, const string &o, const string &cor, const string &col, 
                        const string &tip, const string &tel, const string &tal, const string &e, const string &est, float l):
Estaciones(f, m, o, cor, col, tip, tel, tal, e), estampado(est), longitud(l){}

CuerpoCompleto::CuerpoCompleto():Estaciones(){}

CuerpoCompleto::~CuerpoCompleto(){}

CuerpoCompleto::CuerpoCompleto(CuerpoCompleto &&rhs):Estaciones(move(rhs)),estampado{move(rhs.estampado)}, longitud{move(rhs.longitud)}{}

CuerpoCompleto & CuerpoCompleto::operator=(const CuerpoCompleto & rhs)
{
    if (this == &rhs) return *this;
    return *this;
}

void CuerpoCompleto::setEstampado(const string &e){
    estampado = e;
}

string CuerpoCompleto::getEstampado () const{
    return estampado;
}

void CuerpoCompleto::setLongitud(float l){
    longitud = l;
}

float CuerpoCompleto::getLongitud () const{
    return longitud;
}

bool CuerpoCompleto::operator==(const CuerpoCompleto& rhs) const {
    return Estaciones::operator==(rhs) && (estampado == rhs.estampado) && (longitud == rhs.longitud);
}