#include "ast/GroupType.h"

#include "visitor/Visitor.h"

void tastr::ast::GroupType::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
