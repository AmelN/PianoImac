#include "../inc/Piano.h"

//Constructor
Piano::Piano()
{

}

//Destructor
Piano::~Piano()
{
    //dtor
}

//method to play different sounds for different notes according to pressed key
void Piano::operator<<(char keyPressed) //overload of the operator <<
{

    switch(keyPressed)
    {
    case 's' :
        Beep( m_Octave*261.63, pressDuration ); //C4 - DO
        break;
    case 'd' :
        Beep( m_Octave*293.66, pressDuration ); //D4 - Ré
        break;
    case 'f' :
        Beep( m_Octave*329.63, pressDuration ); //E4 - Mi
        break;
    case 'g' :
        Beep( m_Octave*349.23, pressDuration ); //F4 - Fa
        break;
    case 'h' :
        Beep( m_Octave*392.00, pressDuration ); //G4 - Sol
        break;
    case 'j' :
        Beep( m_Octave*440.00, pressDuration ); //A4 - La*
        break;
    case 'k' :
        Beep( m_Octave*493.88, pressDuration ); //B4 - Si
        break;
    case 'l' :
        Beep( m_Octave*523.25, pressDuration ); //C5 - Do
        break;
    case 'e' :
        Beep( m_Octave*277.18, pressDuration ); //C4#
        break;
    case 'r' :
        Beep( m_Octave*311.13, pressDuration ); //D4#
        break;
    case 'y' :
        Beep( m_Octave*369.99, pressDuration ); //F4#
        break;
    case 'u' :
        Beep( m_Octave*415.30, pressDuration ); //G4#
        break;
    case 'i' :
        Beep( m_Octave*466.16, pressDuration ); //A4#
        break;
    case '9' :
        std::cout<<"\nPress duration is set to 250 by default. Enter the new value: "<<std::endl;
        std::cin>>pressDuration;
        break;
    case 'x' :
        Beep( 0, pressDuration ); //silence
        break;
    case '0':
        std::cout<<"Goodbye !";
        exit (0);
        break;
    }
}




