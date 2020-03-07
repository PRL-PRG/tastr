#include "ast/IntegerScalarTypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::IntegerScalarTypeNode::accept(
    tastr::visitor::ConstNodeVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::IntegerScalarTypeNode::accept(
    tastr::visitor::MutableNodeVisitor& visitor) {
    visitor.visit(*this);
}
