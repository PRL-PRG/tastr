#include "ast/NoNaType.h"

#include "visitor/Visitor.h"

void tastr::ast::NoNaType::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
