#include "ast/TypeDeclarationNodeSequenceNode.hpp"

#include "visitor/Visitor.hpp"

void tastr::ast::TypeDeclarationNodeSequenceNode::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
