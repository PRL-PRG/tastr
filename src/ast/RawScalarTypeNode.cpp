#include "ast/RawScalarTypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::RawScalarTypeNode::accept(
    tastr::visitor::ConstNodeVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::RawScalarTypeNode::accept(
    tastr::visitor::MutableNodeVisitor& visitor) {
    visitor.visit(*this);
}
