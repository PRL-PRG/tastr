#include "ast/ListTypeNode.hpp"

#include "visitor/Visitor.hpp"

void tastr::ast::ListTypeNode::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
