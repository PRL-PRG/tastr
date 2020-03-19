#include "ast/EnvironmentTypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::EnvironmentTypeNode::accept(
    tastr::visitor::ConstNodeVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::EnvironmentTypeNode::accept(
    tastr::visitor::MutableNodeVisitor& visitor) {
    visitor.visit(*this);
}

const tastr::ast::Node::Kind tastr::ast::EnvironmentTypeNode::kind_ =
    tastr::ast::Node::Kind::EnvironmentType;
