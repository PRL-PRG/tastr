#include "ast/node/VectorType.h"

#include "ast/visitor/Visitor.h"

void rtype::ast::node::VectorType::accept(
    rtype::ast::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
