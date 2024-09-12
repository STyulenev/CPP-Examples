#include "Observer.h"
#include "Subject.h"

int main()
{
    Subject* subject = new Subject();
    Observer* observer1 = new Observer(*subject);
    Observer* observer2 = new Observer(*subject);
    Observer* observer3 = new Observer(*subject);
    Observer* observer4;
    Observer* observer5;

    subject->createMessage("Hello!");
    observer3->removeMeFromTheList();

    subject->createMessage("How are you?");
    observer4 = new Observer(*subject);

    observer2->removeMeFromTheList();
    observer5 = new Observer(*subject);

    subject->createMessage("What are you doing?");
    observer5->removeMeFromTheList();

    observer4->removeMeFromTheList();
    observer1->removeMeFromTheList();

    delete observer5;
    delete observer4;
    delete observer3;
    delete observer2;
    delete observer1;
    delete subject;

    return 0;
}
