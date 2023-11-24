/*
Maldonado Melendez Diego Alberto
*/

//Se hace llamada a todas las clases a usar

//ACLARACION

//Dependiendo del compilador, puede requerirse que se escriba .cpp o .h en los includes
// si no compila, utilizar la otra opcion

#include "lista_d.h"
#include "Guardaropa.cpp"
#include "Prendas.cpp"
#include "Accesorios.cpp"
#include "Bottoms.cpp"
#include "Calzado.cpp"
#include "CuerpoCompleto.cpp"
#include "Deportivo.cpp"
#include "Estaciones.cpp"
#include "Tops.cpp"

/*#include "lista_d.h"
#include "Guardaropa.h"
#include "Prendas.h"
#include "Accesorios.h"
#include "Bottoms.h"
#include "Calzado.h"
#include "CuerpoCompleto.h"
#include "Deportivo.h"
#include "Estaciones.h"
#include "Tops.h"*/

using namespace std;

//Prototipo de la funcion menu principal
template <typename objeto>
void menu_principal(lista_d<objeto>& mi_lista);

//Prototipo de la funcion agregar
template <typename objeto>
void agregar(lista_d<objeto>& mi_lista);

//Prototipo de la funcion eliminar
template <typename objeto>
void eliminar(lista_d<objeto>& mi_lista);

//Prototipo de la funcion editar
template <typename objeto>
void editar(lista_d<objeto>& mi_lista);

//Prototipo de la funcion buscar
template <typename objeto>
void buscar(lista_d<objeto>& mi_lista);

//Prototipo de la funcion ordenar
template <typename objeto>
void ordenar(lista_d<objeto>& mi_lista);

//Prototipo de la funcion consultar
template <typename objeto>
void consultar(lista_d<objeto>& mi_lista);

//Prototipo de la funcion busqueda binaria recursiva
template<typename objeto>
int recursividadBB(lista_d<objeto>& mi_lista, int buscar, int inicio, int fin);

//Prototipo de la funcion particion, que se usa en quicksort
template<typename objeto>
int partition(lista_d<objeto>& mi_lista, int low, int high);

//Prototipo de la funcion quicksort
template<typename objeto>
void quicksort(lista_d<objeto>& mi_lista, int low, int high);

int main(){
    //Inicializamos algunos valores para tener en la lista
    //Se crea la lista de apuntadores guardaropas para asi poder guardar cualquier elemento de cualquier clase hija de guardaropa
    lista_d<Guardaropa*> guardaropa;
    Prendas* prenda1 = new Prendas(1, "Adidas", "Dormir", "largo", "azul", "Pantalon Pijama", "Algodon", "S");
    Bottoms* prenda2 = new Bottoms(2, "Nike", "Escuela", "Hasta rodillas", "Negro", "Short", "Tweed", "M", "Verano", "Unicolor", 20);
    Accesorios* prenda3 = new Accesorios(3, "Pandora", "Elegante", "Collar", "Plata");
    Calzado* prenda4 = new Calzado(4, "Nike", "Casual", "Low", "Blanco y negro", "Tenis", "Cuero", "9 1/2", "Verano", "Air Force");
    //Agregamos los valores a la lista
    guardaropa.push_f(prenda1);
    guardaropa.push_b(prenda2);
    guardaropa.push_b(prenda4);
    guardaropa.push_p(prenda3, 2);
    menu_principal(guardaropa);
    
    return 0;
}

template <typename objeto>
void menu_principal(lista_d<objeto>& mi_lista){
    //Menu modularizado
    int opcion;
    int decision = 0;
    do{
        cout << "\nBienvenid@ a tu Guardaropa!" << endl;
        cout << "Tus opciones son: " << endl;
        cout << "1. Agregar" << endl;
        cout << "2. Eliminar" << endl;
        cout << "3. Editar" << endl;
        cout << "4. Busqueda" << endl;
        cout << "5. Ordenamiento" << endl;
        cout << "6. Consultar" << endl;
        cout << "7. Salir" << endl;
        cout << "Seleccione la opcion deseada: ";
        cin >> opcion;
        switch(opcion) {
            case 1:
                agregar(mi_lista);
                break;
            case 2:
                eliminar(mi_lista);
                break;
            case 3:
                editar(mi_lista);
                break;
            case 4:
                buscar(mi_lista);
                break;
            case 5:
                ordenar(mi_lista);
                break;
            case 6:
                consultar(mi_lista);
                break;
            case 7:
                cout << "Esta segur@ que desea salir?" << endl;
                cout << "0: No.\n1: Si: ";
                cin >> decision;
                break;
            default:
                cout << "Opción inválida. Intente de nuevo." << endl;
                break;
        }
    }
    while (decision != 1);
}

