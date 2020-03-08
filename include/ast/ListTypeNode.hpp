#ifndef TASTR_AST_LIST_TYPE_NODE_HPP
#define TASTR_AST_LIST_TYPE_NODE_HPP

#include "ast/Bracket.hpp"
#include "ast/TypeNode.hpp"
#include "ast/TypeNodeSequenceNode.hpp"

namespace tastr::ast {

class ListTypeNode final
    : public TypeNode
    , public Bracketed {
  public:
    explicit ListTypeNode(const std::string& opening_bracket,
                          const std::string& closing_bracket,
                          TypeNodeSequenceNodeUPtr element_types)
        : TypeNode()
        , Bracketed(opening_bracket, closing_bracket)
        , element_types_(std::move(element_types)) {
    }

    ~ListTypeNode() = default;

    ListTypeNode(const ListTypeNode& node)
        : TypeNode(node)
        , Bracketed(node)
        , element_types_(node.element_types_->clone()) {
    }

    ListTypeNode(ListTypeNode&& node)
        : TypeNode(std::move(node))
        , Bracketed(std::move(node))
        , element_types_(std::move(node.element_types_)) {
    }

    ListTypeNode& operator=(const ListTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        Bracketed::operator=(node);
        element_types_ = node.element_types_->clone();
        return *this;
    }

    ListTypeNode& operator=(ListTypeNode&& node) {
        TypeNode::operator=(std::move(node));
        Bracketed::operator=(std::move(node));
        element_types_ = std::move(node.element_types_);
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

    TypeNodeSequenceNode& get_element_types() const {
        return *element_types_.get();
    }

  private:
    virtual ListTypeNode* clone_impl() const override final {
        return new ListTypeNode(*this);
    };

    TypeNodeSequenceNodeUPtr element_types_;
};

using ListTypeNodePtr = ListTypeNode*;
using ListTypeNodeUPtr = std::unique_ptr<ListTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_LIST_TYPE_NODE_HPP */
