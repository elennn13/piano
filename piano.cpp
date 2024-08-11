#include <iostream>
#include <conio.h> // Для _getch()
#include <windows.h> // Для Beep()

// Функция для отображения пианино
void displayPiano() {
    std::cout << "   | Z | X | C | V | B | N | M |\n";
    std::cout << "   |   |   |   |   |   |   |   |\n";
    std::cout << "   |---|---|---|---|---|---|---|\n";
    std::cout << "     C   D   E   F   G   A   B\n\n";
}

// Функция для отображения нажатой клавиши
void pressKey(char key) {
    std::cout << "   ";
    for (char c = 'Z'; c <= 'M'; ++c) {
        if (c == key) {
            std::cout << "| # ";
        }
        else {
            std::cout << "|   ";
        }
    }
    std::cout << "|\n";

    std::cout << "   |---|---|---|---|---|---|---|\n";
    std::cout << "     C   D   E   F   G   A   B\n\n";
}

// Функция для воспроизведения звука на основе нажатой клавиши
// Находит соответствующую частоту для каждой клавиши(ноты) и использует
// функцию Beep() для воспроизведения звука.
// Beep() принимает частоту в герцах и длительность в миллисекундах.
void playSound(char key) {
    int frequency = 0;
    switch (key) {
    case 'Z': frequency = 262; break; // C
    case 'X': frequency = 294; break; // D
    case 'C': frequency = 330; break; // E
    case 'V': frequency = 349; break; // F
    case 'B': frequency = 392; break; // G
    case 'N': frequency = 440; break; // A
    case 'M': frequency = 494; break; // B
    default: return;
    }

    Beep(frequency, 500); // Воспроизводим звук с заданной частотой и длительностью
}

int main() {
    char key;
    displayPiano(); // Показываем начальное пианино

    while (true) {
        key = _getch(); // Ожидаем нажатия клавиши

        // Очистка экрана (имитация)
        system("cls");

        displayPiano(); // Отображаем пианино снова
        pressKey(key);  // Отображаем нажатую клавишу
        playSound(key); // Воспроизводим звук
    }

    return 0;
}