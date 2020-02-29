#include "ast/ParameterType.h"

#include "visitor/Visitor.h"

void tastr::ast::ParameterType::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
