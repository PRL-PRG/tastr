#include "ast/UnionTypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::UnionTypeNode::accept(
    tastr::visitor::ConstNodeVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::UnionTypeNode::accept(
    tastr::visitor::MutableNodeVisitor& visitor) {
    visitor.visit(*this);
}

const tastr::ast::Node::Kind tastr::ast::UnionTypeNode::kind_ =
    tastr::ast::Node::Kind::UnionType;
