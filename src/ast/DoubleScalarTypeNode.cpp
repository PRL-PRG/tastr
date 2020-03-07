#include "ast/DoubleScalarTypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::DoubleScalarTypeNode::accept(
    tastr::visitor::ConstNodeVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::DoubleScalarTypeNode::accept(
    tastr::visitor::MutableNodeVisitor& visitor) {
    visitor.visit(*this);
}
