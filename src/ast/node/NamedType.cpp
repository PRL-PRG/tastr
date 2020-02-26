#include "ast/node/NamedType.h"

#include "ast/visitor/TypeVisitor.h"

void rtype::ast::node::NamedType::accept(
    rtype::ast::visitor::TypeVisitor& visitor) const {
    visitor.visit(*this);
}
