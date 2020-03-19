#ifndef TASTR_AST_EMPTY_NODE_HPP
#define TASTR_AST_EMPTY_NODE_HPP

#include "ast/Node.hpp"

#include <string>

namespace tastr::ast {

class EmptyNode final: public Node {
  public:
    EmptyNode(): Node() {
    }

    ~EmptyNode() = default;

    EmptyNode(const EmptyNode& node): Node(node) {
    }

    EmptyNode(EmptyNode&& node): Node(std::move(node)) {
    }

    EmptyNode& operator=(const EmptyNode& node) {
        if (&node == this) {
            return *this;
        }
        Node::operator=(node);
        return *this;
    }

    EmptyNode& operator=(EmptyNode&& node) {
        Node::operator=(std::move(node));
        return *this;
    }

    std::unique_ptr<EmptyNode> clone() const {
        return std::unique_ptr<EmptyNode>(this->clone_impl());
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    Kind get_kind() const override final {
        return kind_;
    }
    
  private:
    virtual EmptyNode* clone_impl() const override final {
        return new EmptyNode(*this);
    }

    static const Kind kind_;
};

using EmptyNodePtr = EmptyNode*;
using EmptyNodeUPtr = std::unique_ptr<EmptyNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_EMPTY_NODE_HPP */
