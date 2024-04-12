#include <iostream>

using namespace std;

template<typename T>
struct Nodo {
    T data;
    Nodo* next;
};

template<typename T>
class List {
private:
    Nodo<T>* head;
public:
    List();
    T front();
    T back();
    void push_front(T dt);
    void push_back(T dt);
    T pop_front();
    T pop_back();
    T operator[](int i);
    bool empty();
    int size();
    void clear();
    void sort();
    void reverse();
    void print();
    ~List();
};

template<typename T>
List<T>::List() {
    head = NULL;
}

template<typename T>
T List<T>::front() {
    if(empty()) {
        throw logic_error("Lista vacia");
    }
    return head->data;
}

template<typename T>
T List<T>::back() {
    if(empty()) {
        throw logic_error("Lista vacia");
    }
    Nodo<T>* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    return temp->data;
}

template<typename T>
void List<T>::push_front(T dt) {
    Nodo<T>* nuevoNodo = new Nodo<T>;
    nuevoNodo->data = dt;
    nuevoNodo->next = head;
    head = nuevoNodo;
}

template<typename T>
void List<T>::push_back(T dt) {
    Nodo<T>* nuevoNodo = new Nodo<T>;
    Nodo<T>* temp = head;
    nuevoNodo->data = dt;
    nuevoNodo->next = NULL;
    if (head == NULL) {
        head = nuevoNodo;
    }
    else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = nuevoNodo;
    }
}

template<typename T>
T List<T>::pop_front() {
    if(empty()) {
        throw logic_error("Lista vacia");
    }
    Nodo<T>* temp = head;
    T data = head->data;
    head = head->next;
    delete temp;
    return data;
}

template<typename T>
T List<T>::pop_back() {
    if(empty()) {
        throw logic_error("Lista vacia");
    }
    if (head->next == NULL) {
        T data = head->data;
        delete head;
        head = NULL;
        return data;
    }
    else {
        Nodo<T>* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;}
        T data = temp->next->data;
        delete temp->next;
        temp->next = NULL;
        return data;
    }
}

template<typename T>
T List<T>::operator[](int i) {
    if (empty()) {
        throw logic_error("Lista vacia");
    }
    Nodo<T>* temp = head;
    int index = 0;
    while (temp != NULL) {
        if (index == i) {
            return temp->data;
        }
        temp = temp->next;
        index++;
    }
    throw out_of_range("Índice fuera de rango");
}

template<typename T>
bool List<T>::empty() {
    return head == NULL;
}

template<typename T>
int List<T>::size() {
    int i = 0;
    Nodo<T>* temp = head;
    while (temp != NULL) {
        i++;
        temp = temp->next;
    }
    return i;
}

template<typename T>
void List<T>::clear() {
    while (head != NULL) {
        Nodo<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

template<typename T>
void List<T>::sort() {
    if(empty()) {
        throw logic_error("Lista vacia");
    }
    Nodo<T>* temp = head;
    while (temp != NULL) {
        Nodo<T>* temp2 = temp->next;
        while (temp2 != NULL) {
            if (temp->data > temp2->data) {
                T aux = temp->data;
                temp->data = temp2->data;
                temp2->data = aux;
            }
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
}

template<typename T>
void List<T>::reverse() {
    if(empty()) {
        throw logic_error("Lista vacia");
    }
    Nodo<T>* anterior = NULL;
    Nodo<T>* actual = head;
    Nodo<T>* siguiente = NULL;
    while (actual != NULL) {
        siguiente = actual->next;
        actual->next = anterior;
        anterior = actual;
        actual = siguiente;
    }
    head = anterior;
}

template<typename T>
List<T>::~List() {
    clear();
}

template<typename T>
void List<T>::print() {
    if(empty()) {
        cout << "Lista vacia" << endl;
        return;
    }
    Nodo<T>* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {

    // Ejemplo de uso de las funciones de la clase List
    List<int> intList;
    intList.push_back(1);
    intList.push_back(2);
    intList.push_back(3);
    intList.push_back(4);

    cout << "Lista de enteros: ";
    intList.print();
    intList.clear();
    cout << endl;

    // Prueba de excepciones cuando la lista se encuentra vacía
    try{
        intList.pop_front();
        intList.pop_back();

    }
    catch(const logic_error& e) {
        cout << "Lista vacia" << endl;
    }
    cout << endl;


}