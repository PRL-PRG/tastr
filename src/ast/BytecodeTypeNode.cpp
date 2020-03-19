#include "ast/BytecodeTypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::BytecodeTypeNode::accept(
    tastr::visitor::ConstNodeVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::BytecodeTypeNode::accept(
    tastr::visitor::MutableNodeVisitor& visitor) {
    visitor.visit(*this);
}

const tastr::ast::Node::Kind tastr::ast::BytecodeTypeNode::kind_ =
    tastr::ast::Node::Kind::BytecodeType;
