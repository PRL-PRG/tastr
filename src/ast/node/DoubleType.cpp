#include "ast/node/DoubleType.h"

#include "ast/visitor/Visitor.h"

void rtype::ast::node::DoubleType::accept(
    rtype::ast::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
