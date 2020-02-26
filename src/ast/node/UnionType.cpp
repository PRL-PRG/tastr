#include "ast/node/UnionType.h"

#include "ast/visitor/TypeVisitor.h"

void rtype::ast::node::UnionType::accept(
    rtype::ast::visitor::TypeVisitor& visitor) const {
    visitor.visit(*this);
}
