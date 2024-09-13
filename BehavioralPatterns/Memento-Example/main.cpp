#include <iostream>

#include "Caretaker.h"
#include "Originator.h"

int main()
{
    {
        std::string result = "0";

        Originator* originator = new Originator(result);
        Caretaker* caretaker = new Caretaker(originator);

        result = result + "123";

        caretaker->backup();
        originator->update(result);

        result = result + "4";

        caretaker->backup();
        originator->update(result);

        result = result + "5";

        caretaker->backup();
        originator->update(result);

        caretaker->history();

        std::cout << "Client: undo state" << std::endl;
        caretaker->undo();

        std::cout << "Client: undo state";
        caretaker->undo();

        delete originator;
        delete caretaker;
    }

    return 0;
}