//Definicion de funcion agregar
template <typename objeto>
void agregar(lista_d<objeto>& mi_lista){
    int folio;
    string marca, ocasion, material, tipo, corte, color, tela, talla, estacion, estampado, modelo, deporte;
    float longitud;
    Guardaropa* prendaAgregar;
    cout << endl;
    cout << "\nEste es el apartado para agregar algo a tu Guardaropa." << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "Indicar si sera un accesorio o una prenda:" << endl;
    cout << "0: Accesorio.\n1: Prenda." << endl;
    cout << "Indique la opcion deseada: ";
    int accesorio_o_prenda;
    cin >> accesorio_o_prenda;
    cout << "Indique el numero de folio: ";
    cin >> folio;
    int folioRepetido = 0;

    //Validacion si ya existe una prenda con dicho folio
    Guardaropa* temporal;
    lista_d<Guardaropa*>::iterador itr = mi_lista.begin();

    //Se usa un iterador para verificar si hay algun elemento con ese folio
    for(int i = 0; i<mi_lista.tam(); i++){
        temporal = *itr;
        if(&itr == nullptr){
            break;   
        }
        if (temporal == nullptr) {
                break;
        }
        if(folio == temporal->getFolio()){//Si existe ya el folio en mi lista, lo indico
            folioRepetido = 1;
            break;
        }
        else{
            folioRepetido = 0;
        }
        itr++;
    }

    while (folioRepetido != 0){ //Mientras se ponga un folio que está en la lista, se pedirá que se increse nuevamente 
        cout << endl;
        cout << "Este folio ya existe. Intente de nuevo." << endl;
        cout << "Indique el folio: ";
        cin >> folio;
        // Variable adicional para indicar si se encuentra un folio repetido
        bool encontrado = false;
        itr = mi_lista.begin();
        for(int i = 0; i<mi_lista.tam(); i++){
            temporal = *itr;
            if(&itr == nullptr){
                break;   
            }
            if (temporal == nullptr) {
                break;
            }
            if(folio == temporal->getFolio()){//Si existe ya el folio en mi lista, lo indico
                encontrado = true;
                break;
            }
            itr++;
        }
        if(!encontrado){
            folioRepetido = 0;
        }
    }
    
    cin.ignore();
    cout << "\nIngrese la marca: ";
    getline(cin, marca);

    cout << "\nIngrese la ocasion: ";
    getline(cin, ocasion);
    
    switch (accesorio_o_prenda)
    {
    case 0: //Agregar accesorios
        cout << "\nIngrese el material: ";
        getline(cin, material);
        cout << "\nIngrese el tipo: ";
        getline(cin, tipo);
        prendaAgregar = new Accesorios(folio, marca, ocasion, tipo, material);
        break;
    
    case 1: //Agregar prenda
        cout << "\nIngrese el corte: ";
        getline(cin, corte);
        cout << "\nIngrese el color: ";
        getline(cin, color);
        cout << "\nIngrese el tipo: ";
        getline(cin, tipo);
        cout << "\nIngrese la tela: ";
        getline(cin, tela);
        cout << "\nIngrese la talla: ";
        getline(cin, talla);
        cout << "\nIngrese la estacion: ";
        getline(cin, estacion);
        cout << "\nIndicar que tipo de prenda es: " << endl;
        cout << "0: Bottoms.\n1: Tops.\n2: Cuerpo completo.\n3: Calzado. \n4: Deportivo." << endl;
        cout << "Seleccione la opcion que desea: ";
        int tipoPrenda;
        cin >> tipoPrenda;
        switch (tipoPrenda) //Agregar dependiendo del tipo de prenda
        {
        case 0: //Bottoms
            cin.ignore();
            cout << "\nIngrese el estampado: ";
            getline(cin, estampado);
            cout << "\nIngrese la longitud en cm: ";
            cin >> longitud;
            prendaAgregar = new Bottoms(folio, marca, ocasion, corte, color, tipo, tela, talla, estacion, estampado, longitud);
            break;
        
        case 1: //Tops
            cin.ignore();
            cout << "\nIngrese el estampado: ";
            getline(cin, estampado);
            cout << "\nIngrese la longitud en cm: ";
            cin >> longitud;
            prendaAgregar = new Tops(folio, marca, ocasion, corte, color, tipo, tela, talla, estacion, estampado, longitud);
            break;
        
        case 2: //Cuerpo Completo
            cin.ignore();
            cout << "\nIngrese el estampado: ";
            getline(cin, estampado);
            cout << "\nIngrese la longitud en cm: ";
            cin >> longitud;
            prendaAgregar = new CuerpoCompleto(folio, marca, ocasion, corte, color, tipo, tela, talla, estacion, estampado, longitud);
            break;
        
        case 3: //Calzado
            cin.ignore();
            cout << "\nIngrese el modelo: ";
            getline(cin, modelo);
            prendaAgregar = new Calzado(folio, marca, ocasion, corte, color, tipo, tela, talla, estacion, modelo);
            break;
        
        case 4: //Deportivo
            cin.ignore();
            cout << "\nIngrese el deporte: ";
            getline(cin, deporte);
            prendaAgregar = new Deportivo(folio, marca, ocasion, corte, color, tipo, tela, talla, estacion, deporte);
            break;
        
        default:
            cout << "Opcion invalida. Intente de nuevo." << endl;
            break;
        }
        break;
    
    default:
        cout << "Opcion invalida. Intente de nuevo." << endl;
        break;
    }
    cout << endl;
    cout << "Indique si desea ingresar al inicio, final o en una posicion:" << endl;
    cout << "0: Inicio.\n1: Final.\n2: Posicion."<<endl;
    cout << "Seleccione la opcion que desea: ";
    int dondeAgregar;
    cin >> dondeAgregar;
    switch (dondeAgregar){
        case 0: //Agregando al inicio
            cout << "Agregando al inicio..." << endl;
            mi_lista.push_f(prendaAgregar);
            break;
        
        case 1: //Agregando al final
            cout << "Agregando al final..." << endl;
            mi_lista.push_b(prendaAgregar);
            break;
        
        case 2:
            int posicion;
            cout << "Indique la posicion a donde ingresar." << endl;
            cout << "Debe ser una posicion entre 1 y " << mi_lista.tam() - 1<<":";
            cin >> posicion;
            cout << "\nAgregando en posicion...";
            mi_lista.push_p(prendaAgregar, posicion);
            break;
        
        default:
            cout << "Opción inválida. Intente de nuevo." << endl;
            break;
    }
}

