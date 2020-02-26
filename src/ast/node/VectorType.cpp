#include "ast/node/VectorType.h"

#include "ast/visitor/TypeVisitor.h"

void rtype::ast::node::VectorType::accept(
    rtype::ast::visitor::TypeVisitor& visitor) const {
    visitor.visit(*this);
}
