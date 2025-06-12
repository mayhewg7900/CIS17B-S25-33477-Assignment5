#include <iostream>
#include <string>
#include <array>
#include <typeinfo>


// Specialization for type T, reference to item
template<typename T>
class Package {
private:
    T item;
public:
    // Package constructor, and label method
    Package(T i) : item(i) {}
    
    // Label method, displaying the package contents
    void label() {
        std::cout << "Generic package containing: " << typeid(T).name() << "\n";
    }
};

// Specialization for std::string
template<>
class Package<std::string> {
private:
    std::string item;
public:
    Package(std::string i) : item(i) {}
    void label() {
        std::cout << "Book package: \"" << item << "\"\n";
    }
};

// Partial specialization for pointers
template<typename T>
class Package<T*> {
private:
    T* item;
public:
    Package(T* i) : item(i) {}
    void label() {
        std::cout << "Fragile package for pointer to type: " << typeid(T).name() << "\n";
    }
};

// Specialization for int
template<>
class Package<int> {
private:
    int item;
public:
    Package(int i) : item(i) {}
    void label() {
        std::cout << "Integer package " << item << "\n";
    }
};

// Specialization for Box class, having a private array and count of array size
template<typename T, int Size>
class Box {
private:
    std::array<T, Size> items;
    int count = 0;
public:
    // Function declaration for adding item to Box class
    bool addItem(const T& item) {
        // If count does has not met the desired size...
        if (count < Size) {
            // Adding item to the array and returning successful addition
            items[count++] = item;
            std::cout << "Added item to box: \"" << item << "\"\n";
            return true;
        }
        // Otherwise, return unsuccessful item addition
        return false;
    }

    // Displaying the items of the box
    void printItems() const {
        std::cout << "Box contents:\n";
        for (int i = 0; i < count; ++i) {
            std::cout << " - " << items[i] << "\n";
        }
    }
};

// shipItem specialization for item in Package class
template<typename T>
void shipItem(const T& item) {
    std::cout << "Shipping item of type: " << typeid(T).name() << "\n";
}

template<>
void shipItem(const std::string& item) {
    std::cout << "Shipping item of type: " << typeid(std::string).name() << "\n";
}

//  shipItem specialization for type double
template<>
void shipItem(const double& item) {
    std::cout << "Shipping item of type: " << typeid(double&).name() << "\n";
    std::cout << "Shipping temperature-controlled item: " << item << "C\n";
}

// shipItem specialization for type integer
template<>
void shipItem<int>(const int& item) {
    std::cout << "Shipping item of type: " << typeid(int&).name() << "\n";
    std::cout << "Shipping temperature-controlled item: " << item << " C\n";
}