#include "ast/node/DoubleType.h"

#include "ast/visitor/TypeVisitor.h"

void rtype::ast::node::DoubleType::accept(
    rtype::ast::visitor::TypeVisitor& visitor) const {
    visitor.visit(*this);
}
