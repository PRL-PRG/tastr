#include "ast/node/VarargType.h"

#include "ast/visitor/Visitor.h"

void rtype::ast::node::VarargType::accept(
    rtype::ast::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
