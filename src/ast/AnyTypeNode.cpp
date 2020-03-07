#include "ast/AnyTypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::AnyTypeNode::accept(
    tastr::visitor::ConstNodeVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::AnyTypeNode::accept(
    tastr::visitor::MutableNodeVisitor& visitor) {
    visitor.visit(*this);
}
