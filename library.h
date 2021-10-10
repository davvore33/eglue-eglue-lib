#ifndef EGLUE_LIB_LIBRARY_H
#define EGLUE_LIB_LIBRARY_H

#include <iostream>
#define TRUE true
#if BOOSTFOUND // https://www.boost.org/doc/libs/1_77_0/more/getting_started/unix-variants.html#get-boost
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>
#endif
//TODO implement a parser if you don't have boost


class Loader {
    enum errors_type {
        OK = 0,
        READERR = 1,
        BADKEY = 3,
        FILENOTREADY = 4,
        GENERICERROR = 255
    };
public:
    Loader() {};
    ~Loader() {};

    unsigned short load_resource(const std::string& path);
    unsigned short get_value(const std::string& key);
    unsigned short set_value(const std::string& key, const std::string& value);

private:
    boost::property_tree::ptree parsed_rs;
    void print_err(const std::exception& e, const char *message);
};

#endif //EGLUE_LIB_LIBRARY_H
