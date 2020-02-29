#include "ast/Identifier.h"

#include "visitor/Visitor.h"

void tastr::ast::Identifier::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
