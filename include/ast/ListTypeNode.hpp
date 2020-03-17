#ifndef TASTR_AST_LIST_TYPE_NODE_HPP
#define TASTR_AST_LIST_TYPE_NODE_HPP

#include "ast/Bracket.hpp"
#include "ast/TypeNode.hpp"

namespace tastr::ast {

class ListTypeNode final
    : public TypeNode
    , public Bracketed {
  public:
    explicit ListTypeNode(OperatorNodeUPtr opening_bracket,
                          OperatorNodeUPtr closing_bracket,
                          NodeUPtr elements)
        : TypeNode()
        , Bracketed(std::move(opening_bracket), std::move(closing_bracket))
        , elements_(std::move(elements)) {
    }

    ~ListTypeNode() = default;

    ListTypeNode(const ListTypeNode& node)
        : TypeNode(node), Bracketed(node), elements_(node.elements_->clone()) {
    }

    ListTypeNode(ListTypeNode&& node)
        : TypeNode(std::move(node))
        , Bracketed(std::move(node))
        , elements_(std::move(node.elements_)) {
    }

    ListTypeNode& operator=(const ListTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        Bracketed::operator=(node);
        elements_ = node.elements_->clone();
        return *this;
    }

    ListTypeNode& operator=(ListTypeNode&& node) {
        TypeNode::operator=(std::move(node));
        Bracketed::operator=(std::move(node));
        elements_ = std::move(node.elements_);
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    std::unique_ptr<ListTypeNode> clone() const {
        return std::unique_ptr<ListTypeNode>(this->clone_impl());
    }

    bool is_list_type_node() const override final {
        return true;
    }

    Node& get_elements() const {
        return *elements_.get();
    }

  private:
    virtual ListTypeNode* clone_impl() const override final {
        return new ListTypeNode(*this);
    };

    NodeUPtr elements_;
};

using ListTypeNodePtr = ListTypeNode*;
using ListTypeNodeUPtr = std::unique_ptr<ListTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_LIST_TYPE_NODE_HPP */
