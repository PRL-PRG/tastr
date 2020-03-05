#include "ast/ExpressionTypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::ExpressionTypeNode::accept(
    tastr::visitor::ConstVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::ExpressionTypeNode::accept(
    tastr::visitor::MutableVisitor& visitor) {
    visitor.visit(*this);
}
