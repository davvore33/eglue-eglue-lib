#ifndef EGLUE_LIB_LIBRARY_H
#define EGLUE_LIB_LIBRARY_H

#include <iostream>
#define TRUE true

#ifdef BOOSTFOUND
bool boostfound = BOOSTFOUND; // https://www.boost.org/doc/libs/1_77_0/more/getting_started/unix-variants.html#get-boost
#endif

class Loader {
public:
    Loader() {};
    ~Loader() {};

    unsigned short load_resource(const std::string& path);
    unsigned short get_value(const std::string& key);
    unsigned short set_value(const std::string& key, const std::string& value);
};

#endif //EGLUE_LIB_LIBRARY_H
