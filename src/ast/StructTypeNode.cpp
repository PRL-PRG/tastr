#include "ast/StructTypeNode.hpp"

#include "visitor/Visitor.hpp"

void tastr::ast::StructTypeNode::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
