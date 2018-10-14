#ifndef PIANOAPPEXCEPTION_H
#define PIANOAPPEXCEPTION_H
#include <exception>
#include <string>

//template class which allows to create exceptions using strings or int or any other type we want
template <typename T>
class PianoAppException: public std::exception
{
public:
    PianoAppException(const T &error): errorMessage(error) {}
    ~PianoAppException() throw () {}

    T GetError() const
    {
        return errorMessage;
    }
    void SetError(const T &error)
    {
        errorMessage = error;
    }
private:
    T errorMessage;
};
#endif // PIANOAPPEXCEPTION_H
