#include "ast/VarargTypeNode.hpp"

#include "visitor/Visitor.hpp"

void tastr::ast::VarargTypeNode::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
