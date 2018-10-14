#include "../inc/UserManager.h"
#define UsersDirectory "Users\\"

//Constructor
UserManager::UserManager()
{
    //ctor
}

//Destructor
UserManager::~UserManager()
{
    //dtor
}

//Method to create new folder for a new user
bool  UserManager::CreateNewUserFolder()
{
    bool accepted=false;
    std::string path = UsersDirectory+m_pseudo;

    try
    {
        if (CreateDirectory((path).c_str(), NULL))
        {
            accepted=true;
        }
        else if (ERROR_ALREADY_EXISTS == GetLastError())
        {
            accepted=false;
        }
        else throw FolderException(path);
    }
    catch(const FolderException &error)
    {
        std::cerr << error.GetError() <<std::endl;
    }
    return accepted;
}

//Method to verify existence of a user
bool  UserManager::VerifyUserExistance()
{
    bool accepted =false;
    if (GetFileAttributes((UsersDirectory+m_pseudo).c_str()) == INVALID_FILE_ATTRIBUTES)
    {
        accepted =false;
    }
    else
    {
        accepted =true;
    }
    return accepted;
}







