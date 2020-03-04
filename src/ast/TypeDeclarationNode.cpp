#include "ast/TypeDeclarationNode.hpp"

#include "visitor/Visitor.hpp"

void tastr::ast::TypeDeclarationNode::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
