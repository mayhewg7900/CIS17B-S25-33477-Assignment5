#include "Templates.h"


int main() {
    // Instancing package of type int
    Package<int> firstPackage(2);
    firstPackage.label();
    
    // Instancing package of type string
    Package<std::string> secondPackage("Test");
    secondPackage.label();

    // Instancing package of type double pointer
    double testDouble = 384.2938;
    Package<double*> thirdPackage(&testDouble);
    thirdPackage.label();

    // Instancing box, using type string and a size of 3
    Box<std::string, 3> box;
    box.addItem("Book1");
    box.addItem("Book2");
    box.addItem("Book3");
    box.printItems();

    shipItem(12);
    
}