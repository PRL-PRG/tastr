#include "ast/node/UnionType.h"

#include "ast/visitor/Visitor.h"

void rtype::ast::node::UnionType::accept(
    rtype::ast::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
