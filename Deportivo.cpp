#include "Deportivo.h" 

Deportivo::Deportivo(const Deportivo &rhs):Estaciones(rhs){
    this->deporte = rhs.deporte;
}

Deportivo::Deportivo(int f, const string &m, const string &o, const string &cor, const string &col, 
                        const string &tip, const string &tel, const string &tal, const string &e, const string &dep):
Estaciones(f, m, o, cor, col, tip, tel, tal, e), deporte(dep){}

Deportivo::Deportivo():Estaciones(){}

Deportivo::~Deportivo(){}

Deportivo::Deportivo(Deportivo &&rhs):Estaciones(move(rhs)), deporte{move(rhs.deporte)}{}

Deportivo & Deportivo::operator=(const Deportivo & rhs)
{
    if (this == &rhs) return *this;
    return *this;
}

void Deportivo::setDeporte(const string &d){
    deporte = d;
}

string Deportivo::getDeporte () const{
    return deporte;
}

bool Deportivo::operator==(const Deportivo& rhs) const {
    return Estaciones::operator==(rhs) && (deporte == rhs.deporte);
}