#include "ast/ListType.h"

#include "visitor/Visitor.h"

void tastr::ast::ListType::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
