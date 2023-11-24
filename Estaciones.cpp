
#include "Estaciones.h" 

Estaciones::Estaciones(const Estaciones &rhs):Prendas(rhs){
    this->estacion = rhs.estacion;
}

Estaciones::Estaciones():Prendas(){}

Estaciones::Estaciones(int f, const string &m, const string &o, const string &cor, const string &col, 
                        const string &tip, const string &tel, const string &tal, const string &e):
Prendas(f, m, o, cor, col, tip, tel, tal), estacion(e){}

Estaciones::~Estaciones(){}

Estaciones::Estaciones(Estaciones &&rhs):Prendas(move(rhs)),estacion{move(rhs.estacion)}{}

Estaciones & Estaciones::operator=(const Estaciones & rhs)
{
    if (this == &rhs) return *this;
    return *this;
}

void Estaciones::setEstacion(const string &e){
    estacion = e;
}

string Estaciones::getEstacion() const{
    return estacion;
}

bool Estaciones::operator==(const Estaciones& rhs) const {
    return Prendas::operator==(rhs) && (estacion == rhs.estacion);
}