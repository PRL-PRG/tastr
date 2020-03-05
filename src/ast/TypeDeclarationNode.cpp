#include "ast/TypeDeclarationNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::TypeDeclarationNode::accept(
    tastr::visitor::ConstVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::TypeDeclarationNode::accept(
    tastr::visitor::MutableVisitor& visitor) {
    visitor.visit(*this);
}
