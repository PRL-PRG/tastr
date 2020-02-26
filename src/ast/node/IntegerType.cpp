#include "ast/node/IntegerType.h"

#include "ast/visitor/Visitor.h"

void rtype::ast::node::IntegerType::accept(
    rtype::ast::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
