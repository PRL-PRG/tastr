#include "ast/node/GroupType.h"

#include "ast/visitor/Visitor.h"

void tastr::ast::node::GroupType::accept(
    tastr::ast::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
