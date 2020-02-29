#include "ast/node/LogicalType.h"

#include "ast/visitor/Visitor.h"

void tastr::ast::node::LogicalType::accept(
    tastr::ast::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
