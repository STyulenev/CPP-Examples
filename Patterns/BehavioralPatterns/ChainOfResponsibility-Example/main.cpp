#include <iostream>
#include <vector>

#include "Handlers.h"

/*!
 * \brief Клиентский код, который может обработать любую часть цепочки. Работает с одним обработчиком.
 */
void clientCode(HandlerInterface& handler)
{
    std::vector<std::string> data = { "1", "2", "3" };

    for (const std::string& d : data) {
        std::cout << " --> " << d << std::endl;

        const std::string result = handler.someAction(d);

        if (!result.empty()) {
            std::cout << "  " << result;
        } else {
            std::cout << "  " << d << " was left untouched" << std::endl;
        }
    }
}

int main()
{
    Handler1* first = new Handler1();
    Handler2* second = new Handler2();
    Handler3* third = new Handler3();

    first->next(second)->next(third);

    std::cout << "Chain: first > second > third" << std::endl;
    clientCode(*first);

    std::cout << "\n";

    std::cout << "Subchain: second > third" << std::endl;
    clientCode(*second);

    delete first;
    delete second;
    delete third;

    return 0;
}
