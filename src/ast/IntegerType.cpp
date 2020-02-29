#include "ast/IntegerType.h"

#include "visitor/Visitor.h"

void tastr::ast::IntegerType::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
