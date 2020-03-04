#include "ast/UnionTypeNode.hpp"

#include "visitor/Visitor.hpp"

void tastr::ast::UnionTypeNode::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
