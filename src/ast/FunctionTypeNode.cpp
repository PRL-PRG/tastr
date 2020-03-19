#include "ast/FunctionTypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::FunctionTypeNode::accept(
    tastr::visitor::ConstNodeVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::FunctionTypeNode::accept(
    tastr::visitor::MutableNodeVisitor& visitor) {
    visitor.visit(*this);
}

const tastr::ast::Node::Kind tastr::ast::FunctionTypeNode::kind_ =
    tastr::ast::Node::Kind::FunctionType;
