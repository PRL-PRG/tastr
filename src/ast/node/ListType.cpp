#include "ast/node/ListType.h"

#include "ast/visitor/TypeVisitor.h"

void rtype::ast::node::ListType::accept(
    rtype::ast::visitor::TypeVisitor& visitor) const {
    visitor.visit(*this);
}
