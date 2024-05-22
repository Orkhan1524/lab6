#include <iostream>
#include <stdexcept>
#include <cmath>
using namespace std;

class PrimeNumber {
private:
    int value;

    // Проверка, является ли число простым
    bool isPrime(int num) const {
        if (num <= 1) return false;
        if (num <= 3) return true;
        if (num % 2 == 0 || num % 3 == 0) return false;
        for (int i = 5; i * i <= num; i += 6) {
            if (num % i == 0 || num % (i + 2) == 0) return false;
        }
        return true;
    }

public:
    // Конструктор
    PrimeNumber(int value) {
        if (!isPrime(value)) {
            throw InvalidPrimeException(value);
        }
        this->value = value;
    }

    // Геттер для значения
    int getValue() const {
        return value;
    }
};

class InvalidPrimeException : public invalid_argument {
private:
    int invalidValue;

public:
    InvalidPrimeException(int value) : invalid_argument("Invalid prime number"), invalidValue(value) {}

    // Метод для печати всех данных
    void printDetails() const {
        cerr << "Invalid prime number: " << invalidValue << endl;
    }
};

int main() {
    try {
        // Создание объекта с простым числом
        PrimeNumber prime(7);
        cout << "Prime number: " << prime.getValue() << endl;

        // Попытка создать объект с непростым числом
        PrimeNumber invalidPrime(4);
        cout << "Prime number: " << invalidPrime.getValue() << endl;
    }
    catch (const InvalidPrimeException& e) {
        // Обработка исключения
        e.printDetails();
    }

    return 0;
}