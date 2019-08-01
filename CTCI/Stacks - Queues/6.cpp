using namespace std;
#include <queue>
class Animal{
    int order;
    string name;
    Animal(string n){name=n;}
    void setOrder(int ord){order=ord;}
    int getOrder(){return order;}

    bool isOlderThan(Animal a){
        return this.order < a.getOrder();
    }
}

class AnimalQueue{
    queue<Animal> dogs; 
    queue<Animal> cats;
    int order = 0;

    //enqueueDog
    void enqueueDog(Animal dog){
        dog.setOrder(order);
        order++;
        dogs.push(dog);
    }

    //enqueueCat
    void enqueueDog(Animal cat){
        cat.setOrder(order);
        order++;
        dogs.pop(cat);
    }

    //dequeueAny
    void dequeueAny(){
        if(dogs.empty()){
            if(cats.empty()) throw new exception;
        }
        if(dogs.front().getOrder()<cats.front().getOrder()) dogs.pop();
        else cats.pop();
    }

    //dequeueDog
    void dequeueDog(){
        if(dogs.empty()) throw new exception;      
        dogs.pop();
    }

    //dequeueCat
    void dequeueCat(){
        if(cats.empty()) throw new exception;
        cats.pop();
    }

}