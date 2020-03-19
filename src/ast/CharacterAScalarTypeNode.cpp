#include "ast/CharacterAScalarTypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::CharacterAScalarTypeNode::accept(
    tastr::visitor::ConstNodeVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::CharacterAScalarTypeNode::accept(
    tastr::visitor::MutableNodeVisitor& visitor) {
    visitor.visit(*this);
}

const tastr::ast::Node::Kind tastr::ast::CharacterAScalarTypeNode::kind_ =
    tastr::ast::Node::Kind::CharacterAScalarType;
