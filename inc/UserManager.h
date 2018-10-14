#ifndef USERMANAGER_H
#define USERMANAGER_H
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include "FolderException.h"

class UserManager
{
public:
    UserManager();
    ~UserManager();

//getters
    std::string Getpseudo() const
    {
        return m_pseudo;
    }
//setters
    void Setpseudo(const std::string val)
    {
        m_pseudo = val;
    }
//methods
    bool CreateNewUserFolder();
    bool VerifyUserExistance();

private:
    std::string m_pseudo;

};

/*
class UserManager
{
public:
        UserManager() { m_instance = this; }
        createNewUser(pseudo);
        verifyUser(pseudo);
        UserManager& instance();
        private:
        static UserManager* m_instance;
}
*/

//userManager::instance().createNewUser(pseudo)

#endif // USERMANAGER_H
