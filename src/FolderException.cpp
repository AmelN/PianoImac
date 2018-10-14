#include "../inc/FolderException.h"

FolderException::FolderException(const std::string &foldername)
    : PianoAppException("Unable to open folder " + foldername)
{

}
