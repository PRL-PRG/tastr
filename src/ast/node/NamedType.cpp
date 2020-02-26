#include "ast/node/NamedType.h"

#include "ast/visitor/Visitor.h"

void rtype::ast::node::NamedType::accept(
    rtype::ast::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
