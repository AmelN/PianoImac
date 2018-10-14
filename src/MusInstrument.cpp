#include <string>
#include <conio.h>
#include "../inc/MusInstrument.h"

//Constructor
MusInstrument::MusInstrument()
{
    m_saveModeOn=0;
    m_loadModeOn=0;
    m_Octave=1;
    m_twiceS=0;
}
//Destructor
MusInstrument::~MusInstrument()
{
    //dtor
}

//Method to handle key press for save/ load/ octave up and down
void MusInstrument::HandleKey(char keyPressed)
{

    switch(keyPressed)
    {
    case '+' :
        if(m_Octave < 16)
        {
            m_Octave=m_Octave*2;
            std::cout << "Octave UP" <<m_Octave <<std::endl;
        }
        break;
    case '-' :
        if(m_Octave> 0.0625)  //0.0625 =1/16
        {
            m_Octave=m_Octave/2;
            std::cout << "Octave DOWN"<<m_Octave <<std::endl;
        }
        break;
    case '5' :
        m_twiceS++;
        if(m_twiceS % 2 !=0)
        {
            m_saveModeOn=1;
            std::cout <<"save mode on ! "<< std::endl;
            savedNotes.erase (savedNotes.begin(),savedNotes.end());
            savedOctaves.erase (savedOctaves.begin(),savedOctaves.end());
        }
        else
        {
            m_saveModeOn=0;
            try
            {
                Save();
            }
            catch(const FileException &error)
            {
                std::cerr << error.GetError() <<std::endl;
            }
        }
        break;
    case '8' :
        try
        {
            Load();
            m_loadModeOn=1;
        }
        catch(const FileException &error)
        {
            std::cerr << error.GetError() <<std::endl;
        }
        break;
    }
}

//Method to count the occurrence of a note using lambda expression
int countNote(std::vector<char> savedNotes, char note)
{
    return std::count_if(savedNotes.begin(), savedNotes.end(), [note] (char n)
    {
        return n == note;
    });
}

//Method that asks user if he wants to know occurrence and existence of a note on a loaded song
void MusInstrument::Ask()
{
    int option,stay=1;
    char note;
    do
    {
        std::cout<<"\n [1]Do you want to know whether a note appears in the song? \n [2]Do you want to know how many times a note appears ? \n [3] move on! "<<std::endl;
        std::cin>> option;
        switch(option)
        {
        case 1:
        {
            std::cout <<"Which note?" << std::endl;
            std::cin>> note;
            std::vector<char>::iterator appearence = std::find(savedNotes.begin(), savedNotes.end(), note); //the use of std::find algorithm
            if(appearence != savedNotes.end())
                std::cout << "The song contains " << note <<std::endl;
            else
                std::cout << "The song does not contain " << note <<std::endl;
            break;
        }

        case 2 :
        {
            std::cout <<"Which note?" << std::endl;
            std::cin>> note;
            int occ = countNote(savedNotes,note);
            std::cout <<"The song contains the "<<note<<" note " << occ <<" times."<<std::endl;
            break;
        }
        case 3 :
            stay=0;
            std::cout<< "You can carry on playing ! :) \n";
            break;
        default:
            break;
        }
    }
    while(stay==1);
}



//Method to save a song on a file
void MusInstrument::Save()
{
    std::cout << "\nGive a name to the record " <<std::endl;
    std::cin >>m_songName;
    std::string path = "Users\\"+ m_pseudo+"\\"+m_songName+".txt";
    //std::cout << path <<std::endl;
    std::ofstream songFile (path.c_str(),std::ios_base::app);

    savedNotes.erase (savedNotes.begin());
    savedOctaves.erase (savedOctaves.begin());
    if (songFile.is_open())
    {

        for(unsigned int i=0; i<savedNotes.size(); i++)
        {
            songFile << savedNotes[i];
        }

        songFile << "\n";

        for(unsigned int i=0; i<savedOctaves.size(); i++)
        {
            songFile << savedOctaves[i];
        }

        songFile.close();

    }
    else throw FileException(path);

    std::cout << "Save done ! " <<std::endl;


}

//Method to load a song from a file
void MusInstrument::Load()
{
    std::cout << "\nGive the name of the record you want to load " <<std::endl;
    std::cin >>m_songName;
    std::string path = "Users\\"+m_pseudo+"\\"+m_songName+".txt";
    //std::cout << path <<std::endl;
    std::ifstream songFile (path.c_str());

    savedNotes.erase (savedNotes.begin(),savedNotes.end());
    savedOctaves.erase (savedOctaves.begin(),savedOctaves.end());

    if (songFile.good())
    {
        std::string sLine;
        char note;
        float octave;
        int nblign=0;
        while(getline(songFile, sLine))
        {
            nblign++;
            //std::cout << sLine << std::endl;
            if(nblign==1)
            {
                for(unsigned int i=1; i<sLine.size(); i++)
                {
                    note=sLine[i];
                    savedNotes.push_back(note);
                }
            }
            else if (nblign==2)
            {

                for(unsigned int i=1; i<sLine.size(); i++)
                {
                    note=sLine[i];
                    octave=(float)(note - '0');
                    savedOctaves.push_back(octave);
                }
            }
        }
    }
    else throw FileException(path);

    songFile.close();
}

//Method of the main loop to detect pressed key and uses vector to add notes on save mode and load notes on load mode
void MusInstrument::MainLoop()
{
    std::string songName;
    char keyPressed;
    while(1)
    {
        keyPressed= getch(); //getch(): allows to get pressed key without pressing enter
        //std::cout << keyPressed;
        //std::cout << m_Octave;
        HandleKey(keyPressed);
        (*this) << keyPressed;
        if(m_saveModeOn)
        {
            savedNotes.push_back(keyPressed);
            savedOctaves.push_back(m_Octave);
        }
        if(m_loadModeOn)
        {
            m_loadModeOn=0;
            for(unsigned int i=0; i<savedNotes.size(); i++)
            {
                (*this) <<savedNotes[i];
                m_Octave=savedOctaves[i];
            }
            Ask();
        }

    }
}