//Definicion de funcion eliminar
template <typename objeto>
void eliminar(lista_d<objeto>& mi_lista){
    cout << endl;
    cout << "\nEste es el apartado para eliminar algo a tu Guardaropa." << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "Indique si desea eliminar al inicio, final o en una posicion:" << endl;
    cout << "0: Inicio.\n1: Final.\n2: Posicion."<<endl;
    cout << "Seleccione la opcion que desea: ";
    int dondeEliminar;
    cin >> dondeEliminar;
    switch (dondeEliminar){
        case 0: //Eliminando al inicio
        //Validacion de si esta vacia la lista
            if(!mi_lista.vacia()){
                cout << "Eliminando al inicio..." << endl;
                mi_lista.pop_f();
            } else{
                cout << "La lista esta vacia. No hay nada para eliminar." << endl;
            }
            break;
        
        case 1: //Eliminando al final
            if(!mi_lista.vacia()){
                cout << "Eliminando al final..." << endl;
                 mi_lista.pop_b();
            } else{
                cout << "La lista esta vacia. No hay nada para eliminar." << endl;
            }
            break;
        
        case 2:
            if(mi_lista.tam() <= 2){//Si hay menos de dos elementos, se vuelve caotico eliminar por posicion
                cout << "Se requieren minimo dos elementos para eliminar por posicion. Ingrese elementos para poder eliminar.";
            }
            else{
                //Validacionde lista vacia
                if(!mi_lista.vacia()){
                    int posicion;
                    cout << "Indique la posicion que desea eliminar." << endl;
                    cout << "Debe ser una posicion entre 1 y " << mi_lista.tam() - 1<<":";
                    cin >> posicion;
                    cout << "\nEliminando en posicion...";
                    mi_lista.pop_p(posicion);
                } else{
                    cout << "La lista esta vacia. No hay nada para eliminar." << endl;
                }
            }
            break;
        
        default:
            cout << "Opcion invalida. Intente de nuevo." << endl;
            break;
    }   
}

