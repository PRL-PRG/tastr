#include "ast/node/ComplexType.h"

#include "ast/visitor/Visitor.h"

void rtype::ast::node::ComplexType::accept(
    rtype::ast::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
