#include "utilities.h"

#include "ast/visitor/TypeSerializer.h"

#include <sstream>
#include <string>

std::ostream& operator<<(std::ostream& os, const rtype::ast::node::Type& type) {
    rtype::ast::visitor::TypeSerializer(os).visit(type);
    return os;
}

std::string to_string(const rtype::ast::node::Type& type) {
    std::stringstream stream;
    stream << type;
    return stream.str();
}
