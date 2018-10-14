#include "../inc/FileException.h"

FileException::FileException(const std::string &filename)
    : PianoAppException("Unable to open file " + filename)
{

}
