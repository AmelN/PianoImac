#ifndef PIANOMANAGER_H
#define PIANOMANAGER_H
#include "userManager.h"
#include "MusInstrument.h"

class Piano : public MusInstrument
{
public:
    Piano();
    ~Piano();
    void operator<<(char keyPressed);

private:
    int pressDuration=250;
};

#endif // PIANOMANAGER_H
