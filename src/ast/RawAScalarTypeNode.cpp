#include "ast/RawAScalarTypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::RawAScalarTypeNode::accept(
    tastr::visitor::ConstNodeVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::RawAScalarTypeNode::accept(
    tastr::visitor::MutableNodeVisitor& visitor) {
    visitor.visit(*this);
}
