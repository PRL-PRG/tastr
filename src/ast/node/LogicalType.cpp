#include "ast/node/LogicalType.h"

#include "ast/visitor/Visitor.h"

void rtype::ast::node::LogicalType::accept(
    rtype::ast::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
