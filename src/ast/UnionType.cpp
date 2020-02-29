#include "ast/UnionType.h"

#include "visitor/Visitor.h"

void tastr::ast::UnionType::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
