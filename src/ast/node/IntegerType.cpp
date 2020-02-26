#include "ast/node/IntegerType.h"

#include "ast/visitor/TypeVisitor.h"

void rtype::ast::node::IntegerType::accept(
    rtype::ast::visitor::TypeVisitor& visitor) const {
    visitor.visit(*this);
}
