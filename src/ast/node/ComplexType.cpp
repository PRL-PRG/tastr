#include "ast/node/ComplexType.h"

#include "ast/visitor/TypeVisitor.h"

void rtype::ast::node::ComplexType::accept(
    rtype::ast::visitor::TypeVisitor& visitor) const {
    visitor.visit(*this);
}
