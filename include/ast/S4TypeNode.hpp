#ifndef TASTR_AST_S4_TYPE_NODE_HPP
#define TASTR_AST_S4_TYPE_NODE_HPP

#include "ast/Name.hpp"
#include "ast/TypeNode.hpp"

namespace tastr::ast {

class S4TypeNode final
    : public TypeNode
    , public Name {
  public:
    explicit S4TypeNode(const std::string& name): TypeNode(), Name(name) {
    }

    ~S4TypeNode() = default;

    S4TypeNode(const S4TypeNode& node): TypeNode(node), Name(node) {
    }

    S4TypeNode(S4TypeNode&& node)
        : TypeNode(std::move(node)), Name(std::move(node)) {
    }

    S4TypeNode& operator=(const S4TypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        Name::operator=(node);
        return *this;
    }

    S4TypeNode& operator=(S4TypeNode&& node) {
        TypeNode::operator=(std::move(node));
        Name::operator=(std::move(node));
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    std::unique_ptr<S4TypeNode> clone() const {
        return std::unique_ptr<S4TypeNode>(this->clone_impl());
    }

    bool is_s4_type_node() const override final {
        return true;
    }

  private:
    virtual S4TypeNode* clone_impl() const override final {
        return new S4TypeNode(*this);
    };
};

using S4TypeNodePtr = S4TypeNode*;
using S4TypeNodeUPtr = std::unique_ptr<S4TypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_S4_TYPE_NODE_HPP */
