#include "ast/EnvironmentTypeNode.hpp"
#include "visitor/Visitor.hpp"

void tastr::ast::EnvironmentTypeNode::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
