#include "ast/node/TypeDeclaration.h"

#include "ast/visitor/Visitor.h"

void rtype::ast::node::TypeDeclaration::accept(
    rtype::ast::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
