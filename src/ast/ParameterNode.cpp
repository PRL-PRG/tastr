#include "ast/ParameterNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::ParameterNode::accept(
    tastr::visitor::ConstNodeVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::ParameterNode::accept(
    tastr::visitor::MutableNodeVisitor& visitor) {
    visitor.visit(*this);
}

const tastr::ast::Node::Kind tastr::ast::ParameterNode::kind_ =
    tastr::ast::Node::Kind::Parameter;
