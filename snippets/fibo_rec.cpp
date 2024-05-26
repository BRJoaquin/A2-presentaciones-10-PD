#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Función recursiva para calcular Fibonacci
long fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    int N;
    cout << "Ingrese el valor de N para calcular Fibonacci(N): ";
    cin >> N;

    // Iniciamos el temporizador
    auto start = high_resolution_clock::now();

    // Calculamos el número de Fibonacci
    long resultado = fibonacci(N);

    // Detenemos el temporizador
    auto stop = high_resolution_clock::now();

    // Calculamos la duración
    auto duration = duration_cast<seconds>(stop - start);

    cout << "Fibonacci(" << N << ") = " << resultado << endl;
    cout << "Tiempo de ejecución: " << duration.count() << " segundos." << endl;

    return 0;
}
