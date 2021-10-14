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

    /// Load and parse a .ini file
    /// \param path Path where to load you .ini file
    /// \return 0 : success
    /// \return 1 : in case of read error
    /// \return 255 : in case of generic error
    unsigned short load_resource(const std::string& path);

    /// Return value of a given key from the previous loaded file
    /// \param key Key to load
    /// \return
    /// \return 0 : success
    /// \return 3 : file not loaded yet
    /// \return 4 : key not valid
    /// \return 255 : in case of generic error
    unsigned short get_value(const std::string& key);

    /// Set the value of a give key to the previous loaded file
    /// \param key Key to be modified
    /// \param value New value
    /// \return
    /// \return 0 : success
    /// \return 3 : file not loaded yet
    /// \return 255 : in case of generic error
    unsigned short set_value(const std::string& key, const std::string& value);

public:
    std::string value;

private:
    boost::property_tree::ptree parsed_rs;
};

#endif //EGLUE_LIB_LIBRARY_H
