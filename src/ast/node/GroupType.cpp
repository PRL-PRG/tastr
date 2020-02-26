#include "ast/node/GroupType.h"

#include "ast/visitor/Visitor.h"

void rtype::ast::node::GroupType::accept(
    rtype::ast::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
