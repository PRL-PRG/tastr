#include "ast/node/TypeDeclaration.h"

#include "ast/visitor/TypeVisitor.h"

void rtype::ast::node::TypeDeclaration::accept(
    rtype::ast::visitor::TypeVisitor& visitor) const {
    visitor.visit(*this);
}
