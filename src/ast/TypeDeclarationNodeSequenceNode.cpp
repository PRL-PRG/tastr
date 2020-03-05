#include "ast/TypeDeclarationNodeSequenceNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::TypeDeclarationNodeSequenceNode::accept(
    tastr::visitor::ConstVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::TypeDeclarationNodeSequenceNode::accept(
    tastr::visitor::MutableVisitor& visitor) {
    visitor.visit(*this);
}
