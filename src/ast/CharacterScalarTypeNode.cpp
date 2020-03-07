#include "ast/CharacterScalarTypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::CharacterScalarTypeNode::accept(
    tastr::visitor::ConstNodeVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::CharacterScalarTypeNode::accept(
    tastr::visitor::MutableNodeVisitor& visitor) {
    visitor.visit(*this);
}
