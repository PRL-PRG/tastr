#include "ast/TypeDeclarationNodeSequenceNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::TypeDeclarationNodeSequenceNode::accept(
    tastr::visitor::ConstNodeVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::TypeDeclarationNodeSequenceNode::accept(
    tastr::visitor::MutableNodeVisitor& visitor) {
    visitor.visit(*this);
}
