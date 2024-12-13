#include <iostream>
#include <cmath>
using namespace std;

class Complexe {
private:
    double Re, Img;

public:
    Complexe(double r = 0.0, double i = 0.0) : Re(r), Img(i) {}

    void afficher() const {
        cout << Re << " + " << Img << "i" << endl;
    }

    double module() const {
        return sqrt(Re * Re + Img * Img);
    }

    Complexe conjugue() const {
        return Complexe(Re, -Img);
    }

    Complexe operator+(const Complexe& c) const {
        return Complexe(Re + c.Re, Img + c.Img);
    }

    Complexe operator+(double val) const {
        return Complexe(Re + val, Img);
    }

    Complexe operator-(const Complexe& c) const {
        return Complexe(Re - c.Re, Img - c.Img);
    }

    Complexe operator*(const Complexe& c) const {
        return Complexe(Re * c.Re - Img * c.Img, Re * c.Img + Img * c.Re);
    }

    Complexe operator*(double val) const {
        return Complexe(Re * val, Img * val);
    }

    friend Complexe operator+(double val, const Complexe& c) {
        return Complexe(c.Re + val, c.Img);
    }

    friend Complexe operator*(double val, const Complexe& c) {
        return Complexe(c.Re * val, c.Img * val);
    }
};

int main() {
    Complexe c1(3, 4), c2(1, 2);

    cout << "Premier nombre complexe: ";
    c1.afficher();

    cout << "Deuxieme nombre complexe: ";
    c2.afficher();

    Complexe sum = c1 + c2;
    cout << "Somme des deux complexes: ";
    sum.afficher();

    Complexe diff = c1 - c2;
    cout << "Difference des deux complexes: ";
    diff.afficher();

    Complexe product = c1 * c2;
    cout << "Produit des deux complexes: ";
    product.afficher();

    cout << "Module de c1: " << c1.module() << endl;
    cout << "Conjugue de c1: ";
    c1.conjugue().afficher();

    double val = 2.0;
    Complexe sumWithDouble = c1 + val;
    cout << "Somme de c1 et " << val << ": ";
    sumWithDouble.afficher();

    Complexe productWithDouble = val * c1;
    cout << "Produit de " << val << " et c1: ";
    productWithDouble.afficher();

    return 0;
}
