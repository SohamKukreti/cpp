#include <iostream>
using namespace std;
struct Term {
    int coefficient;
    int exponent;
    Term* next;

    Term(int coeff, int exp) : coefficient(coeff), exponent(exp), next(nullptr) {}
};

class Polynomial {
private:
    Term* head;

public:
    Polynomial() : head(nullptr) {}

    void insertTerm(int coeff, int exp) {
        Term* newTerm = new Term(coeff, exp);
        if (!head || exp > head->exponent) {
            newTerm->next = head;
            head = newTerm;
        } else {
            Term* temp = head;
            while (temp->next && exp <= temp->next->exponent) {
                temp = temp->next;
            }
            newTerm->next = temp->next;
            temp->next = newTerm;
        }
    }

    void display() {
        Term* temp = head;
        while (temp) {
            cout << temp->coefficient << "x^" << temp->exponent;
            if (temp->next) {
                cout << " + ";
            }
            temp = temp->next;
        }
        cout << endl;
    }

    Polynomial multiply(Polynomial& other) {
        Polynomial result;
        Term* term1 = head;

        while (term1) {
            Term* term2 = other.head;
            while (term2) {
                int coeff = term1->coefficient * term2->coefficient;
                int exp = term1->exponent + term2->exponent;
                result.insertTerm(coeff, exp);
                term2 = term2->next;
            }
            term1 = term1->next;
        }

        return result;
    }
};

int main() {
    Polynomial poly1;
    poly1.insertTerm(5, 1);
    poly1.insertTerm(6, 4);
    poly1.insertTerm(1, 0);

    Polynomial poly2;
    poly2.insertTerm(2, 1);
    poly2.insertTerm(3, 0);

    cout << "Polynomial 1: ";
    poly1.display();

    cout << "Polynomial 2: ";
    poly2.display();

    Polynomial product = poly1.multiply(poly2);

    cout << "Product: ";
    product.display();

    return 0;
}