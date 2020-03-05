#include "ast/IdentifierNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::IdentifierNode::accept(
    tastr::visitor::ConstVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::IdentifierNode::accept(
    tastr::visitor::MutableVisitor& visitor) {
    visitor.visit(*this);
}