//Definicion de funcion editar
template <typename objeto>
void editar(lista_d<objeto>& mi_lista){
    //Validacion por si esta vacia la lista
    if(!mi_lista.vacia()){
        int decision;
        cout << endl;
        cout << "\nEste es el apartado para editar algo a tu Guardaropa." << endl;
        cout << "-------------------------------------------------------" << endl;
        cout << "Ingresa el numero de folio del articulo a editar: ";
        int folio;
        cin >> folio;
        int posicionFolio = recursividadBB(mi_lista, folio, 0, mi_lista.tam()-1);
        //Validacion si dicho folio esta en la lista
        if (posicionFolio != -1){
            //Creo un objeto ejemplo para saber a que clase pertenece el elemento
            Guardaropa* ejemplo = mi_lista.peek_p(posicionFolio);

            //Si mi elemento pertenece a accesorios, entonces mostrara los atributos de un accesorio
            if (Accesorios* accesorios = dynamic_cast<Accesorios*> (ejemplo)) {
                cout << "\nEl articulo a editar es: " << endl;
                cout << "Folio: " << accesorios->getFolio() << ". Marca: " << accesorios->getMarca() << 
                ". Ocasion: " << accesorios->getOcasion() << ". Tipo: " << accesorios-> getTipo() 
                << ". Material: " << accesorios->getMaterial() << endl;

            } else if(Prendas* prendas = dynamic_cast<Prendas*> (ejemplo)){
                cout << "\nEl articulo a editar es: " << endl;
                cout << "Folio: " << prendas->getFolio() << ". Marca: " << prendas->getMarca() << 
                ". Ocasion: " << prendas->getOcasion() << ". Tipo: " << prendas-> getTipo() 
                << ". Talla: " << prendas->getTalla() << endl;
            }
            //Si mi elemento pertenece a prendas, se mostrara al usuario los atributos de una prenda
            /*Nota: Cabe destacar que un objeto prenda tambien puede ser un Tops o Bottoms. 
            No obstante, se establecio en que solo se muestran los atributos de la clase prenda ya que esta contiene los atributos 
            mas importantes, a su vez que para ahorrar codigo y hacerlo mas eficiente. Aun asi, se podrian
            crear validaciones para que muestre todos los atributos de todas las clases hijas*/

            cout << "Esta segur@ que desea editar el articulo de este folio?" << endl;
            cout << "0: No, 1: Si: ";
            cin >> decision;
            //Verifica si el usuario si quiere editar
            if(decision){ //Se editan todos los aspectos del elemento, manteniendo el mismo numero de folio
                Guardaropa* prendaAgregar;
                string marca, ocasion, material, tipo, corte, color, tela, talla, estacion, estampado, modelo, deporte;
                float longitud;
                cout << "Indicar si sera un accesorio o una prenda:" << endl;
                cout << "0: Accesorio.\n1: Prenda." << endl;
                cout << "Indique la opcion deseada: ";
                int accesorio_o_prenda;
                cin >> accesorio_o_prenda;
                cin.ignore();
                cout << "\nIngrese la marca: ";
                getline(cin, marca);

                cout << "\nIngrese la ocasion: ";
                getline(cin, ocasion);
                
                switch (accesorio_o_prenda)
                {
                case 0: //Agregar accesorios
                    cout << "\nIngrese el material: ";
                    getline(cin, material);
                    cout << "\nIngrese el tipo: ";
                    getline(cin, tipo);
                    prendaAgregar = new Accesorios(folio, marca, ocasion, tipo, material);
                    break;
                
                case 1: //Agregar prenda
                    cout << "\nIngrese el corte: ";
                    getline(cin, corte);
                    cout << "\nIngrese el color: ";
                    getline(cin, color);
                    cout << "\nIngrese el tipo: ";
                    getline(cin, tipo);
                    cout << "\nIngrese la tela: ";
                    getline(cin, tela);
                    cout << "\nIngrese la talla: ";
                    getline(cin, talla);
                    cout << "\nIngrese la estacion: ";
                    getline(cin, estacion);
                    cout << "\nIndicar que tipo de prenda es: " << endl;
                    cout << "0: Bottoms.\n1: Tops.\n2: Cuerpo completo.\n3: Calzado. \n4: Deportivo." << endl;
                    cout << "Seleccione la opcion que desea: ";
                    int tipoPrenda;
                    cin >> tipoPrenda;
                    switch (tipoPrenda) //Agregar dependiendo del tipo de prenda
                    {
                    case 0: //Bottoms
                        cin.ignore();
                        cout << "\nIngrese el estampado: ";
                        getline(cin, estampado);
                        cout << "\nIngrese la longitud en cm: ";
                        cin >> longitud;
                        prendaAgregar = new Bottoms(folio, marca, ocasion, corte, color, tipo, tela, talla, estacion, estampado, longitud);
                        break;
                    
                    case 1: //Tops
                        cin.ignore();
                        cout << "\nIngrese el estampado: ";
                        getline(cin, estampado);
                        cout << "\nIngrese la longitud en cm: ";
                        cin >> longitud;
                        prendaAgregar = new Tops(folio, marca, ocasion, corte, color, tipo, tela, talla, estacion, estampado, longitud);
                        break;
                    
                    case 2: //Cuerpo Completo
                        cin.ignore();
                        cout << "\nIngrese el estampado: ";
                        getline(cin, estampado);
                        cout << "\nIngrese la longitud en cm: ";
                        cin >> longitud;
                        prendaAgregar = new CuerpoCompleto(folio, marca, ocasion, corte, color, tipo, tela, talla, estacion, estampado, longitud);
                        break;
                    
                    case 3: //Calzado
                        cin.ignore();
                        cout << "\nIngrese el modelo: ";
                        getline(cin, modelo);
                        prendaAgregar = new Calzado(folio, marca, ocasion, corte, color, tipo, tela, talla, estacion, modelo);
                        break;
                    
                    case 4: //Deportivo
                        cin.ignore();
                        cout << "\nIngrese el deporte: ";
                        getline(cin, deporte);
                        prendaAgregar = new Deportivo(folio, marca, ocasion, corte, color, tipo, tela, talla, estacion, deporte);
                        break;
                    
                    default:
                        cout << "Opción inválida. Intente de nuevo." << endl;
                        break;
                    }
                break;
                default:
                    cout << "Opción inválida. Intente de nuevo." << endl;
                    break;
                }
                //En las siguientes lineas, se elimina el elemento que estaba en la posicion del folio indicado, y se agrega el elemento editado.
                //Existen las validaciones por si el folio esta al inicio, al final, o en cualquier posicion
                if(posicionFolio == 0){
                    mi_lista.pop_f();
                    mi_lista.push_f(prendaAgregar);
                } else if (posicionFolio == mi_lista.tam() - 1){
                    mi_lista.pop_b();
                    mi_lista.push_b(prendaAgregar);
                } else{
                    mi_lista.pop_p(posicionFolio);
                    mi_lista.push_p(prendaAgregar, posicionFolio);
                }
            }
            else {
                cout << "Volviendo al menu..." << endl;
                cout << endl;
            }

        }
        else{
            cout << "\nNo existe dicho folio en el Guardaropa..." << endl;
            cout << "Volviendo al menu..." << endl;
            cout << endl;
        }
    } else{
        cout << "La lista esta vacia." << endl;
    }
}

