#include <iostream>
#include <cstdarg>

/*
 * Элли́псис обозначается тремя точками (...), и применяется в традиционном стиле программирования на C/C++ для объявления функции,
 * способной принимать переменное количество аргументов неопределённого типа. Обычно используется совместно с библиотечными средствами
 * из <cstdarg>. Эта техника позволяет объявлять функции, способные обрабатывать любое количество аргументов разных типов, однако такая
 * возможность сильно ограничивает возможности проверки типов на этапе компиляции.
 *
 * Недостатки эллипсиса:
 * - Нет контроля типов на этапе компиляции, что потенциально ведёт к ошибкам во время исполнения программы.
 * - Не поддерживается перегрузка функций (например, нельзя сделать две функции с одинаковым именем, принимающие разное количество аргументов).
 * - Сложность сопровождения и расширения функционала программы.
 *
 */

double average(int num_args, ...)
{
    va_list args;
    va_start(args, num_args);
    double sum = 0.0;

    for (int i = 0; i < num_args; ++i) {
        sum += va_arg(args, double); // Получаем значение следующего аргумента
    }
    va_end(args);

    return sum / num_args;
}

void log(const char* format, ...)
{
    va_list args;
    va_start(args, format);

    std::cout << "log: ";

    while (*format != '\0') {
        if (*format == '%') {
            switch (*(++format)) {
            case 'd':
                std::cout << va_arg(args, int);
                break;
            case 'f':
                std::cout << va_arg(args, double);
                break;
            default:
                std::cerr << "Error symbol\n";
                break;
            }
        } else {
            std::cout << *format;
        }

        ++format;
    }

    va_end(args);

    std::cout << std::endl;
}

int main()
{
    std::cout << "average = " << average(5, 1.1, 1.2, 1.3, 1.44, 1.58) << std::endl;

    log("id = %d, value = %f", 17, 8.5);

    return 0;
}
