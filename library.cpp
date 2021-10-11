#include "library.h"

unsigned short Loader::load_resource(const std::string &path) {
    try {
        boost::property_tree::ini_parser::read_ini(path, this->parsed_rs);
    } catch (boost::property_tree::ini_parser::ini_parser_error &e) {
        print_err(e, "read error");
        return Loader::errors_type::READERR;
    } catch (...) {
        return Loader::errors_type::GENERICERROR;
    }
    return Loader::errors_type::OK;
}

unsigned short Loader::get_value(const std::string &key) {
    if (this->parsed_rs.empty()) {
        return Loader::errors_type::FILENOTREADY;
    }
    try {
        const std::string &ret = this->parsed_rs.get<std::string>(key);

        value = ret;
    } catch (boost::property_tree::ptree_bad_path &e) {
        print_err(e, "bad key provided");
        return Loader::errors_type::BADKEY;
    } catch (...) {
        return Loader::errors_type::GENERICERROR;
    }
    return Loader::errors_type::OK;
}

unsigned short Loader::set_value(const std::string &key, const std::string &value) {
    if (this->parsed_rs.empty()) {
        return Loader::errors_type::FILENOTREADY;
    }
    try {
        this->parsed_rs.put<std::string>(key, value);
    } catch (...) {
        return Loader::errors_type::GENERICERROR;
    }
    return Loader::errors_type::OK;
}

void Loader::print_err(const std::exception &e, const char *message) {
    std::cerr << "[ERR: " << e.what() << "]: " << message << std::endl;
}
