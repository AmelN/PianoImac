#ifndef FILEEXCEPTION_H
#define FILEEXCEPTION_H
#include "PianoAppException.h"

class FileException : public PianoAppException<std::string>
{
public:
    FileException(const std::string& filename);
};

#endif // FILEEXCEPTION_H
