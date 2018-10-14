#ifndef KEY_H
#define KEY_H
#include <windows.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include "FileException.h"

//Musical instrument class from which the different instruments derive
class MusInstrument
{
public:
    MusInstrument();
    virtual ~MusInstrument();


//getters
    std::string Getpseudo() const
    {
        return m_pseudo;
    }
    std::string GetsongName() const
    {
        return m_songName;
    }
    unsigned int GetsaveModeOn() const
    {
        return m_saveModeOn;
    }
    unsigned int GetsaveOctave() const
    {
        return m_Octave;
    }
//setters
    void Setpseudo(const std::string val)
    {
        m_pseudo = val;
    }
    void SetsongName(const std::string val)
    {
        m_songName = val;
    }
    void SetsaveModeOn(const unsigned int val)
    {
        m_saveModeOn = val;
    }
    void SetsaveOctave(const unsigned int val)
    {
        m_Octave = val;
    }

//methods
    virtual void operator <<(char keyPressed) = 0;
    void HandleKey(char keyPressed);
    void MainLoop();
    void Save();
    void Load();
    void Ask();

private:
    std::vector<char> savedNotes;
    std::vector<int> savedOctaves;
    std::string m_songName;
    std::string m_pseudo;
    unsigned int m_saveModeOn;
    unsigned int m_loadModeOn;
    int m_twiceS;
protected:
    float m_Octave;

};

#endif // KEY_H
