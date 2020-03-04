#include "ast/CharacterScalarTypeNode.hpp"

#include "visitor/Visitor.hpp"

void tastr::ast::CharacterScalarTypeNode::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
