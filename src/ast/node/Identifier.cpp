#include "ast/node/Identifier.h"

#include "ast/visitor/Visitor.h"

void tastr::ast::node::Identifier::accept(
    tastr::ast::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
