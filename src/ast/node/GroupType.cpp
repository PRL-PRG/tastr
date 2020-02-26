#include "ast/node/GroupType.h"

#include "ast/visitor/TypeVisitor.h"

void rtype::ast::node::GroupType::accept(
    rtype::ast::visitor::TypeVisitor& visitor) const {
    visitor.visit(*this);
}
