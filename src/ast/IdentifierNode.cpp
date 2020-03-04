#include "ast/IdentifierNode.hpp"

#include "visitor/Visitor.hpp"

void tastr::ast::IdentifierNode::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
