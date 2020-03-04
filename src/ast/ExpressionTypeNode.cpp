#include "ast/ExpressionTypeNode.hpp"
#include "visitor/Visitor.hpp"

void tastr::ast::ExpressionTypeNode::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
