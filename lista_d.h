#ifndef LISTA_D_H
#define LISTA_D_H
#include <iterator>
#include <iostream>
using namespace std;

template <typename objeto>
class lista_d
{
    public:
        lista_d(const lista_d <objeto> &rhs);
        ~lista_d();
        lista_d(lista_d <objeto> &&rhs);
        lista_d();
        lista_d <objeto> & operator=(const lista_d <objeto> & rhs);
        void iniciar();
        bool llena ();
        void insertar(const objeto &x);
        void insertar(objeto &&x);
        void push_b(const objeto &x);
        void push_b(objeto &&x);
        bool vacia() const;
        objeto & peek_p(int pos);
        objeto & peek_next(int pos);
        objeto & peek_previous(int pos);
        void push_f(const objeto &x);
        void push_f(objeto &&x);
        void pop_f();
        void pop_b();
        void pop_p(int pos);
        void push_p(const objeto &x, int pos);
        void push_p(objeto &&x, int pos);
        void swap(int, int);
        int tam();
        typename lista_d<objeto>::nodo* obtenerNodoEnPosicion(int pos) const;
        bool validacion(int pos);

    private:
        struct nodo
        {
            objeto dato;
            nodo *next;
            nodo *previous;
            nodo (const objeto &d=objeto{}, nodo *n=nullptr, nodo *p=nullptr):dato{d},next{n}, previous{p}
            {}
            nodo (objeto &&d=objeto{}, nodo *n=nullptr, nodo *p=nullptr):dato{move(d)},next{move(n)}, previous{move(p)}
            {}
        };
        nodo *head;
        nodo *tail;
        int tamanio;
        int capacidad;
    
    public:
        class iterador_const
        {
        	public:
        		iterador_const():actual{nullptr}
        		{}
                iterador_const(nodo *p) : actual(p)
                {
                }
        		const objeto & operator*()const
        		{
        			return recuperar();
				}
        
                iterador_const & operator++()
				{
					actual=actual->next;
					return *this;
				}
				iterador_const operator++(int)
				{
					iterador_const viejo=*this;
					++(*this);
					return viejo;
				}

				bool operator== (const iterador_const &rhs)const
				{
					return actual==rhs.actual;
				}
				bool operator!=(const iterador_const &rhs)const
				{
					return !(*this==rhs);
				}

                nodo* next() const{
                    return actual->next;
                }
                
            protected:
                nodo *actual;
                const objeto & recuperar() const
                {
                    return actual->dato;
                }
                friend class lista_d <objeto>;
		};
        
		class iterador:public iterador_const
		{
			public: 
                iterador()
                {
                }
                iterador(nodo *p) : actual(p)
                {
                }
                objeto & operator*()
                {
                    return iterador::recuperar();
                }

                nodo*& next()
                {
                    return actual->next;
                }
                
                iterador & operator++()
                {
                    this->actual=this->actual->next;
                    return *this;
                }
                iterador operator++(int)
                {
                    iterador viejo=*this;
                    ++(*this);
                    return viejo;
                }
                bool operator== (iterador &&rhs)
				{
					return actual==rhs.actual;
				}
				bool operator!=( iterador &&rhs)
				{
					return !(*this==rhs);
				}
			protected:
                nodo *actual;
                objeto & recuperar()
                {
                    return actual->dato;
                }
				friend class lista_d <objeto>;
		};

        const iterador_const begin_const() const{
            return iterador_const(head);
        }

        const iterador_const end() const{
            return iterador_const(tail);
        }

        iterador begin() {
            return iterador(head);
        }

        iterador end() {
            return iterador(tail);
        }
};

#endif // LISTA_D_H

template <typename objeto>
lista_d <objeto>::lista_d(const lista_d <objeto> &rhs)
{
            iniciar();
            for(auto &x:rhs);
                push_b(rhs);
            //copy ctor
}

