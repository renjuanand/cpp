//  Abstract Factory - defines an abstract class for creating
//  families of objects but without specifying their concrete sub-classes

#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Widget {
public:
    virtual void draw() = 0;    //  pure virtual function
};

//  concrete class

class LinuxButton : public Widget {
public:
    void draw() {
        cout << "LinuxButton" << endl;
    }
};

class LinuxMenu : public Widget {
public:
    void draw() {
        cout << "LinuxMenu" << endl;
    }
};

class WindowsButton : public Widget {
public:
    void draw() {
        cout << "Windows Button" << endl;
    }
};

class WindowsMenu : public Widget {
public:
    void draw() {
        cout << "Windows Menu" << endl;
    }
};


class Factory {
public:
    virtual Widget* createButton() = 0;
    virtual Widget* createMenu() = 0;
};

class LinuxFactory : public Factory {
public:
    Widget* createButton() {
        return new LinuxButton;
    }
    Widget* createMenu() {
        return new LinuxMenu;
    }
};

class WindowsFactory : public Factory {
public:
    Widget* createButton() {
        return new WindowsButton;
    }
    Widget* createMenu() {
        return new WindowsMenu;
    }
};


class Client {
    unique_ptr<Factory> factory;
public:
    Client(unique_ptr<Factory> f) : factory(std::move(f)){ }
    void draw() {
        Widget* w = factory->createButton();
        w->draw();
        displayWindowOne();
        displayWindowOne();
    }

    void displayWindowOne() {
        Widget* w[] = {
            factory->createButton(), factory->createMenu()
        };

        w[0]->draw(); w[1]->draw();
    }

    void displayWindowTwo() {
        Widget* w[] = {
            factory->createButton(), factory->createMenu()
        };

        w[0]->draw(); w[1]->draw();
    }
};

int main(int argc, char *argv[])
{
    unique_ptr<Factory> factory(new LinuxFactory);
    unique_ptr<Client> c(new Client(std::move(factory)));
    c->draw();

    return 0;
}