//Definicion de la funcion buscar
template <typename objeto>
void buscar(lista_d<objeto>& mi_lista){
    //Validacion por si esta vacia la lista
    if(!mi_lista.vacia()){
        cout << endl;
        cout << "\nEste es el apartado para buscar un elemento del Guardaropa." << endl;
        cout << "-------------------------------------------------------------" << endl;
        cout << "Ingresa el numero de folio del articulo a buscar: ";
        int folio;
        cin >> folio;
        //Se utiliza la funcion de busqueda binaria, que busca a traves del guardaropas el folio indicado
        int posicionFolio = recursividadBB(mi_lista, folio, 0, mi_lista.tam()-1);
        if(posicionFolio != -1){
            cout << "La posicion del articulo en el Guardaropa es: " << posicionFolio << endl;
        } else{
            cout << "No existe dicho folio en el Guardaropa..." << endl;
            cout << "Volviendo al menu..." << endl;
        }
    } else{
        cout << "La lista esta vacia." << endl;
    }
}

//definicion de la funcion consultar
template <typename objeto>
void consultar(lista_d<objeto>& mi_lista){
    if(!mi_lista.vacia()){
        cout << endl;
        cout << "\nEste es el apartado para consultar uno o varios elementos del Guardaropa." << endl;
        cout << "---------------------------------------------------------------------------" << endl;
        int cantidad;
        cout << "Indique si desea consultar uno o todos los elementos. " << endl;
        cout << "1: Uno. \n0: Todos." << endl;
        cout << "Seleccione la opcion deseada: ";
        cin >> cantidad;
        if(cantidad == 1){
            cout << "Ingrese el numero de folio del articulo a consultar: ";
            int consultado;
            cin >> consultado;
            int posicionFolio = recursividadBB(mi_lista, consultado, 0, mi_lista.tam()-1);
            //Utiliza el mismo principio empleado en la funcion editar. Busca si el folio existe, y si si, determina que clase pertenece el 
            //elemento para mostrar asi sus atributos
            if(posicionFolio != -1){
                Guardaropa* ejemplo = mi_lista.peek_p(posicionFolio);
                if (Accesorios* accesorios = dynamic_cast<Accesorios*> (ejemplo)) {
                    cout << "\nEl articulo consultado es: " << endl;
                    cout << "Folio: " << accesorios->getFolio() << ". Tipo: " << accesorios-> getTipo() << ". Marca: " << accesorios->getMarca() 
                    << ". Ocasion: " << accesorios->getOcasion() << ". Material: " << accesorios->getMaterial() << endl;
                } else if(Prendas* prendas = dynamic_cast<Prendas*> (ejemplo)){
                    cout << "\nEl articulo consultado es: " << endl;
                    cout << "Folio: " << prendas->getFolio() << ". Tipo: " << prendas-> getTipo() << ". Marca: " << prendas->getMarca() << 
                    ". Ocasion: " << prendas->getOcasion() << ". Talla: " << prendas->getTalla() << ". Color: " << prendas->getColor() 
                    << ". Tela: " << prendas->getTela() << endl;
                }
            } else{
                cout << "No existe dicho folio en el Guardaropa..." << endl;
                cout << "Volviendo al menu..." << endl;
                cout << endl;
            }

        } else if(cantidad == 0){
            //quicksort(mi_lista, 0, mi_lista.tam()-1);
            lista_d<Guardaropa*>::iterador itr = mi_lista.begin();
            Guardaropa* temporal;
            for(int i = 0; i<mi_lista.tam(); i++){
                temporal = *itr;
                if(&itr == nullptr){
                    break;   
                }//Si se desean mostrar todos los elementos entonces lo mismo, se identifica a que clase pertenece el elemento
                if (Accesorios* accesorios = dynamic_cast<Accesorios*> (temporal)) {
                    cout << "\nEl articulo consultado es: " << endl;
                    cout << "Folio: " << accesorios->getFolio() << ". Tipo: " << accesorios-> getTipo() << ". Marca: " << accesorios->getMarca() 
                    << ". Ocasion: " << accesorios->getOcasion() << ". Material: " << accesorios->getMaterial() << endl;
                } else if(Prendas* prendas = dynamic_cast<Prendas*> (temporal)){
                    cout << "\nEl articulo consultado es: " << endl;
                    cout << "Folio: " << prendas->getFolio() << ". Tipo: " << prendas-> getTipo() << ". Marca: " << prendas->getMarca() << 
                    ". Ocasion: " << prendas->getOcasion() << ". Talla: " << prendas->getTalla() << ". Color: " << prendas->getColor() 
                    << ". Tela: " << prendas->getTela() << endl;
                }
                cout << endl;
                itr++;
            }
        } else{
            cout << "Opcion no valida." << endl;
            cout << "Volviendo al menu..." << endl;
        }
    } else {
        cout << "La lista esta vacia." << endl;
    }
}

