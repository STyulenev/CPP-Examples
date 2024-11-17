#pragma once

#include "IObserver.h"
#include "Subject.h"

/*!
 * \brief Kласс-наблюдатель
 */
class Observer : public IObserver
{
public:
    Observer(Subject& subject);
    virtual ~Observer();

    void update(const std::string& messageFromSubject) override;
    void removeMeFromTheList();
    void printInfo();

private:
    std::string messageFromSubject_;
    Subject& subject_;
    static int staticNumber_;
    int number_;

};
