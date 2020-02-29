#include "ast/ExpressionType.h"
#include "visitor/Visitor.h"

void tastr::ast::ExpressionType::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
