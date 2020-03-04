#include "ast/ExternalPointerTypeNode.hpp"

#include "visitor/Visitor.hpp"

void tastr::ast::ExternalPointerTypeNode::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
