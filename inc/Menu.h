#ifndef MENU_H
#define MENU_H
#include "Piano.h"

class Menu
{
public:
    Menu();
    ~Menu();

//getters
    unsigned int Getstate() const
    {
        return m_state;
    }
//setters
    void Setstate(const unsigned int val)
    {
        m_state = val;
    }
//methods
    void MainMenu();
    void AddUserMenu();
    void ExistingUserMenu();
    void Tutorial();
    void PrintPiano();

private:
    unsigned int m_state;
    UserManager userM;
    Piano pianoM;
};

#endif // MENU_H
