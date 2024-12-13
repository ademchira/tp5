#include <iostream>
#include <cmath>
using namespace std;

class Vecteur3D {
private:
    float x, y, z;

public:
    Vecteur3D(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z) {}

    void afficher() const {
        cout << "(" << x << ", " << y << ", " << z << ")\n";
    }

    Vecteur3D somme(const Vecteur3D& v) const {
        return Vecteur3D(x + v.x, y + v.y, z + v.z);
    }

    float produitScalaire(const Vecteur3D& v) const {
        return x * v.x + y * v.y + z * v.z;
    }

    bool coince(const Vecteur3D& v) const {
        return x == v.x && y == v.y && z == v.z;
    }

    float norme() const {
        return sqrt(x * x + y * y + z * z);
    }

    static Vecteur3D normax(const Vecteur3D& v1, const Vecteur3D& v2) {
        return (v1.norme() > v2.norme()) ? v1 : v2;
    }

    static Vecteur3D* normax_adresse(const Vecteur3D& v1, const Vecteur3D& v2) {
        return (v1.norme() > v2.norme()) ? const_cast<Vecteur3D*>(&v1) : const_cast<Vecteur3D*>(&v2);
    }

    static Vecteur3D& normax_reference(const Vecteur3D& v1, const Vecteur3D& v2) {
        return (v1.norme() > v2.norme()) ? const_cast<Vecteur3D&>(v1) : const_cast<Vecteur3D&>(v2);
    }
};

int main() {
    Vecteur3D v1(1.0, 2.0, 3.0);
    Vecteur3D v2(4.0, 5.0, 6.0);

    cout << "Vecteur 1: ";
    v1.afficher();

    cout << "Vecteur 2: ";
    v2.afficher();

    Vecteur3D somme = v1.somme(v2);
    cout << "Somme des vecteurs: ";
    somme.afficher();

    float produit = v1.produitScalaire(v2);
    cout << "Produit scalaire: " << produit << "\n";

    bool sontIdentiques = v1.coince(v2);
    cout << "Les vecteurs sont " << (sontIdentiques ? "identiques" : "différents") << "\n";

    cout << "Norme du vecteur 1: " << v1.norme() << "\n";
    cout << "Norme du vecteur 2: " << v2.norme() << "\n";

    Vecteur3D normax = Vecteur3D::normax(v1, v2);
    cout << "Vecteur avec la plus grande norme (par valeur): ";
    normax.afficher();

    Vecteur3D* normax_ptr = Vecteur3D::normax_adresse(v1, v2);
    cout << "Vecteur avec la plus grande norme (par adresse): ";
    normax_ptr->afficher();

    Vecteur3D& normax_ref = Vecteur3D::normax_reference(v1, v2);
    cout << "Vecteur avec la plus grande norme (par référence): ";
    normax_ref.afficher();

    return 0;
}
