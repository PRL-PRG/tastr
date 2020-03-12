#include "ast/UnknownTypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::UnknownTypeNode::accept(
    tastr::visitor::ConstNodeVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::UnknownTypeNode::accept(
    tastr::visitor::MutableNodeVisitor& visitor) {
    visitor.visit(*this);
}
