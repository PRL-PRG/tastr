#include "ast/node/ExpressionType.h"
#include "ast/visitor/Visitor.h"

void rtype::ast::node::ExpressionType::accept(
    rtype::ast::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
