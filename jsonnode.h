#ifndef JSON_NODE_H
#define JSON_NODE_H

#include <string>
#include <map>
#include <vector>

namespace turtle_json {

enum NodeType { STRING, REAL, INTEGER, BOOLEAN, NIL, ARRAY, OBJECT };

class JsonNode {
public:
    ~JsonNode();
    std::map<std::string, JsonNode*> m_dict;
    std::vector<JsonNode*> m_array;

    std::string str;
    int integer;
    float real;
    bool boolean;

    NodeType type;

    // Helper functions to create Nodes
    static JsonNode* string_node(const char* str);
    static JsonNode* real_node(double real);
    static JsonNode* integer_node(int integer);
    static JsonNode* boolean_node(bool value);
    static JsonNode* null_node();
    static JsonNode* array_node();
    static JsonNode* object_node();
private:
    // Only allow creating through static members
    JsonNode() {}
    // No copy
    JsonNode(const JsonNode&);
    JsonNode& operator=(const JsonNode&);
};

} // END NAMESPACE turtle_json

#endif
