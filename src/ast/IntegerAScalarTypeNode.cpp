#include "ast/IntegerAScalarTypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::IntegerAScalarTypeNode::accept(
    tastr::visitor::ConstNodeVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::IntegerAScalarTypeNode::accept(
    tastr::visitor::MutableNodeVisitor& visitor) {
    visitor.visit(*this);
}
