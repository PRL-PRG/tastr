#include "ast/TypeDeclarationNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::TypeDeclarationNode::accept(
    tastr::visitor::ConstNodeVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::TypeDeclarationNode::accept(
    tastr::visitor::MutableNodeVisitor& visitor) {
    visitor.visit(*this);
}

const tastr::ast::Node::Kind tastr::ast::TypeDeclarationNode::kind_ =
    tastr::ast::Node::Kind::TypeDeclaration;
