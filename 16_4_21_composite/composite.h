#ifndef __COMPOSITE__H__
#define __COMPOSITE__H__

#include <iostream>
#include <vector>
using namespace std;

class IComposite {
public:
    virtual void show() = 0;    
};

class AComposite : public IComposite {
public:
    void addLeaf(IComposite *leaf);
protected:
    vector<IComposite*> vec_leaf;
};

class Composite1 : public AComposite {
public:
    virtual void show();
};

class Composite2 : public AComposite {
public:
    virtual void show();
};

class LeafA : public IComposite{
public:
    virtual void show();
};

class LeafB : public IComposite {
public:
    virtual void show();
};

class LeafC : public IComposite {
public:
    virtual void show();
};

#endif