//Definicion de la funcion de busqueda binaria recursiva
template<typename objeto>
int recursividadBB(lista_d<objeto>& mi_lista, int buscar, int inicio, int fin) {
    if(mi_lista.vacia()){
        cout << "No hay datos en el Guardaropa..." << endl;
        return -1;
    } else{
        //Se llama a quicksort ya que los datos deben estar ordenados para que pueda buscar
        quicksort(mi_lista, 0, mi_lista.tam()-1);
        int mitad;
        //se crea un objeto apuntador de tipo Guardaropa, llamado comparador, que ayuda a que pueda identificar
        //cualquier elemento de la lista, sin importar de que subclase sea
        Guardaropa* comparador;
        mitad = (inicio + fin) / 2;
        //Se busca cual es el elemento que esta en la mitad de la lista
        comparador = mi_lista.peek_p(mitad);
        if (inicio > fin) {
            return -1;
        }
        if (buscar == comparador->getFolio()) {//Si el folio a buscar esta en el elemento de la mitad, retorna ese elemento
            return mitad;
        }
        if (buscar < comparador->getFolio()) { //Si el folio a buscar esta a la izquierda de la mitad, hace recursividad
            return recursividadBB(mi_lista, buscar, inicio, mitad - 1);
        }
        if (buscar > comparador->getFolio()) { //Si el folio a buscar esta a la derecha de la mitad, hace recursividad
            return recursividadBB(mi_lista, buscar, mitad + 1, fin);
        }

        return -1;
    }
}

