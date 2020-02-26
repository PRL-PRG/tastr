#ifndef R_TYPE_UTILITIES_H
#define R_TYPE_UTILITIES_H

#include "ast/node/Type.h"

std::ostream& operator<<(std::ostream& os, const rtype::ast::node::Type& type);

std::string to_string(const rtype::ast::node::Type& type);

#endif /* R_TYPE_UTILITIES_H */
