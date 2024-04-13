#include "memory.hpp"

using namespace std;

int Memory::cast_int(const unique_ptr<variable_t>& var) {
    if (var->type != Type::Int) {
        throw runtime_error("Cannot cast variable to int");
    }
    return get<int>(var->value);
}

float Memory::cast_float(const unique_ptr<variable_t>& var) {
    if (var->type != Type::Float) {
        throw runtime_error("Cannot cast variable to double");
    }
    return get<float>(var->value);
}

string Memory::cast_string(const unique_ptr<variable_t>& var) {
    if (var->type != Type::String) {
        throw runtime_error("Cannot cast variable to string");
    }
    return get<string>(var->value);
}

bool Memory::cast_boolean(const unique_ptr<variable_t>& var) {
    if (var->type != Type::Boolean) {
        throw runtime_error("Cannot cast variable to bool");
    }
    return get<bool>(var->value);
}

void Memory::set_variable(const string& name, const variable_t& value) {
    this->variables[name] = value;
}

unique_ptr<variable_t> Memory::get_variable(const string& name) {
    if (this->variables.find(name) != this->variables.end()) {
        return make_unique<variable_t>(this->variables[name]);
    }
    return nullptr;
}

void Memory::add_function(const string& name, const function_t& func) {
    if (this->functions.find(name) != this->functions.end()) {
        throw runtime_error("Function already exists");
    }
    this->functions[name] = func;
}
