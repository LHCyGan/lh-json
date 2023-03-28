#pragma once

#include <string>
using std::string;

#include <list>
#include <map>

namespace lh {
namespace json {
    
class Json {

public:
    // json数据类型
    enum  Type {
        json_null = 0,
        json_bool,
        json_int,
        json_double,
        json_string,
        json_array,
        json_object
    };

    Json();
    Json(Type type);
    Json(bool value);
    Json(int value);
    Json(double value);
    Json(const string& value);
    Json(const char* value);
    ~Json();

    Type type() const;

    bool isNull() const;
    bool isBool() const;
    bool isInt() const;
    bool isDouble() const;
    bool isString() const;
    bool isArray() const;
    bool isObject() const;

    bool asBool() const;
    int asInt() const;
    string asString() const;
    double asDouble() const;

    int size() const;

    bool empty() const;

    void clear();
    // 判断有无Key
    bool has(int index);
    bool has(const string& key);
    bool has(const char* key);
    // 移除Key
    void remove(int index);
    void remove(const char* key);
    void remove(const string& key);
    // 添加数据
    void append(const Json& value);

    Json& operator=(const Json& other);
    bool operator==(const Json& other);
    bool operator!=(const Json& other);

    Json& operator[](int index);
    Json& operator[](const char* key);
    Json& operator[](const string& key);

    // 提供隐式转换
    operator bool();
    operator int();
    operator double();
    operator string();

    void parse(const string& str);

    // 访问数组值类型
    typedef std::list<Json>::iterator iterator;
    iterator begin() {
        return (m_value.m_array)->begin();
    }

    iterator end() {
        return (m_value.m_array)->end();
    }

private:
    void copy(const Json& other);

private:
    // json值类型
    union Value {
        bool m_bool;
        int m_int;
        double m_double;
        std::string m_string;
        // 为了使数组中的类型可变，所以使用链表+Json
        std::list<Json> *m_array;
        std::map<string, Json> *m_object;
    };

    Type m_type;
    Value m_value;

};

}
}