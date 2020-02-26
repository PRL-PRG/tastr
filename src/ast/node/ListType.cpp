#include "ast/node/ListType.h"

#include "ast/visitor/Visitor.h"

void rtype::ast::node::ListType::accept(
    rtype::ast::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
