#include "ast/DoubleType.h"

#include "visitor/Visitor.h"

void tastr::ast::DoubleType::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
