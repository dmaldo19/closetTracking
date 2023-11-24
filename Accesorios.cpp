#include "Accesorios.h" 

Accesorios::Accesorios(const Accesorios &rhs):Guardaropa(rhs){
    this->tipo = rhs.tipo;
    this->material = rhs.material;
}

Accesorios::Accesorios():Guardaropa(){}

Accesorios::Accesorios(int f, const string &m, const string &o, const string &t, const string &mat):Guardaropa(f, m, o), tipo(t), material(mat){};

Accesorios::~Accesorios(){}

Accesorios::Accesorios(Accesorios &&rhs):Guardaropa(move(rhs)),tipo{move(rhs.tipo)}, material{move(rhs.material)}{}

Accesorios & Accesorios::operator=(const Accesorios & rhs)
{
    if (this == &rhs) return *this;
    return *this;
}

void Accesorios::setTipo(const string &t){
    tipo = t;
}

string Accesorios::getTipo() const{
    return tipo;
}

void Accesorios::setMaterial(const string &m){
    material = m;
}

string Accesorios::getMaterial() const{
    return material;
}

bool Accesorios::operator==(const Accesorios& rhs) const {
    return Guardaropa::operator==(rhs) && (tipo == rhs.tipo) && (material == rhs.material);
}