template <typename objeto>
lista_d <objeto>::lista_d(lista_d <objeto> &&rhs):head{rhs.head},tail{rhs.tail},tamanio{rhs.tamanio},capacidad{rhs.capacidad}
{
            rhs.head=nullptr;
            rhs.tail=nullptr;
            rhs.tamanio=0;
            rhs.capacidad=10000;
}
template <typename objeto>
lista_d <objeto>::~lista_d()
{
	//metodo limpiar
    delete head;
    delete tail;
    //dtor
}
template <typename objeto>
lista_d <objeto>::lista_d()
{
    iniciar();
}
template <typename objeto>
lista_d <objeto> & lista_d <objeto>::operator=(const lista_d <objeto> & rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
template <typename objeto>
void lista_d <objeto>::iniciar()
{
	head=nullptr;
    tail=nullptr;
    tamanio=0;
    capacidad=10000;
}
template <typename objeto>
bool lista_d <objeto>::llena()
{
    if (tamanio==capacidad)
        return true;
    else
        return false;
}
template <typename objeto>
bool lista_d <objeto>::vacia() const
{
    if(head==nullptr)
        return true;
    else
        return false;
}

template <typename objeto>
void lista_d <objeto>::insertar(const objeto &x)
{
    nodo *p=new nodo{x,nullptr};
    p->next=head;
    if(head != nullptr){
        head -> previous = p;
    }
    head=p;
    tail=head;
    tamanio++;
}

template <typename objeto>
void lista_d <objeto>::insertar(objeto &&x)
{
    nodo *p=new nodo{move(x),nullptr};
    p->next=head;
    if(head != nullptr){
        head -> previous = p;
    }
    head=p;
    tail=head;
    tamanio++;
}

template <typename objeto>
void lista_d <objeto>::push_b(const objeto &x)
{
    if(vacia())
    {
      insertar(x);
    }
    else
    {
        nodo *p = new nodo{x,nullptr};
        tail->next=p;
        p -> previous = tail;
        tail=p;
        tamanio++;
	}
}
template <typename objeto>
void lista_d <objeto>::push_b(objeto &&x)
{
    if(vacia())
    {
      insertar(x);
    }
    else
    {
        nodo *p=new nodo{move(x),nullptr};
        tail->next=p;
        p -> previous = tail;
        tail=p;
        tamanio++;
	}
}
template <typename objeto>
void lista_d <objeto>::push_f(const objeto &x)
{
    if(vacia())
    {
      insertar(x);
    }
    else
    {
        nodo *p=new nodo{x,nullptr};
        p->next=head;
        if(head != nullptr){
            head->previous = p;
        }
        head=p;
        tamanio++;
    }
}
template <typename objeto>
void lista_d <objeto>::push_f(objeto &&x)
{
    if(vacia())
    {
      insertar(x);
    }
    else
    {
        nodo *p=new nodo{move(x),nullptr};
        p->next=head;
        if(head != nullptr){
            head->previous = p;
        }
        head=p;
        tamanio++;
	}
}

template <typename objeto>
void lista_d<objeto>::pop_f()
{
    if (vacia()) {
        cout << ("La lista esta vacia.");
    }
    nodo *temp = head;
    head = head->next;
    delete temp;
    if (head != nullptr) {
        head->previous = nullptr;
    }
    tamanio--;
}

template <typename objeto>
void lista_d<objeto>::pop_b() {
    if (vacia()) {
        cout << ("La lista esta vacia.");
    }

    if (head == tail) {
        // La lista tiene un solo elemento
        delete head;
        head = nullptr;
        tail = nullptr;
        tamanio = 0;
    }
    else{
        // La lista tiene más de un elemento
        nodo *penultimo = tail;
        tail = tail->previous;
        tail->next = nullptr;
        delete penultimo;
        tamanio--;
    }
}

template <typename objeto>
void lista_d<objeto>::pop_p(int pos)
{
    if (vacia()) { // Lista vacía
        cout << ("La lista esta vacia.");
    }else if(validacion(pos)){
        nodo *p = head;
        for(int i = 0; i < pos - 1; i++){
            p = p->next;
        }
        nodo *del = p->next;
        nodo *aft = del->next;
        p->next = aft;
        aft->previous = p;
        delete del;
        --tamanio;
    } else {
        cout << ("Posicion invalida.");
    }
}



template <typename objeto>
void lista_d <objeto>::push_p(const objeto &x, int pos)
{
    if(vacia())
    {
      insertar(x);
    }
    else if(validacion(pos))
    {
        nodo *pre, *aft;
		pre=head;
		for(int k=0;k<pos-1;k++){
            pre=pre->next;
        }
		aft=pre->next;
		nodo *p=new nodo{x,nullptr};
		p->next=aft;
        aft->previous=p;
		pre->next=p;
        p->previous=pre;
        tamanio++;
	}
	else if(pos<=0){
        push_f(x);
    }
    else{
        push_b(x);
    }
}
template <typename objeto>
void lista_d <objeto>::push_p(objeto &&x, int pos)
{
    if(vacia())
    {
        insertar(x);
    }
    else if(validacion(pos))
    {
        nodo *pre, *aft;
		pre=head;
		for(int k=0;k<pos-1;k++){
            pre=pre->next;
        }
		aft=pre->next;
		nodo *p=new nodo{move(x),nullptr};
		p->next=aft;
        aft->previous=p;
		pre->next=p;
        p->previous=pre;
        tamanio++;
	}
	else if(pos<=0){
        push_f(x);
    }
    else{
        push_b(x);
    }
}
template <typename objeto>
bool lista_d <objeto>::validacion(int pos)
{
	if(pos > 0 && pos < tamanio){
        return true;
    }
    else{
        return false;
    }
}

template <typename objeto>
objeto & lista_d <objeto>::peek_p(int pos)
{
    if (vacia() || pos < 0 || pos > tamanio) {
        cout << ("La lista esta vacia o la posicion es invalida");
    }
    nodo *elemento = head;
    for (int i = 0; i < pos && elemento->next != nullptr; i++)
    {
        elemento = elemento->next;
    }
    return elemento->dato;
}

template <typename objeto>
objeto & lista_d <objeto>::peek_next(int pos)
{
    if (vacia() || pos < 0 || pos > tamanio) {
        cout << ("La lista esta vacia o la posicion es invalida");
    }
    nodo *elemento = head;
    for (int i = 0; i < pos && elemento->next != nullptr; i++)
    {
        elemento = elemento->next;
    }
    if(elemento -> next == nullptr){
        cout << ("La posicion es invalida");
    }
    elemento = elemento ->next;
    return elemento->dato;
}

template <typename objeto>
objeto & lista_d <objeto>::peek_previous(int pos)
{
    if (vacia() || pos < 0 || pos > tamanio) {
        cout << ("La lista esta vacia o la posicion es invalida");
    }
    nodo *elemento = head;
    for (int i = 0; i < pos && elemento->next != nullptr; i++)
    {
        elemento = elemento->next;
    }
    if(elemento -> previous == nullptr){
        cout << ("La posicion es invalida");
    }
    elemento = elemento->previous;
    return elemento->dato;
}

template <typename objeto>
int lista_d <objeto>::tam(){
    return tamanio;
}

//Sirve para intercambiar la posicion de dos nodos, ayuda en quicksort
template<typename objeto>
void lista_d<objeto>::swap(int posicion1, int posicion2) {
    if (posicion1 < 0 || posicion1 >= tam() || posicion2 < 0 || posicion2 >= tam()) {
        // Verificar si las posiciones son válidas
        cout << "Error: Posiciones invalidas para el intercambio." << endl;
    }
    
    nodo* nodo1 = obtenerNodoEnPosicion(posicion1);
    nodo* nodo2 = obtenerNodoEnPosicion(posicion2);
    
    //Utiliza un objeto temporal para intercambiar los nodos
    objeto temp = nodo1->dato;
    nodo1->dato = nodo2->dato;
    nodo2->dato = temp;
}

//Metodo para saber en que posicion se encuentra un nodo
template<typename objeto>
typename lista_d<objeto>::nodo* lista_d<objeto>::obtenerNodoEnPosicion(int pos) const {
    if (vacia() || pos < 0 || pos > tamanio) {
        throw out_of_range("La lista esta vacia o la posicion es invalida");
    } else{
        nodo *elemento = head;
        for (int i = 0; i < pos && elemento->next != nullptr; i++)
        {
            elemento = elemento->next;
        }
        //En vez de retornar solo la parte dato, retorna todo el nodo
        return elemento;
    }
}
