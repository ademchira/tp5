#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Point {
private:
    double x, y;

public:
    Point(double x = 0, double y = 0) : x(x), y(y) {}

    double getX() const { return x; }
    double getY() const { return y; }

    void setX(double newX) { x = newX; }
    void setY(double newY) { y = newY; }

    void deplacer(double dx, double dy) {
        x += dx;
        y += dy;
    }

    void afficher() const {
        cout << "(" << x << ", " << y << ")";
    }
};

class Cercle {
private:
    double rayon;
    Point centre;

public:
    Cercle(double rayon, const Point& centre) : rayon(rayon), centre(centre) {}

    Cercle(double rayon, double x, double y) : rayon(rayon), centre(x, y) {}

    double getRayon() const { return rayon; }
    Point getCentre() const { return centre; }

    void setRayon(double newRayon) { rayon = newRayon; }

    void deplacerCentre(double dx, double dy) {
        centre.deplacer(dx, dy);
    }

    double calculerSurface() const {
        return M_PI * rayon * rayon;
    }

    double calculerPerimetre() const {
        return 2 * M_PI * rayon;
    }

    bool estEgal(const Cercle& autre) const {
        return rayon == autre.rayon && centre.getX() == autre.centre.getX() && centre.getY() == autre.centre.getY();
    }

    bool contientPoint(const Point& p) const {
        double distance = sqrt(pow(centre.getX() - p.getX(), 2) + pow(centre.getY() - p.getY(), 2));
        return distance <= rayon;
    }

    void afficher() const {
        cout << "Cercle: Centre=";
        centre.afficher();
        cout << ", Rayon=" << rayon << endl;
    }
};

int main() {
    Cercle c1(1, 10, 10);
    cout << "Cercle initial: \n";
    c1.afficher();

    cout << "Perimetre: " << c1.calculerPerimetre() << endl;
    cout << "Surface: " << c1.calculerSurface() << endl;

    c1.setRayon(c1.getRayon() * 2);
    cout << "Apres doublement du rayon: \n";
    c1.afficher();
    cout << "Perimetre: " << c1.calculerPerimetre() << endl;
    cout << "Surface: " << c1.calculerSurface() << endl;

    c1.deplacerCentre(-10, -10);
    cout << "Apres deplacement au centre: \n";
    c1.afficher();

    Point p1(1, 1);
    Point p2(3, 3);

    cout << "Le point (1, 1) est "
         << (c1.contientPoint(p1) ? "a l'interieur" : "à l'exterieur") << " du cercle." << endl;
    cout << "Le point (3, 3) est "
         << (c1.contientPoint(p2) ? "a l'interieur" : "à l'exterieur") << " du cercle." << endl;

    Cercle c2(2, 0, 0);
    cout << "Le cercle est " << (c1.estEgal(c2) ? "egal" : "different") << " au cercle (0, 0, 2)." << endl;

    return 0;
}
