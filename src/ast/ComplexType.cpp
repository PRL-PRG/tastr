#include "ast/ComplexType.h"

#include "visitor/Visitor.h"

void tastr::ast::ComplexType::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
