#include "ast/NullableTypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::NullableTypeNode::accept(
    tastr::visitor::ConstNodeVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::NullableTypeNode::accept(
    tastr::visitor::MutableNodeVisitor& visitor) {
    visitor.visit(*this);
}

const tastr::ast::Node::Kind tastr::ast::NullableTypeNode::kind_ =
    tastr::ast::Node::Kind::NullableType;
