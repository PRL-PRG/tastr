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
