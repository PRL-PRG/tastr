#include "ast/UnionTypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::UnionTypeNode::accept(
    tastr::visitor::ConstNodeVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::UnionTypeNode::accept(
    tastr::visitor::MutableNodeVisitor& visitor) {
    visitor.visit(*this);
}
