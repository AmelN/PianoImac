#ifndef FOLDEREXCEPTION_H
#define FOLDEREXCEPTION_H
#include "PianoAppException.h"


class FolderException : public PianoAppException<std::string>
{
public:
    FolderException(const std::string& foldername);
};

#endif // FILEEXCEPTION_H
