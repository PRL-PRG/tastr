#include "ast/ExternalPointerTypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::ExternalPointerTypeNode::accept(
    tastr::visitor::ConstNodeVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::ExternalPointerTypeNode::accept(
    tastr::visitor::MutableNodeVisitor& visitor) {
    visitor.visit(*this);
}

const tastr::ast::Node::Kind tastr::ast::ExternalPointerTypeNode::kind_ =
    tastr::ast::Node::Kind::ExternalPointerType;
