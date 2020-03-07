#include "ast/VectorTypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::VectorTypeNode::accept(
    tastr::visitor::ConstNodeVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::VectorTypeNode::accept(
    tastr::visitor::MutableNodeVisitor& visitor) {
    visitor.visit(*this);
}
