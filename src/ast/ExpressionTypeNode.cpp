#include "ast/ExpressionTypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::ExpressionTypeNode::accept(
    tastr::visitor::ConstNodeVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::ExpressionTypeNode::accept(
    tastr::visitor::MutableNodeVisitor& visitor) {
    visitor.visit(*this);
}
