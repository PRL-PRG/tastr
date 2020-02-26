#include "ast/node/LogicalType.h"

#include "ast/visitor/TypeVisitor.h"

void rtype::ast::node::LogicalType::accept(
    rtype::ast::visitor::TypeVisitor& visitor) const {
    visitor.visit(*this);
}
