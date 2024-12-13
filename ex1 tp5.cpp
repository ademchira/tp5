#include <iostream>
#include <string>
using namespace std;

class Etudiant {
private:
    static int compteurMatricule;
    int matricule;
    string nom;
    int nbrNotes;
    float* tabNotes;

public:
    Etudiant() : matricule(++compteurMatricule), nom(""), nbrNotes(0), tabNotes(nullptr) {}
    Etudiant(string nom, int nbrNotes) : matricule(++compteurMatricule), nom(nom), nbrNotes(nbrNotes) {
        tabNotes = new float[nbrNotes];
    }
    ~Etudiant() {
        delete[] tabNotes;
    }
    Etudiant(const Etudiant &e) : matricule(++compteurMatricule), nom(e.nom), nbrNotes(e.nbrNotes) {
        tabNotes = new float[nbrNotes];
        for (int i = 0; i < nbrNotes; i++) {
            tabNotes[i] = e.tabNotes[i];
        }
    }

    int getMatricule() const { return matricule; }
    void setNom(const string& nom) { this->nom = nom; }
    string getNom() const { return nom; }

    void setNbrNotes(int nbr) {
        nbrNotes = nbr;
        delete[] tabNotes;
        tabNotes = new float[nbrNotes];
    }

    int getNbrNotes() const { return nbrNotes; }

    void saisie() {
        cout << "Saisie des notes pour " << nom << " (" << matricule << "):\n";
        for (int i = 0; i < nbrNotes; i++) {
            cout << "Note " << i + 1 << ": ";
            cin >> tabNotes[i];
        }
    }

    void affichage() const {
        cout << "Matricule: " << matricule << ", Nom: " << nom << "\nNotes: ";
        for (int i = 0; i < nbrNotes; i++) {
            cout << tabNotes[i] << " ";
        }
        cout << "\n";
    }

    float moyenne() const {
        float somme = 0;
        for (int i = 0; i < nbrNotes; i++) {
            somme += tabNotes[i];
        }
        return somme / nbrNotes;
    }

    bool admis() const {
        return moyenne() >= 10;
    }

    static bool comparer(const Etudiant &e1, const Etudiant &e2) {
        return e1.moyenne() == e2.moyenne();
    }
};

int Etudiant::compteurMatricule = 0;

int main() {
    Etudiant e1("Alice", 3);
    e1.saisie();

    Etudiant e2("Bob", 4);
    e2.saisie();

    e1.affichage();
    e2.affichage();

    if (Etudiant::comparer(e1, e2)) {
        cout << "Les deux étudiants ont la même moyenne.\n";
    } else {
        cout << "Les deux étudiants n'ont pas la même moyenne.\n";
    }

    cout << "Alice est " << (e1.admis() ? "admis" : "non admis") << ".\n";
    cout << "Bob est " << (e2.admis() ? "admis" : "non admis") << ".\n";

    return 0;
}
