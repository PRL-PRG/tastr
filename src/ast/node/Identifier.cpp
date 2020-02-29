#include "ast/node/Identifier.h"

#include "ast/visitor/Visitor.h"

void rtype::ast::node::Identifier::accept(
    rtype::ast::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
