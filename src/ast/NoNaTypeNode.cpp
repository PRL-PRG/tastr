#include "ast/NoNaTypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::NoNaTypeNode::accept(
    tastr::visitor::ConstNodeVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::NoNaTypeNode::accept(
    tastr::visitor::MutableNodeVisitor& visitor) {
    visitor.visit(*this);
}