//Definicion de la funcion Partition. Esta es necesaria para realizar los cambios necesarios en quicksort
//quicksort se realiza tomando en cuenta el folio del elemento
template<typename objeto>
int partition(lista_d<objeto>& mi_lista, int low, int high) {
    int pivot = mi_lista.peek_p(high)->getFolio(); //Se establece como pivote el folio del ultimo elemento
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (mi_lista.peek_p(j)->getFolio() < pivot) { //Si el folio del elemento actual es menor al pivote, se aumenta i y se intercambian
            i++;
            mi_lista.swap(i, j);
        }
    }

    mi_lista.swap( i + 1, high);
    return i + 1;
}

// Función recursiva de Quicksort
template<typename objeto>
void quicksort(lista_d<objeto>& mi_lista, int low, int high) {
    if(mi_lista.vacia()){
        cout << "No hay datos en el Guardaropa..." << endl;
    } else{
        if (low < high) {
            int pivotIndex = partition(mi_lista, low, high);

            quicksort(mi_lista, low, pivotIndex - 1);
            quicksort(mi_lista, pivotIndex + 1, high);
        }
    }
}

//Definicion de la funcion ordenar donde basicamente se usa quicksort
template <typename objeto>
void ordenar(lista_d<objeto>& mi_lista){
    int ordenar;
    cout << endl;
    cout << "\nEste es el apartado para ordenar los elementos del Guardaropa." << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "El ordenado se hara de menor a mayor tomando en cuenta el folio.";
    cout << "Esta segur@ que desea salir?" << endl;
    cout << "0: No, 1: Si: ";
    cin >> ordenar;
    if(ordenar){
        quicksort(mi_lista, 0, mi_lista.tam()-1);
        if(!mi_lista.vacia()){
            cout << "\nOrdenado. Volviendo al menu..." << endl;
        }
    } else {
        cout << "\nNo se ordeno. Volviendo al menu..." << endl;
    }
}
