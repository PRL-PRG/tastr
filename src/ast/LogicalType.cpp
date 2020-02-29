#include "ast/LogicalType.h"

#include "visitor/Visitor.h"

void tastr::ast::LogicalType::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
