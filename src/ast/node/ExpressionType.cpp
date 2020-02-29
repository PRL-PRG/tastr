#include "ast/node/ExpressionType.h"
#include "ast/visitor/Visitor.h"

void tastr::ast::node::ExpressionType::accept(
    tastr::ast::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
