#include "ast/DoubleAScalarTypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::DoubleAScalarTypeNode::accept(
    tastr::visitor::ConstNodeVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::DoubleAScalarTypeNode::accept(
    tastr::visitor::MutableNodeVisitor& visitor) {
    visitor.visit(*this);
}
