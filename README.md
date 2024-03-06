# Taller Bonus - LinkedLists

En programación, existe el concepto de LinkedList. Una lista enlazada es un tipo de lista que no se basa en arrays, sino en nodos; cada nodo consta de dos campos: uno tiene datos y, en el segundo campo, el nodo tiene una dirección que mantiene una referencia al siguiente nodo. En algunos casos, como en este taller, el nodo puede contener una variable que guarda la dirección del nodo anterior. 

![alt text](<./readme-assets/UML Diagram - LinkedList 1.jpg>)

La representación en c++ sería de la siguiente manera:

```cpp
    template <typename T>
    struct Node {
        T value;
        Node<T>* next;
        Node<T>* previous;
    };  
```

En este caso definimos un template, ya que el valor del nodo puede ser cualquier cosa.

Con estos nodos es posible formar listas (LinkedList), para hacerlo es necesario definir dentro de una estructura dos valores:
1. Un apuntador hacia el primer nodo de la lista, definido como `head`. 
2. El tamaño actual de la lista (`size`)

![Imagen 2](<./readme-assets/UML Diagram - LinkedList 2.jpg>)

Como puede observar, la dirección `previous` del primer elemento apunta a la dirección `nullptr` y la dirección `next` del elemento del final también apunta a `nullptr`.

En c++ una LinkedList; sin los métodos para agregar, eliminar y demás; se definiría de la siguiente forma:
```cpp
    template <typename T>
    struct LinkedList {
        
        Node<T>* head;
        int size;

        LinkedList() {
            head = nullptr;
            size = 0;
        }
    };
```
En el caso de este tipo de listas, el recorrido por las mismas se debe realizar a través del valor inicial que contiene el apuntador `Head`, hasta que se encuentre el valor buscado, o hasta que el valor `next` del último nodo sea encontrado:

Con esto en cuenta, si quisieramos obtener el último nodo, deberíamos hacer la siguiente operación: 

```cpp
Node<T>* getLastNode() {
    
    //Dirección del primer nodo
    Node<T>* currentNode = head;

    //El nodo inicialmente podría estar vacío
    if (currentNode == nullptr) {
        return nullptr;
    }

    //si hay elementos en la lista, 
    // recorremos mientras exista un elemento más 
    //y se asigna a la variable `currentNode`
    while (currentNode->next != nullptr) {
        currentNode = currentNode->next;
    }

    return currentNode;
}
```
Por otro lado, si se quiere obtener un valor de una posición en particular, se debe controlar que al momento de recorrer la lista el valor del indice no esté fuera de los valores permitidos (entre 0 y el tamaño de la lista). Luego, se recorre a través del apuntador `next`:

```cpp
Node<T>* getNode(int index) {
        
    if (index < 0 || index >= size) {
            return nullptr;
        }

    Node<T>* currentNode = head;
    int currentIndex = 0;
    
    while (currentIndex < index) {
        currentNode = currentNode->next;
        currentIndex++;
    }

    return currentNode;
}

T get(int index) {
        
    Node<T>* searchNode = getNode(index);
    
    if (searchNode == nullptr) {
        return NULL;
    }
    
    //Se retorna value, no el nodo completo
    return searchNode->value;
        
}
```
Si desea información más detallada sobre este proceso, puede encontrarla en el siguiente [enlace a miro](https://miro.com/app/board/uXjVMYC93wc=/?moveToWidget=3458764580148903856&cot=14).

Cómo puede imaginar, estás listas tienen operaciones para agregar elementos ([add](https://github.com/clase-programacion-avanzada/CPP-Workshop-Bonus/blob/main/libs/LinkedList.h#L38)), eliminar ([remove](https://github.com/clase-programacion-avanzada/CPP-Workshop-Bonus/blob/main/libs/LinkedList.h#L47)) y reiniciar la lista ([clear](https://github.com/clase-programacion-avanzada/CPP-Workshop-Bonus/blob/main/libs/LinkedList.h#L137)). Su tarea es completar estos tres métodos. Solo hay que hacerlo en la estructura LinkedList.h.

Si usted ejecuta el código del archivo Taller7.cpp este mostrará si el código implementado funciona o no. 

**Por cada método que implemente con éxito recibirá 0.15 puntos adicionales en el parcial.**

**Este taller debe estar finalizado antes del exámen y debe haber entregado los anteriores para que sea tomado como válido.**

Recuerde que hay una explicación sobre cómo funciona cada uno de estos métodos en el [enlace de miro](https://miro.com/app/board/uXjVMYC93wc=/?moveToWidget=3458764580148903857&cot=14).
