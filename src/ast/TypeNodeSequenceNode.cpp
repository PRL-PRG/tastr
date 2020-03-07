#include "ast/TypeNodeSequenceNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::TypeNodeSequenceNode::accept(
    tastr::visitor::ConstNodeVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::TypeNodeSequenceNode::accept(
    tastr::visitor::MutableNodeVisitor& visitor) {
    visitor.visit(*this);
}
