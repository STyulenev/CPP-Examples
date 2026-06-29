#include <iostream>
#include <vector>
#include <random>

/*
 * Пользовательский литерал — это механизм в языке C++, который позволяет создавать собственные расширения для синтаксиса литералов,
 * чтобы сделать код более читаемым и удобным для конкретных задач.
 * Пример:
 * - 42                   // целочисленный литерал
 * - 3.14                 // числовой литерал с плавающей точкой
 * - "Hello"              // строковый литерал
 * - auto length = 5.0_m; // _m — пользовательский суффикс
 *
 */

// Пользовательский литерал для превращения строк в цвет
struct Color
{
    int r;
    int g;
    int b;
};

Color operator"" _color(const char* str, size_t len)
{
    unsigned int r, g, b;
    sscanf(str, "#%02x%02x%02x", &r, &g, &b);
    return { static_cast<int>(r), static_cast<int>(g), static_cast<int>(b) };
}

// Пользовательский литерал для перевода минут в секунды
unsigned long long operator "" _min(unsigned long long minutes)
{
    return minutes * 60;
}

// Пользовательский литерал для возведения в квадрат
auto operator "" _sq(unsigned long long int value)
{
    return value * value;
}

// Пользовательский литерал для создания строковых представлений байтов
std::string operator"" _bytes(const char* str, size_t len)
{
    std::string result;
    for (size_t i = 0; i < len; ++i) {
        result += "\\x";
        char buf[3];
        sprintf(buf, "%02X", static_cast<unsigned char>(str[i]));
        result += buf;
    }
    return result;
}

// Пользовательский литерал для преобразования секунд в миллисекунды
constexpr long long operator"" _ms(unsigned long long sec)
{
    return sec * 1000; // преобразование секунд в миллисекунды
}

// Пользовательский литерал для генерации массива случайных чисел
std::vector<int> operator"" _rand(unsigned long long count)
{
    std::vector<int> vec;
    std::mt19937 gen{std::random_device{}()};
    std::uniform_int_distribution<> dist(0, 100);
    for (unsigned long long i = 0; i < count; ++i) {
        vec.push_back(dist(gen));
    }
    return vec;
}

int main()
{
    {
        Color red = "#FF0000"_color;
        std::cout << "Color: R=" << red.r << " G=" << red.g << " B=" << red.b << std::endl;
    }

    {
        std::cout << "5 * 5 = " << 5_sq << std::endl; // на экран выведится 300
    }

    {
        std::cout << 5_min << std::endl; // на экран выведится 300
    }

    {
        auto data = "Hello"_bytes;
        std::cout << "Bytes: " << data << std::endl; // Выведет: \x48\x65\x6C\x6C\x6F
    }

    {
        auto duration_ms = 5_ms; // миллисекунды
        std::cout << "Duration: " << duration_ms << " ms" << std::endl;
    }

    {
        auto random_numbers = 10_rand; // Массив из 10 случайных чисел
        std::cout << "Random numbers: ";
        for (auto num : random_numbers)
        {
            std::cout << num << ' ';
        }
        std::cout << std::endl;
    }

    return 0;
}
