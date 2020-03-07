#include "ast/IdentifierNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::IdentifierNode::accept(
    tastr::visitor::ConstNodeVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::IdentifierNode::accept(
    tastr::visitor::MutableNodeVisitor& visitor) {
    visitor.visit(*this);
}
