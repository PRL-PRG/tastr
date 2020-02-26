#include "ast.h"

#include "ast/visitor/Unparser.h"

#include <sstream>

std::ostream& operator<<(std::ostream& os, const rtype::ast::node::Node& node) {
    rtype::ast::visitor::Unparser(os).visit(node);
    return os;
}

std::string to_string(const rtype::ast::node::Node& node) {
    std::stringstream stream;
    stream << node;
    return stream.str();
}
