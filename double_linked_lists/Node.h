

template <typename T>
class List;

template <typename T>
class Node {
private:
    T info;
    Node<T>* next;
    Node<T>* prev;
public:
    Node(T info, Node<T>* next, Node<T>* previous) : info(info), next(next), prev(prev){}
    Node(T info) : info(info){ next= nullptr, prev = nullptr;}
    friend class List<T>;
};
