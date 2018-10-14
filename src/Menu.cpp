#include "../inc/Menu.h"
#define Exit 0
#define NewUser 1
#define ExistingUser 2
#define TutorialMenu 3
#define BackToMM 1

//Destructor
Menu::Menu()
{

}

//Destructor
Menu::~Menu()
{
    //dtor
}

//method for the main menu
void Menu::MainMenu()
{
    int option;
    std::cout<<"\n\t **** HELLO AND WELCOME TO PPPPPIANO IMAC ****";
    std::cout<<"\n\n\n\t\t\tMAIN MENU\n\t\t=====================\n\t\t[1] New user\n\t\t[2] I am already a user\n\t\t[3] Tutorial\n\t\t[4] Exit\n\t\t=====================\n\t\t";
    std::cout<<"Enter the choice:";
    std::cin>>option;

    switch(option)
    {
    case Exit:
        std::cout<<"Goodbye !";
        exit (0);
        break;
    case NewUser:
        AddUserMenu();
        break;
    case ExistingUser:
        ExistingUserMenu();
        break;
    case TutorialMenu:
        Tutorial();
        break;
    default:
        break;
    }
}

//method for adding a new user menu
void Menu::AddUserMenu()
{
    system("cls");
    bool accepted=false;
    std::string pseudo;
    std::cout << "\n\n\n \t\t Hola my new friend ! Let's choose a pseudo ! \n" << std::endl;
    do
    {
        std::cin >> pseudo;
        userM.Setpseudo(pseudo);
        accepted=userM.CreateNewUserFolder();
        if(accepted==false)
        {
            std::cout<<"Pseudo already exists ! try another one: \n";
        }
        else
            std::cout << "You've been successfully registered !" << std::endl;
        pianoM.Setpseudo(pseudo);
    }
    while (accepted == false);
    PrintPiano();
    pianoM.MainLoop();
}
//method for an existing user menu
void Menu::ExistingUserMenu()
{
    system("cls");
    bool accepted =false;
    std::string pseudo;
    std::cout << "\n\n\n \t\t welcome back my friend ! what's your pseudo? \n" << std::endl;
    do
    {
        std::cin >> pseudo;
        userM.Setpseudo(pseudo);
        accepted=userM.VerifyUserExistance();
        if(accepted==false)
        {
            std::cout<<"Sorry no such pseudo exist ! \n type again : \n ";
        }
        pianoM.Setpseudo(pseudo);
    }
    while (accepted ==false );
    PrintPiano();
    pianoM.MainLoop();
}

//method for tutorial menu
void Menu:: Tutorial()
{
    system("cls");
    int option;
    std::cout<<"\n\n\n\t\t\tTUTORIAL\n\t\t====================\n\t\t Once you type your pseudo, the piano interface will show up \n\t\t with indication of the different notes on the keyboard.  ";
    std::cout<<"\n\t\t Also you can press + or - to go an octave up or down.\n\t\t You can press 5 to start record mode and press 5 again to \n\t\t stop record.\n\t\t Press 9 to change Press duration. \n\t\t";
    std::cout<<" Press 8 to load a song and finally 0 to exit \n\t\t=====================\n\t\t";
    std::cout<<"\n\n\n..::Enter the Choice:\n\n\t[" <<BackToMM << "] Main Menu\t\t["<<Exit <<"] Exit\n";
    std::cin>>option;
    switch(option)
    {
    case Exit:
        std::cout<<"Goodbye !";
        exit (0);
        break;
    case BackToMM:
        system("cls");
        MainMenu();
        break;
    }
}

//method to print piano play interface
void Menu:: PrintPiano()
{
    system("cls");
    std::cout<<"\n";
    std::cout<<"|   | |  | |   |   | |  | |  | |   |    |      PRESS 9 TO CHANGE PRESS DURATION"<<std::endl;
    std::cout<<"|   | |  | |   |   | |  | |  | |   |    |      PRESS 5 TO START/STOP SAVE MODE."<<std::endl;
    std::cout<<"|   |e|  |r|   |   |y|  |u|  |i|   |    |      PRESS 8 FOR LOAD MODE."<<std::endl;
    std::cout<<"|   |_|  |_|   |   |_|  |_|  |_|   |    |      PRESS + TO GO AN OCTAVE UP."<<std::endl;
    std::cout<<"| s  | d  | f  | g  | h  | j  | k  | l  |      PRESS - TO GO AN OCTAVE DOWN."<<std::endl;
    std::cout<<"|____|____|____|____|____|____|____|____|      PRESS 0 TO EXIT."<<std::endl;
}

