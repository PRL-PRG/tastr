#include "ast/StructTypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::StructTypeNode::accept(
    tastr::visitor::ConstNodeVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::StructTypeNode::accept(
    tastr::visitor::MutableNodeVisitor& visitor) {
    visitor.visit(*this);
}
