#include "ast/FunctionType.h"

#include "visitor/Visitor.h"

void tastr::ast::FunctionType::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
