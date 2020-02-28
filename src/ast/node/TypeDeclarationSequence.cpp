#include "ast/node/TypeDeclarationSequence.h"

#include "ast/visitor/Visitor.h"

void rtype::ast::node::TypeDeclarationSequence::accept(
    rtype::ast::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
