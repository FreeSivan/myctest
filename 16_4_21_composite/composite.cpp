#include "composite.h"


void AComposite::addLeaf(IComposite *leaf) {
    vec_leaf.push_back(leaf);
}

void Composite1::show() {
    cout<<"====Composite1 begin===="<<endl;
    vector<IComposite*>::iterator it = vec_leaf.begin();
    for (; it != vec_leaf.end(); ++it) {
        (*it)->show();
    }
    cout<<"====Composite1 end======"<<endl;   
}

void Composite2::show() {
    cout<<"----Composite2 begin----"<<endl;
    vector<IComposite*>::iterator it = vec_leaf.begin();
    for (; it != vec_leaf.end(); ++it) {
        (*it)->show();
    }
    cout<<"----Composite2 end------"<<endl;
}

void LeafA::show() {
    cout<<"LeafA"<<endl;
}

void LeafB::show() {
    cout<<"leafB"<<endl;
}

void LeafC::show() {
    cout<<"leafC"<<endl;
}

int main() {
    AComposite *com1 = new Composite1();
    AComposite *com2 = new Composite2();
    IComposite *leaf1 = new LeafA();
    IComposite *leaf2 = new LeafB();
    IComposite *leaf3 = new LeafC();
    com1->addLeaf(leaf1);
    com1->addLeaf(leaf2);
    com1->addLeaf(leaf3);
    com1->show();
    cout<<"------------------------"<<endl;
    com2->addLeaf(leaf2);
    com2->addLeaf(com1);
    com2->show();
    return 0;
}
