#include "ast/ListTypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::ListTypeNode::accept(
    tastr::visitor::ConstNodeVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::ListTypeNode::accept(
    tastr::visitor::MutableNodeVisitor& visitor) {
    visitor.visit(*this);
}
