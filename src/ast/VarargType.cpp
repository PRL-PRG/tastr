#include "ast/VarargType.h"

#include "visitor/Visitor.h"

void tastr::ast::VarargType::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
